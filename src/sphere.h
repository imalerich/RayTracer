#ifndef SPHERE_H
#define SPHERE_H

#include "point.h"

class Sphere {
public:
	Sphere();
	Sphere(Point Origin, double Radius);

	Point origin; /**< Origin of the sphere. */
	double radius; /**< Radius of the sphere. */
};

#endif