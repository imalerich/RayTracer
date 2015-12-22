#define _USE_MATH_DEFINES
#include <math.h>
#include "balllight.h"

BallLight::BallLight(Vector Pos, double Radius, double Intensity, double Range) :
	PointLight(Pos, Intensity, Range), radius{Radius} { }

unsigned BallLight::num_samples() {
	return 128;
}

Vector BallLight::direction_from_point(Vector point, int sample) {
	Vector r = Vector::rand_vec() * radius;
	Vector p = pos + r;

	Vector dir = p - point;
	dir.normalize();
	return dir;
}

double BallLight::scalar_for_point(Vector point, Vector normal, Vector dir) {
	return PointLight::scalar_for_point(point, normal, dir);
}
