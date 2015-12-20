#define _USE_MATH_DEFINES
#include <math.h>
#include <thread>
#include <float.h>

#include "raytracer.h"
#include "vector.h"
#include "sphere.h"
#include "plane.h"

using namespace std;

RayTracer::RayTracer(unsigned Screen_W, unsigned Screen_H) 
		: screen_w{Screen_W}, screen_h{Screen_H} { 
	surfaces.push_back(new Sphere(Vector(0.0, 3.0, 0.0), 1.0));
	surfaces.push_back(new Sphere(Vector(-1.5, 4.0, 0.0), 0.6));
	surfaces.push_back(new Sphere(Vector(2.0, 5.0, -0.2), 0.8));
	surfaces.push_back(new Sphere(Vector(4.0, 8.0, 2.0), 1.2));
	surfaces.push_back(new Sphere(Vector(3.0, 13.0, 2.4), 1.5));

	surfaces.push_back(new Sphere(Vector(0.4, -2.0, 0.0), 1.4));
	surfaces.push_back(new Sphere(Vector(2.5, -3.0, 0.0), 2.0));
	surfaces.push_back(new Sphere(Vector(-2.0, -4.0, 0.5), 3.0));

	surfaces.push_back(new Plane(Vector(0.0, 0.0, -0.8), Vector(0.0, 0.0, 1.0)));

	for (auto s : surfaces) {
		s->diffuse = Vector((rand() % 1000) / 1000.0, (rand() % 1000) / 1000.0, (rand() % 1000) / 1000.0);
		s->reflection = (rand() % 250) / 1000.0;
		//s->reflection = 0.0;
	}
}

RayTracer::~RayTracer() {
	for (auto s : surfaces) {
		delete s;
	}
}

float * RayTracer::render_scene(Vector light) {
	Pixel * pixels = new Pixel[screen_w * screen_h];
	pixels_rendered = 0;

	for (auto y = 0u; y < screen_h; y++) {
		for (auto x = 0u; x < screen_w; x++) {
			render_point(x, y, pixels, light);
		}
	}

	return (float *)pixels;
}

void RayTracer::render_point(unsigned x, unsigned y, Pixel * pixels, Vector light) {
	Camera cam(1.0, M_PI/2.0, (double)screen_w / (double)screen_h);

	// create the light ray for this pixel
	Vector start = cam.get_pos();
	Vector dir = cam.ray_for_coord(Vector(x, 0.0, y), Vector(screen_w, 0.0, screen_h));

	Vector c = color_for_ray(start, dir, light, 5);
	pixels[y * screen_w + x] = { (float)c.x, (float)c.y, (float)c.z };

	pixels_rendered++;
}

Vector RayTracer::color_for_ray(Vector start, Vector dir, Vector light, int limit) {
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

			Vector dir = light - intersect;
			dir.normalize();

			auto l = 0.2f; // ambient
			auto light = true;

			// check if a shadow hits this surface
			for (auto k : surfaces) {
				if (k->intersects(intersect, dir, intersect)) {
					light = false;
					break;
				}
			}

			if (light) {
				l = min(1.0, max(norm.dot(dir), 0.0) + l);
			}

			color = (s->diffuse * l);
			drawn = true;

		} else if (!drawn) {
			color = Vector(135/255.0, 206/255.0, 235/255.0);
		}
	}

	if (hit && hit->reflection && limit) {
		double reflect = 2.0 * dir.dot(hit_n);
		Vector r = color_for_ray(hit_i, dir - hit_n * reflect, light, limit - 1);
		return (r * hit->reflection) + (color * (1.0 - hit->reflection));
	}

	return color;
}