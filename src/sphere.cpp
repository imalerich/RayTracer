#include <math.h>
#include <stdlib.h>
#include "sphere.h"

using namespace std;

Sphere::Sphere() {
	radius = 1.0;
}

Sphere::Sphere(Vector Center, double Radius) {
	center = Center;
	radius = Radius;
}

ostream& operator<<(ostream &os, const  Sphere &sphere) {
	os << "(Center: " << sphere.center << ", Radius: " << sphere.radius << ")";
	return os;
}

unsigned Sphere::intersects(Vector &start, Vector &dir, Vector &location) {
	auto a = pow(dir.magnitude(), 2);
	auto b = 2.0 * (start.dot(dir) - dir.dot(center));
	auto c = pow((center - start).magnitude(), 2) - pow(radius, 2);
	auto delta = pow(b, 2) - (4 * a * c);

	// Return the number of intersections.
	if (delta < 0 || a == 0) {
		return 0;
	} else {
		auto d = delta == 0 ? (-b / 2 * a) : (-b - sqrt(delta)) / (2 * a);
		location.x = start.x + d * dir.x;
		location.y = start.y + d * dir.y;
		location.z = start.z + d * dir.z;

		if (d < 0) {
			return 0;
		}

		return d == 0 ? 1 : 2;
	}
}