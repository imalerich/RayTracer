#include "dirlight.h"

DirLight::DirLight(Vector Dir, double Intensity) :
		intensity{Intensity}, dir{-Dir} { 
	dir.normalize();
}

Vector DirLight::direction_from_point(Vector point, int sample) {
	return dir;
}

double DirLight::scalar_for_point(Vector point, Vector normal, Vector dir) {
	normal.normalize();
	return normal.dot(dir) * intensity;
}
