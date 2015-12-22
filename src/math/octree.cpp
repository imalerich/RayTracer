#include <algorithm>
#include <assert.h>
#include <float.h>

#include "octree.h"

Octree::Octree(Vector Origin, double Width, unsigned MaxDepth) :
		origin{Origin}, half_width{Width / 2.0}, max_depth{MaxDepth} { 
	// 0 out all children
	for (auto &c : children) {
		c = nullptr;
	}
}

void Octree::filter_by_ray(const Vector start, const Vector dir, vector<void *> &ret) {
	// If the ray does not intersect this octant. Ignore it.
	if (!bbox_for_self().intersects(start, dir) && !bbox_for_self().contains(start)) {
		return;
	}

	// add items to the ret array.
	for (auto i : items) {
		ret.push_back(i);
	}

	for (auto i = 0; i < OCT_CHILDREN; i++) {
		// if a child exists, recurse through it
		if (children[i]) {
			children[i]->filter_by_ray(start, dir, ret);
		}
	}
}

bool Octree::add_item(const AABBox box, void * data) {
	if (!does_item_fit(box)) {
		return false;
	}

	// if it fits in a child, add it there
	for (auto i = 0; i < OCT_CHILDREN; i++) {
		if (does_item_fit_child(box, i) && max_depth) {
			// will do nothing if not needed
			create_child(i);
			children[i]->add_item(box, data);
			return true;
		}
	}

	// does not fit in any children, add it here
	items.push_back(data);
	return true;
}

AABBox Octree::bbox_for_octant(Octant i) const {
	auto min = Vector(-DBL_MAX, -DBL_MAX, -DBL_MAX);
	auto max = Vector(DBL_MAX, DBL_MAX, DBL_MAX);

	assert(i > 0 && i < OCT_CHILDREN);

	if (i < OCT_BOT_UPPER_RIGHT) {
		min.z = origin.z;
		max.z = min.z + half_width;
	} else {
		max.z = origin.z;
		min.z = max.z - half_width;
	}

	if (i == OCT_TOP_UPPER_RIGHT || i == OCT_TOP_UPPER_LEFT ||
			i == OCT_BOT_UPPER_RIGHT || i == OCT_BOT_UPPER_LEFT) {
		min.y = origin.y;
		max.y = origin.y + half_width;
	} else {
		max.y = origin.y;
		min.y = max.y - half_width;
	}

	if (i == OCT_TOP_UPPER_RIGHT || i == OCT_TOP_LOWER_RIGHT ||
			i == OCT_BOT_UPPER_RIGHT || i == OCT_BOT_LOWER_RIGHT) {
		min.x = origin.x;
		max.x = origin.x + half_width;
	} else {
		max.x = origin.x;
		min.x = max.z - half_width;
	}

	return AABBox(min, max);
}

AABBox Octree::bbox_for_self() const {
	auto tmp = Vector(half_width, half_width, half_width);
	return AABBox(origin - tmp, origin + tmp);
}

bool Octree::does_item_fit(const AABBox box) const {
	return bbox_for_self().contains(box);
}

bool Octree::does_item_fit_child(const AABBox box, Octant i) const {
	return bbox_for_octant(i).contains(box);
}

bool Octree::has_child(Octant i) const {
	return children[i];
}

void Octree::create_child(Octant i) {
	// do not create a child  if not necessary
	if (has_child(i)) {
		return;
	}

	// will throw an exception if 'i' is invalid.
	AABBox bbox = bbox_for_octant(i);
	Vector origin = (bbox.get_min() + bbox.get_max()) * 0.5;
	children[i] = new Octree(origin, half_width, max_depth - 1);
}
