#ifndef DIR_LIGHT_H
#define DIR_LIGHT_H

#include "light.h"

/**
 * A simple Directional Light.
 * This light only has a static direction
 * and an intensity. Lighting is determined only by 
 * visibility and alignment of the surface normal 
 * vector with this lights direction (scaled
 * by the intensity).
 */
class DirLight : public Light {
public:
	DirLight(Vector Dir, double Intensity);

	virtual Vector direction_from_point(Vector point, int sample);
	virtual double scalar_for_point(Vector point, Vector normal, Vector dir);

private:
	const double intensity;
	Vector dir;
};

#endif
