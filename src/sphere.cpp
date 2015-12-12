#include <math.h>
#include <stdlib.h>
#include "sphere.h"

using namespace std;

Sphere::Sphere() {
	radius = 1.0;
}

Sphere::Sphere(Vector Origin, double Radius) {
	origin = Origin;
	radius = Radius;
}

ostream& operator<<(ostream &os, const  Sphere &sphere) {
	os << "(Origin: " << sphere.origin << ", Radius: " << sphere.radius << ")";
	return os;
}

unsigned Sphere::intersects(Vector &start, Vector &dir, Vector &location) {
	Vector end = start + dir;

	auto a = pow(end.x - start.x, 2) + pow(end.y - start.y, 2) + pow(end.z - start.z, 2);
	auto b = 2 * (
		(end.x - start.x) * (start.x - origin.x) + 
		(end.y - start.y) * (start.y - origin.y) +
		(end.z - start.z) * (start.z - origin.z));
	auto c = pow(start.x - origin.x, 2) + 
		pow(start.y - origin.y, 2) + 
		pow(start.z - origin.z, 2) - pow(radius, 2);
	auto delta = pow(b, 2) - (4 * a * c);

	// Return the number of intersections.
	if (delta < 0) {
		return 0;
	} else {
		auto d = delta == 0 ? (-b / 2 * a) : (-b - sqrt(delta)) / (2 * a);
		location.x = start.x + d * dir.x;
		location.y = start.y + d * dir.y;
		location.z = start.z + d * dir.z;

		const static auto epsilon = 0.0000000001;
		if (abs(start.distance(origin) - radius) < epsilon && delta == 0) {
			return 0;
		}

		return delta == 0 ? 1 : 2;
	}
}