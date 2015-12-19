#define _USE_MATH_DEFINES
#include <math.h>
#include <thread>

#include "raytracer.h"
#include "vector.h"
#include "sphere.h"

using namespace std;

RayTracer::RayTracer(unsigned Screen_W, unsigned Screen_H) 
		: screen_w{Screen_W}, screen_h{Screen_H} { }

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
	Sphere s(Vector(0.0, 3.0, 0.0), 1.0);
	Camera cam(1.0, M_PI/2.0, (double)screen_w / (double)screen_h);

	// create the light ray for this pixel
	Vector dir = cam.ray_for_coord(Vector(x, 0.0, y), Vector(screen_w, 0.0, screen_h));
	Vector norm;
	Vector intersect;

	if (s.intersects(cam.get_pos(), dir, intersect, norm)) {
		Vector color(61/255.0, 102/255.0, 70/255.0);
		Vector dir = light - intersect;
		dir.normalize();

		auto l = 0.2; // ambient
		if (!s.intersects(intersect, dir, intersect)) {
			l = min(1.0, max(norm.dot(dir), 0.0) + l);
		}

		color = color * l;
		pixels[y * screen_w + x] = { (float)color.x, (float)color.y, (float)color.z };

	} else {
		pixels[y * screen_w + x] = { 135/255.0, 206/255.0, 235/255.0 };
	}

	pixels_rendered++;
}