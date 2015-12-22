#include <algorithm>
#include <stdlib.h>
#include <math.h>

#include "sphere.h"

using namespace std;

Sphere::Sphere() : radius{1.0} { }

Sphere::Sphere(Vector Center, double Radius) : 
	center{Center}, radius{Radius} { }

ostream& operator<<(ostream &os, const  Sphere &sphere) {
	os << "(Center: " << sphere.center << ", Radius: " << sphere.radius << ")";
	return os;
}

bool Sphere::intersects(Vector start, Vector dir, Vector &location, Vector &normal) {
	const static auto epsilon = 0.00000000001;
	auto a = pow(dir.magnitude(), 2);
	auto b = 2.0 * (start.dot(dir) - dir.dot(center));
	auto c = pow((Vector(center) - start).magnitude(), 2) - pow(radius, 2);
	auto delta = pow(b, 2) - (4 * a * c);

	// Return the number of intersections.
	if (delta < -epsilon || a == 0) {
		return false;
	} else {
		// if delta is 0
		auto d = -(b + sqrt(delta)) / (2 * a);

		// if delta is positive
		if (fabs(delta) > epsilon) {
			auto d0 = (-b - sqrt(delta)) / (2 * a);
			auto d1 = (-b + sqrt(delta)) / (2 * a);

			// if one is negative, grab the larger one
			// if both are positive, grab the smaller one
			d = (d0 < epsilon) || (d1 < epsilon) ? max(d0, d1) : min(d0, d1);
		}

		if (d > epsilon) {
			location.set(start.x + d * dir.x, start.y + d * dir.y , start.z + d * dir.z);
			normal.set(location - center);
			normal.normalize();

			return true;
			
		} else {
			return false;
		}
	}
}

AABBox Sphere::bounding_box() {
	auto r = Vector(radius, radius, radius);
	return AABBox(center - r, center + r);
}
