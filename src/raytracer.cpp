#define _USE_MATH_DEFINES
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
	Camera cam(1.0, M_PI/2.0, (double)screen_w / (double)screen_h);
	Pixel * pixels = new Pixel[screen_w * screen_h];
	Sphere s(Vector(0.0, 3.0, 0.0), 1.0);

	auto height = 1.0;
	auto width = height * aspect_ratio();

	for (auto y = 0; y < screen_h; y++) {
		for (auto x = 0; x < screen_w; x++) {
			// create the light ray for this pixel
			Vector dir = cam.ray_for_coord(Vector(x, 0.0, y), Vector(screen_w, 0.0, screen_h));
			Vector intersect;

			if (s.intersects(cam.get_pos(), dir, intersect)) {
				Vector dir = light - intersect;

				if (s.intersects(intersect, dir)) {
					pixels[y * screen_w + x] = { 0.0, 0.0, 0.2 };
				} else {
					pixels[y * screen_w + x] = { 1.0, 1.0, 1.0 };
				}

			} else {
				pixels[y * screen_w + x] = { 135/255.0, 206/255.0, 235/255.0 };
			}
		}
	}

	return (float *)pixels;
}