#include "camera.h"

Camera::Camera(double Near, double FoV, double ARatio) : 
	near_dist{Near}, fov{FoV}, aratio{ARatio} { }

Vector Camera::ray_for_coord(Vector coord, Vector dimm) {
	auto xperc = coord.x / dimm.x;
	auto zperc = coord.z / dimm.z;

	return Vector(-(aratio / 2.0) + (xperc * aratio), near_dist, 0.5 - zperc);
}