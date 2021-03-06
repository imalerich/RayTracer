#ifndef I_SURFACE
#define I_SURFACE

#include "../math/vector.h"
#include "../math/aabbox.h"
#include "../material.h"

/**
 * Interface for a Surface. A Surface defines
 * an intersection test with a Ray and itself,
 * and can provide the location of intersection
 * allong with the normal Vector of that intersection
 * location.
 */
class Surface {
public:
	Surface(Material Mat) : mat{Mat} { }
	virtual ~Surface() { }

	Material mat; /**< Material used to render the current surface. */

	/**
	 * Determins whether or not this Surface intersects the input
	 * line (determined by the start coordinate and  direction vector).
	 * If an intersection occurs, the location of the intersection
	 * is stored in the 'location' parameter.
	 * \param start Start coordinate of the line.
	 * \param dir Direction vector of the line.
	 * \param location (return) The point of intersection.
	 * \param normal (return) Normal vector to the point of intersection.
	 * \return Whether or not an intersection occured.
	 */
	virtual bool intersects(Vector start, Vector dir, Vector &location, Vector &normal) = 0;

	/**
	 * Utility that calls 'intersect' with no return location or normal.
	 * \param start Start coordinate of the line.
	 * \param dir Direction vector of the line.
	 */
	virtual bool intersects(Vector start, Vector dir) {
		Vector loc, norm;
		return intersects(start, dir, loc, norm);
	}

	/**
	 * Utility that calls the full 'intersect' with only a return location,
	 * but no return normal.
	 * \param start Start coordinate of the line.
	 * \param dir Direction vector of the line.
	 * \param location (return) The point of intersection.
	 */
	virtual bool intersects(Vector start, Vector dir, Vector &location) {
		Vector norm;
		return intersects(start, dir, location, norm);
	}

	/**
	 * Return bounding box for this Surface.
	 * Used for optimization purposes.
	 * \return The bounding box of this surface.
	 */
	virtual AABBox bounding_box() = 0;
};

#endif
