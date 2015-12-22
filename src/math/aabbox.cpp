#include <algorithm>
#include <assert.h>
#include <float.h>

#include "aabbox.h"

AABBox::AABBox(Vector Min, Vector Max) :
		min{Min}, max{Max} {
	assert(!(min > max));
}

bool AABBox::contains(const AABBox &other) {
	return min < other.min && max > other.max;
}

bool AABBox::contains(const Vector &coord) {
	return min < coord && max > coord;
}

bool AABBox::intersects(Vector start, Vector dir) {
	const static auto epsilon = 0.00000000000001;
	Vector d_min(-DBL_MAX, -DBL_MAX, -DBL_MAX);
	Vector d_max(DBL_MAX, DBL_MAX, DBL_MAX);

	for (int i=0; i<3; i++) {
		if (fabs(dir[i]) > epsilon) {
			d_min[i] = (min[i] - start[i]) / dir[i];
			d_max[i] = (max[i] - start[i]) / dir[i];
		} else if (min[i] > start[i] || max[i] < start[i]) {
			return false;
		}
	}

	for (int i=0; i<3; i++) {
		if (dir[i] < -epsilon) {
			swap(d_min[i], d_max[i]);
		}
	}

	auto min_delta = fmax(fmax(d_min.x, d_min.y), d_min.z);
	auto max_delta = fmin(fmin(d_max.x, d_max.y), d_max.z);

	return (max_delta - min_delta > -epsilon) && (min_delta > -epsilon);
}
