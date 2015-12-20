#ifndef POINT_LIGHT_H
#define POINT_LIGHT_H

#include "light.h"

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