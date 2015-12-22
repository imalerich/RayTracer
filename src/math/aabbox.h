#ifndef AABBOX_H
#define AABBOX_H

#include "vector.h"

/**
 * Axis-Aligned Bounding Box for
 * visibility determination.
 * If a surface is needed, use AACube insteaad, this adheres to the Surface 
 * interface and provides normal and intersection location vectors.
 */
class AABBox {
public:
	AABBox(Vector Min, Vector Max);

	/**
	 * Determines whether the input 'other' bounding
	 * box is entirly containted within this bounding
	 * box.
	 * \param other The other box to test.
	 * \return true if 'other' fits within the bounds of 'this'.
	 */
	bool contains(const AABBox &other);

	/**
	 * Determines whether the input coordinate 
	 * exists within the bounds of this bounding box.
	 * \param coord Coordinate to test.
	 * \return true if 'coord fits within the bounds of 'this'.
	 */
	bool contains(const Vector &coord);

	/**
	 * Returns true if an intersection occurs with
	 * the input ray and this axis-aligned bounding box.
	 * \param start Start coord for the ray.
	 * \param dir Direction vector for the ray.
	 * \return Whether or not an intersection occurs.
	 */
	bool intersects(Vector start, Vector dir);

	/** Read-Only getter for the minimum corner. */
	inline Vector get_min() {
		return min;
	}

	/** Read-Only getter for the maximum corner. */
	inline Vector get_max() {
		return max;
	}

private:
	Vector min;
	Vector max;
};

#endif
