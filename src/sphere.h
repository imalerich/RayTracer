#ifndef SPHERE_H
#define SPHERE_H

#include <iostream>
#include "vector.h"

using namespace std;

class Sphere {
public:
	Sphere();
	Sphere(Vector Center, double Radius);
	friend ostream& operator<<(ostream &os, const  Sphere &sphere);

	/**
	 * Determins whether or not this Sphere intersects the input
	 * line (determined by the start coordinate and  direction vector).
	 * If an intersection occurs, the location of the intersection
	 * is stored in the 'location' parameter.
	 * \param start Start coordinate of the line.
	 * \param dir Direction vector of the line.
	 * \param location (return) The point of intersection.
	 * \return How many intersections occured (0, 1, or 2).
	 */
	unsigned intersects(Vector &start, Vector &dir, Vector &location);

	Vector center; /**< Center of the sphere. */
	double radius; /**< Radius of the sphere. */
};

#endif