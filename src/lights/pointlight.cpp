#include "pointlight.h"

PointLight::PointLight(Vector Pos, double Intensity, double Range) : 
	intensity{Intensity}, range{Range}, pos{Pos} { }

Vector PointLight::direction_from_point(Vector point, int sample) {
	Vector dir = pos - point;
	dir.normalize();
	return dir;
}

double PointLight::scalar_for_point(Vector point, Vector normal, Vector dir) {
	if (range == 0.0) {
		return 0.0;
	}

	auto dist = (pos - point).magnitude();

	normal.normalize();
	dir.normalize();

	auto i = 1.0 - (dist / range);
	auto l_val = normal.dot(dir);

	if (i < 0.0) {
		return 0.0;
	}

	return i * l_val * intensity;
}
