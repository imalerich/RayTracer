#ifndef PLANE_H
#define PLANE_H

#include "../vector.h"
#include "surface.h"

class Plane : public Surface {
public:
	Plane(Vector Coord, Vector Norm);
	friend ostream& operator<<(ostream &os, const Plane &plane);

	virtual bool intersects(Vector start, Vector dir, Vector &location, Vector &normal);
	
	virtual bool intersects(Vector start, Vector dir) {
		Vector loc, norm;
		return intersects(start, dir, loc, norm);
	}

	virtual bool intersects(Vector start, Vector dir, Vector &location) {
		Vector norm;
		return intersects(start, dir, location, norm);
	}

	Vector coord; /**< A Coordinate on the plane. */
	const Vector norm; /**< Normal vector of the plane. */
};

#endif
