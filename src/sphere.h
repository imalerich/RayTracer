#ifndef SPHERE_H
#define SPHERE_H

#include <iostream>

#include "vector.h"
#include "surface.h"

using namespace std;

class Sphere : public Surface {
public:
	Sphere();
	Sphere(Vector Center, double Radius);
	friend ostream& operator<<(ostream &os, const  Sphere &sphere);

	virtual bool intersects(Vector start, Vector dir, Vector &location, Vector &normal);
	
	virtual bool intersects(Vector start, Vector dir) {
		Vector loc, norm;
		return intersects(start, dir, loc, norm);
	}

	virtual bool intersects(Vector start, Vector dir, Vector &location) {
		Vector norm;
		return intersects(start, dir, location, norm);
	}

	const Vector center; /**< Center of the sphere. */
	const double radius; /**< Radius of the sphere. */
};

#endif