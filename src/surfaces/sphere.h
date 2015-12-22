#ifndef SPHERE_H
#define SPHERE_H

#include "surface.h"

using namespace std;

/**
 * A Sphere Surface.
 * This Surface has a center location
 * and is the collection of all points with
 * a distance of 'radius' from that center location.
 */
class Sphere : public Surface {
public:
	Sphere();
	Sphere(Vector Center, double Radius);
	friend ostream& operator<<(ostream &os, const  Sphere &sphere);

	virtual AABBox bounding_box();
	virtual bool intersects(Vector start, Vector dir, Vector &location, Vector &normal);
	
	virtual bool intersects(Vector start, Vector dir) {
		Vector loc, norm;
		return intersects(start, dir, loc, norm);
	}

	virtual bool intersects(Vector start, Vector dir, Vector &location) {
		Vector norm;
		return intersects(start, dir, location, norm);
	}

private:
	const Vector center; /**< Center of the sphere. */
	const double radius; /**< Radius of the sphere. */
};

#endif
