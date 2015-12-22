#ifndef OCTREE_H
#define OCTREE_H

#include <vector>

#include "../math/aabbox.h"

#define OCT_CHILDREN 8

#define OCT_TOP_UPPER_RIGHT 0
#define OCT_TOP_UPPER_LEFT  1
#define OCT_TOP_LOWER_LEFT  2
#define OCT_TOP_LOWER_RIGHT 3

#define OCT_BOT_UPPER_RIGHT 4
#define OCT_BOT_UPPER_LEFT  5
#define OCT_BOT_LOWER_LEFT  6
#define OCT_BOT_LOWER_RIGHT 7

typedef int Octant;

class Octree {
public:
	Octree(Vector Origin, double Width, unsigned MaxDepth);

	/**
	 * Adds the references from the 'items' array to the 'ret' parameter
	 * from this octant and it's children whos bounding box collides with the
	 * input ray.
	 * \param start Start coordinate of the ray.
	 * \param dir Direction vector of the ray.
	 * \param ret Array to add items to, if this octant intersects the input ray.
	 */
	void filter_by_ray(const Vector start, const Vector dir, vector<void *> &ret);

	/**
	 * If this item fits within this octant, this will recursively add
	 * the item to the deepest level of the Octree that the data best fits.
	 * If this method fails for this octant, this method returns false.
	 * This method is guaranteed to return the same as does_item_fit().
	 * \param box Bounding box for the item to add.
	 * \param data Data to be stored with the given bounding box.
	 * \return Whether or not the add was succesfull.
	 */
	bool add_item(const AABBox box, void * data);

	/**
	 * Creates an AABBox representation of the given child.
	 * This method does not require that the child actually exist.
	 * \param i Octant index.
	 * \return AABBox for that index.
	 */
	AABBox bbox_for_octant(Octant i) const;

	/**
	 * Creates an AABBox representation of this octant.
	 * \return AABBox for this octant.
	 */
	AABBox bbox_for_self() const;

	/**
	 * Determines whether or not the input box fits within the bounds of
	 * this octant.
	 * \param box Bounding box to test.
	 * \return true if box fits within this Octants bounds.
	 */
	bool does_item_fit(const AABBox box) const;

	/**
	 * Determines whether or not the input box fits within the bounds of 
	 * the child octant. This method does not require that
	 * the child octant actual exist.
	 * \param box Bounding box to test.
	 * \param i Octant index.
	 * \return Whether the input item fits the given octant.
	 */
	bool does_item_fit_child(const AABBox box, Octant i) const;

private:
	/** Center coordinate of this Octree octant. */
	const Vector origin;
	/** Half width of this segment, extending in half_width in each direction of origin. */
	const double half_width;
	/** Maximum depth allowed from here (0 if no children allowed). */
	const unsigned max_depth;

	/** Recursive child Octree poitners. */
	Octree * children[8];
	/** Array of items contained in this segment. */
	vector<void *> items;

	/** Returns true if the input octant exists. */
	inline bool has_child(Octant i) const;

	/** Creates the child at the given Octant index. */
	inline void create_child(Octant i);
};

#endif
