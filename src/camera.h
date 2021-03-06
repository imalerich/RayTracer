#ifndef CAMERA_H
#define CAMERA_H

#define _USE_MATH_DEFINES
#include <math.h>

#include "math/vector.h"

/**
 * Encapsulates all necessary data to 
 * represent a Camera objeect. This includes 
 * a position in space, rotational information, as
 * well as the definition for the near plane which
 * the scene will be rendered to.
 */
class Camera {
public:
	Camera() : near_dist{1.0}, fov{M_PI/2.0}, aratio{1.0} { }
	Camera(double Near, double FoV, double ARatio);

	/**
	 * \return The current camera position.
	 */
	inline Vector get_pos() {
		return Vector();
	}

	/**
	 * Creates a ray representing the direction to shoot
	 * given the input coord and dimm.
	 * \param coord The current screen coordinate (in pixels).
	 * \param dimm The current screen dimmensions (in pixels).
	 * \return The direction vector.
	 */
	Vector ray_for_coord(Vector coord, Vector dimm);

private:
	const double near_dist;
	const double fov;
	const double aratio;
};

#endif
