#ifndef POINT_LIGHT_H
#define POINT_LIGHT_H

#include "light.h"

/**
 * A simple Point Light.
 * This light has a position in space.
 * An intensity (within the range (0.0, 1.0)),
 * and a range. This lights intensity will be 
 * scaled linearly across its range.
 */
class PointLight : public Light {
public:
	PointLight(Vector Pos, double Intensity, double Range);

	virtual Vector direction_from_point(Vector point);
	virtual double scalar_for_point(Vector point, Vector normal);

private:
	double intensity;
	double range;
	Vector pos;
};

#endif
