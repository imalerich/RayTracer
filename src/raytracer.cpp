#define _USE_MATH_DEFINES
#include <math.h>
#include <thread>
#include <float.h>

#include "raytracer.h"

#include "surfaces/sphere.h"
#include "surfaces/plane.h"
#include "surfaces/aacube.h"

#include "lights/pointlight.h"
#include "lights/dirlight.h"
#include "lights/balllight.h"

using namespace std;

const static unsigned reflections = 0;

RayTracer::RayTracer(unsigned Screen_W, unsigned Screen_H) 
		: screen_w{Screen_W}, screen_h{Screen_H} { 
	// add some sample surfaces
	auto count = 2;
	auto i = 10;
	auto depth = 1;

	for (; i < 10 + depth * 3; i += 3) {
		for (auto x = 0; x < count; x++) {
			for (auto y = 0; y < count; y++) {
				auto x_coord = (x * 3.0 - 1.5 * count + 1.5);
				auto y_coord = (y * 3.0 - 1.5 * count + 1.5);
				surfaces.push_back(new Sphere(Material::rand_mat(), 
					Vector(x_coord, (double)i, y_coord), 1.0));
			}
		}
	}

	Material plane_mat(Vector(95/255, 91/255.0, 107/255.0), 0.0, 0.0, 0.0, 0.0);
	surfaces.push_back(new Plane(plane_mat, Vector(0.0, i - 2, 0.0), Vector(0.0, -1.0, 0.0)));
	
	lights.push_back(new PointLight(Vector(-3.0, 8.5, 0.0), 1.0, 30.0));
	//lights.push_back(new BallLight(Vector(-3.0, 8.5, 0.0), 0.5, 1.0, 30.0));
	//lights.push_back(new BallLight(Vector( 3.0, 8.5, 0.0), 1.0, 1.0, 30.0));
}

RayTracer::~RayTracer() {
	for (auto s : surfaces) {
		delete s;
	}

	for (auto l : lights) {
		delete l;
	}
}

float * RayTracer::render_scene() {
	Pixel * pixels = new Pixel[screen_w * screen_h];
	pixels_rendered = 0;

	#pragma omp parallel for
	for (auto y = 0u; y < screen_h; y++) {	
		for (auto x = 0u; x < screen_w; x++) {
			render_point(x, y, pixels);
		}
	}

	correct_exposure((float *)pixels, -1.0);
	encode_srgb((float *)pixels);
	return (float *)pixels;
}

void RayTracer::correct_exposure(float * pixels, float exposure) {
	for (auto i=0u; i < screen_h * screen_w * 3; i++) {
		auto &c = pixels[i];
		c = 1.0 - exp(c * exposure);
	}
}

void RayTracer::encode_srgb(float * pixels) {
	for (auto i=0u; i < screen_h * screen_w * 3; i++) {
		auto &c = pixels[i];
		if (c < 0.0031308) {
			c = 12.92 * c;
		} else {
			c = 1.055 * pow(c, 0.4166667) - 0.554;
		}
	}
}

void RayTracer::render_point(unsigned x, unsigned y, Pixel * pixels) {
	Camera cam(1.0, M_PI/2.0, (double)screen_w / (double)screen_h);

	// create the light ray for this pixel
	Vector start = cam.get_pos();
	Vector dir = cam.ray_for_coord(Vector(x, 0.0, y), Vector(screen_w, 0.0, screen_h));

	Vector c = color_for_ray(start, dir, reflections);
	pixels[y * screen_w + x] = { (float)c.x, (float)c.y, (float)c.z };

	pixels_rendered++;
}

Vector RayTracer::color_for_ray(Vector start, Vector dir, int limit) {
	Vector color;
	Vector norm;
	Vector intersect;

	auto dist = DBL_MAX;

	Surface * hit = nullptr;
	Vector hit_i, hit_n;

	// find the nearest surface
	for (auto s : surfaces) {

		if (s->intersects(start, dir, intersect, norm)) {
			// make sure this point is closer than the last renedered point
			if (intersect.magnitude() > dist) {
				continue;
			} else {
				// keep track of the surface we hit
				hit = s;
				hit_i = intersect;
				hit_n = norm;

				dist = intersect.magnitude();
			}
		}
	}

	// if no hit was made
	if (!hit) {
		return Vector(1.0, 1.0, 1.0);
	}

	// calculate the lighting for the hit surface
	auto l_val = 0.3;
	auto specular = 0.0;

	// loop through each contributing light
	for (auto l : lights) {
		auto num_samples = l->num_samples();

		// take l->num_samples() from each light
		for (auto sample = 0u; sample < num_samples; sample++) {
			Vector l_dir = l->direction_from_point(hit_i, 0);
			auto light = true;

			// check if a shadow hits this surface
			for (auto s : surfaces) {
				if (s->intersects(hit_i, l_dir)) {
					light = false;
					break;
				}
			}

			if (light) {
				hit_n.normalize();
				l_val += l->scalar_for_point(hit_i, hit_n, l_dir) / num_samples;

				// Phong
//				auto reflect = 2.0 * l_dir.dot(hit_n);
//				Vector p_dir = l_dir - hit_n * reflect;
//				p_dir.normalize();
//				auto phong = max(p_dir.dot(dir), 0.0);
//				specular += hit->mat.spec_scalar * pow(phong, hit->mat.spec_pow) / num_samples;

				// Blinn-Phong
				Vector b_dir = l_dir - dir;
				b_dir.normalize();
				auto blinn = max(hit_n.dot(b_dir), 0.0);
				specular += hit->mat.spec_scalar * pow(blinn, hit->mat.spec_pow) / num_samples;
			}
		}
	}

	l_val = min(l_val, 1.0);
	specular = max(specular * l_val, 0.0);

	color = (hit->mat.diffuse * l_val) + Vector(1.0, 1.0, 1.0) * specular;

	// recurse through reflection
	if (hit && hit->mat.reflect > 0.0000000001 && limit) {
		double reflect = 2.0 * dir.dot(hit_n);
		Vector r = color_for_ray(hit_i, dir - hit_n * reflect, limit - 1);
		return (r * hit->mat.reflect) + (color * (1.0 - hit->mat.reflect));
	}

	return color;
}
