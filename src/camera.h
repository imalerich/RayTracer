#ifndef CAMERA_H
#define CAMERA_H

#include "vector.h"

class Camera {
public:
	Camera(double Near, double FoV, double ARatio);

	Vector ray_for_coord(Vector coord, Vector dimm);

private:
	const double near_dist;
	const double fov;
	const double aratio;
};

#endif