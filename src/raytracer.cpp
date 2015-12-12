#include <math.h>
#include "raytracer.h"
#include "vector.h"
#include "sphere.h"

using namespace std;

struct Pixel {
	float r;
	float g;
	float b;
};

RayTracer::RayTracer(unsigned Screen_W, unsigned Screen_H) 
		: screen_w{Screen_W}, screen_h{Screen_H} { }

float * RayTracer::render_scene(Vector light) {
	Pixel * pixels = new Pixel[screen_w * screen_h];
	Vector dir(Vector(0.0, 1.0, 0.0));
	Sphere s(Vector(0.0, 2.0, 0.0), 0.2);

	auto height = 1.0;
	auto width = height * aspect_ratio();

	for (auto y = 0; y < screen_h; y++) {
		for (auto x = 0; x < screen_w; x++) {
			// create the light ray for this pixel
			Vector start(width * (x / (double)screen_w) - (width / 2.0), 0.0, height * (y / (double)screen_h) - (height / 2.0));
			Vector intersect;

			if (s.intersects(start, dir, intersect)) {
				Vector dir = light - intersect;

				if (s.intersects(intersect, dir, intersect)) {
					pixels[y * screen_w + x] = { 0.0, 0.0, 0.2 };
				} else {
					pixels[y * screen_w + x] = { 1.0, 1.0, 1.0 };
				}

			} else {
				pixels[y * screen_w + x] = { 0.1, 0.1, 0.1 };
			}
		}
	}

	return (float *)pixels;
}