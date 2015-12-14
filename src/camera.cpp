#include "camera.h"

Camera::Camera(double Near, double FoV, double ARatio) : 
	near_dist{Near}, fov{FoV}, aratio{ARatio} { }

Vector Camera::ray_for_coord(Vector coord, Vector dimm) {
	auto xperc = coord.x / dimm.x;
	auto zperc = coord.z / dimm.z;
	auto width = 2 * near_dist * sin(fov/2);
	auto height = width / aratio;

	return Vector(-(width / 2.0) + (xperc * width), near_dist, (height / 2.0) - (zperc * height));
}