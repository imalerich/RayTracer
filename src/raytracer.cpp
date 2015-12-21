#define _USE_MATH_DEFINES
#include <math.h>
#include <thread>
#include <float.h>

#include "raytracer.h"
#include "vector.h"

#include "surfaces/sphere.h"
#include "surfaces/plane.h"

#include "lights/pointlight.h"

using namespace std;

const static unsigned reflections = 3;

RayTracer::RayTracer(unsigned Screen_W, unsigned Screen_H) 
		: screen_w{Screen_W}, screen_h{Screen_H} { 
	// add some sample surfaces
	auto count = 3;
	auto i = 10;
	auto depth = 3;
	for (; i < 10 + depth * 2; i += 2) {
		for (auto x = 0; x < count; x++) {
			for (auto y = 0; y < count; y++) {
				auto x_coord = (x * 2.0 - count + 1);
				auto y_coord = (y * 2.0 - count + 1);
				surfaces.push_back(new Sphere(Vector(x_coord, (double)i, y_coord), 1.0));
			}
		}
	}

	for (auto s : surfaces) {
		s->diffuse = Vector((rand() % 1000) / 1000.0, (rand() % 1000) / 1000.0, (rand() % 1000) / 1000.0);
		s->reflection = (rand() % 800) / 1000.0;
	}

	// add some sample lights
	lights.push_back(new PointLight(Vector(-3.0, 8.5, 0.0), 1.0, 30.0));
	lights.push_back(new PointLight(Vector( 3.0, 8.5, 0.0), 1.0, 30.0));
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

	return (float *)pixels;
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
	auto drawn = false;

	Surface * hit = nullptr;
	Vector hit_i, hit_n;

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

			auto l_val = 0.2; // ambient

			for (auto l : lights) {
				Vector dir = l->direction_from_point(intersect);
				auto light = true;

				// check if a shadow hits this surface
				for (auto k : surfaces) {
					if (k->intersects(intersect, dir)) {
						light = false;
						break;
					}
				}

				if (light) {
					l_val += l->scalar_for_point(intersect, norm);
				}
			}

			auto specular = 0.0;
			for (auto l : lights) {
				Vector l_dir = l->direction_from_point(intersect);
				auto light = true;
				
				// check if this light is visible
				for (auto k : surfaces) {
					if (k->intersects(intersect, l_dir)) {
						light = false;
						break;
					}
				}

				if (light) {
					norm.normalize();

					auto reflect = 2.0 * l_dir.dot(norm);
					Vector p_dir = l_dir - norm * reflect;
					auto phong = max(p_dir.dot(dir), 0.0);
					specular += pow(phong, 32);
				}
			}

			l_val = min(l_val, 1.0);
			specular = max(specular, 1.0);

			color = (s->diffuse * l_val) * specular;
			drawn = true;

		} else if (!drawn) {
			color = Vector(1.0, 1.0, 1.0);
		}
	}

	if (hit && hit->reflection > 0.0 && limit) {
		double reflect = 2.0 * dir.dot(hit_n);
		Vector r = color_for_ray(hit_i, dir - hit_n * reflect, limit - 1);
		return (r * hit->reflection) + (color * (1.0 - hit->reflection));
	}

	return color;
}
