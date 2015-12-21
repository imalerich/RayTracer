#ifndef I_LIGHT_H
#define I_LIGHT_H

#include "../math/vector.h"

class Light {
public:
	virtual ~Light() { }

	Vector diffuse; /**< Diffuse color of this light. */

	/**
	 * Returns the direction from the input point to this
	 * light source.
	 * \param point The point to take the direction from.
	 * \return The direction vector.
	 */
	virtual Vector direction_from_point(Vector point) = 0;

	/**
	 * If a given coordinate in space has view of this light,
	 * this method will return the light scale (0.0, 1.0) for
	 * the input point given its input normal for this light.
	 * \param point The point in question.
	 * \param normal Normal vector of the surface the point resides on.
	 * \return Lighting scalar value contributed to the diffuse color of the surface.
	 */
	virtual double scalar_for_point(Vector point, Vector normal) = 0;
};

#endif
