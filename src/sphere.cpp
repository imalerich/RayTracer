#include "sphere.h"

Sphere::Sphere() {
	radius = 1.0;
}

Sphere::Sphere(Point Origin, double Radius) {
	origin = Origin;
	radius = Radius;
}