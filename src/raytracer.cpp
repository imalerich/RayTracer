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
	surfaces.push_back(new Sphere(Vector(-1.5, 4.0, 0.0), 1.0));
	surfaces.push_back(new Sphere(Vector(1.5, 5.0, 0.0), 1.0));
	surfaces.push_back(new Plane(Vector(0.0, 0.0, -1.0), Vector(0.0, 0.0, 1.0)));

	for (auto s : surfaces) {
		s->color = Vector((rand() % 1000) / 1000.0, (rand() % 1000) / 1000.0, (rand() % 1000) / 1000.0);
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
	Vector dir = cam.ray_for_coord(Vector(x, 0.0, y), Vector(screen_w, 0.0, screen_h));
	Vector norm;
	Vector intersect;
	auto dist = DBL_MAX;
	auto drawn = false;

	for (auto s : surfaces) {
		if (s->intersects(cam.get_pos(), dir, intersect, norm)) {
			// make sure this point is closer than the last renedered point
			if (intersect.magnitude() > dist) {
				continue;
			} else {
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

			pixels[y * screen_w + x] = { l * (float)s->color.x, l * (float)s->color.y, l * (float)s->color.z };
			drawn = true;

		} else if (!drawn) {
			pixels[y * screen_w + x] = { 0.0, 0.0, 0.0 };
		}
	}

	pixels_rendered++;
}