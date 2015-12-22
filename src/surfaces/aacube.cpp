#include <algorithm>
#include <float.h>
#include <assert.h>

#include "aacube.h"

using namespace std;

AACube::AACube(Material Mat, Vector Min, Vector Max) :
		Surface(Mat), min{Min}, max{Max} {
	assert(!(min > max));
}

ostream& operator<<(ostream &os, const AACube &cube) {
	os << "(Min: " << cube.min << ", Max: " << cube.max << ")";
	return os;
}

bool AACube::intersects(Vector start, Vector dir, Vector &location, Vector &normal) {
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

	location.set(start + dir * min_delta);

	if (fabs(location.x - min.x) < epsilon) {
		normal.set(-1.0, 0.0, 0.0);
	} else if (fabs(location.x - max.x) < epsilon) {
		normal.set(1.0, 0.0, 0.0);
	} else if (fabs(location.y - min.y) < epsilon) {
		normal.set(0.0, -1.0, 0.0);
	} else if (fabs(location.y - max.y) < epsilon) {
		normal.set(0.0, 1.0, 0.0);
	} else if (fabs(location.z - min.z) < epsilon) {
		normal.set(0.0, 0.0, -1.0);
	} else if (fabs(location.z - max.z) < epsilon) {
		normal.set(0.0, 0.0, 1.0);
	}

	return (max_delta - min_delta > -epsilon) && (min_delta > -epsilon);
}

AABBox AACube::bounding_box() {
	return AABBox(min, max);
}
