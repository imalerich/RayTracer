#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <float.h>

#include "plane.h"

Plane::Plane(Vector Coord, Vector Norm) :
	coord{Coord}, norm{Norm} { }

ostream& operator<<(ostream &os, const Plane &plane) {
	os << "(Coord: " << plane.coord << ", Normal: " << plane.norm << ")";
	return os;
}

bool Plane::intersects(Vector start, Vector dir, Vector &location, Vector &normal) {
	const static auto epsilon = 0.00000000000001;
	normal.set(norm);

	// the plane and vector are parallel
	if (fabs(dir.dot(norm)) < epsilon) {
		return false;
	}

	auto numerator = (coord - start).dot(norm);
	auto d = numerator / dir.dot(norm);

	if (d < 0) {
		return false;
	}

	location = start + dir * d;
	return !(location == start);
}

AABBox Plane::bounding_box() {
	return AABBox(Vector(-DBL_MAX, -DBL_MAX, -DBL_MAX), 
			Vector(DBL_MAX, DBL_MAX, DBL_MAX));
}
