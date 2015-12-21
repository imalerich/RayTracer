#ifndef DIR_LIGHT_H
#define DIR_LIGHT_H

#include "light.h"

class DirLight : public Light {
public:
	DirLight(Vector Dir, double Intensity);

	virtual Vector direction_from_point(Vector point);
	virtual double scalar_for_point(Vector point, Vector normal);

private:
	double intensity;
	Vector dir;
};

#endif
