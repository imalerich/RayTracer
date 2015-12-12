#ifndef RAYTRACER_H
#define RAYTRACER_H

class RayTracer {
public:
	RayTracer(unsigned Screen_W, unsigned Screen_H);

	/**
	 * Renders the input scene and returns a buffer representing 
	 * the image to the caller.
	 */
	float * render_scene();

private:
	const unsigned screen_w; /**< The width (in pixels) of the image to be rendered. */
	const unsigned screen_h; /**< The height (in pixels) of the image to be rendered. */
};

#endif