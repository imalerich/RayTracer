#ifndef RAYTRACER_H
#define RAYTRACER_H

#include <vector>

#include "camera.h"

#include "math/octree.h"
#include "math/vector.h"

#include "surfaces/surface.h"
#include "lights/light.h"

using namespace std;

struct Pixel {
	float r;
	float g;
	float b;
};

class RayTracer {
public:
	RayTracer(unsigned Screen_W, unsigned Screen_H);
	~RayTracer();

	/**
	 * Renders the input scene and returns a buffer representing 
	 * the image to the caller.
	 */
	float * render_scene();

	inline double aspect_ratio() {
		return (double)screen_w / (double)screen_h;
	}

private:
	/**
	 * Performs all necessary ray tracing to generate the color at the given point.
	 * The result will be stored in the input data array.
	 * \param x X coordinate in pixels.
	 * \param y Y coordinate in pixels.
	 * \param data Data array to store the resulting color into.
	 */
	void render_point(unsigned x, unsigned y, Pixel * pixels);

	Vector color_for_ray(Vector start, Vector dir, int limit);

	const unsigned screen_w; /**< The width (in pixels) of the image to be rendered. */
	const unsigned screen_h; /**< The height (in pixels) of the image to be rendered. */
	unsigned pixels_rendered;

	Octree * scene;
	vector<Surface *> surfaces;
	vector<Light *> lights;
};

#endif
