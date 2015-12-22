#ifndef BALLLIGHT_H
#define BALLLIGHT_H

#include "pointlight.h"

/**
 * Volumetric Ball Light.
 * Will average a number of samples from rays
 * going to random directions on this volumes
 * surface.
 */
class BallLight : public PointLight {
public:
	BallLight(Vector Pos, double Radius, double Intensity, double Range);

	virtual unsigned num_samples();
	virtual Vector direction_from_point(Vector point, int sample);
	virtual double scalar_for_point(Vector point, Vector normal, Vector dir);

private:
	const double radius;
};

#endif
