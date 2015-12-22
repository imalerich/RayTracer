#ifndef I_LIGHT_H
#define I_LIGHT_H

#include "../math/vector.h"

/**
 * Interface for a light.
 * Defines the necessary methods a class must adhere to be
 * used as a light when it comes to rendering a scene.
 */
class Light {
public:
	virtual ~Light() { }

	Vector diffuse; /**< Diffuse color of this light. */

	/**
	 * The number of samples needed for this light.
	 * This is only necessary for volumetric lights.
	 * Point and Directional lights will only need one sample.
	 * \return Number of samples to take when rendering.
	 */
	virtual unsigned num_samples() {
		return 1;
	}

	/**
	 * Returns the direction from the input point to this
	 * light source.
	 * \param point The point to take the direction from.
	 * \param sample The current sample we are taking.
	 * \return The direction vector.
	 */
	virtual Vector direction_from_point(Vector point, int sample) = 0;

	/**
	 * If a given coordinate in space has view of this light,
	 * this method will return the light scale (0.0, 1.0) for
	 * the input point given its input normal for this light.
	 * \param point The point in question.
	 * \param normal Normal vector of the surface the point resides on.
	 * \param dir The direction received from direction_from_point().
	 * \return Lighting scalar value contributed to the diffuse color of the surface.
	 */
	virtual double scalar_for_point(Vector point, Vector normal, Vector dir) = 0;
};

#endif
