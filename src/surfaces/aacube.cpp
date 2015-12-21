#include <exception>
#include <algorithm>
#include "aacube.h"

using namespace std;

AACube::AACube(Vector Min, Vector Max) :
		min{Min}, max{Max} {
	if (min > max) {
		throw invalid_argument("AACube::AACube() - invalid min/max");
	}
}

ostream& operator<<(ostream &os, const AACube &cube) {
	os << "(Min: " << cube.min << ", Max: " << cube.max << ")";
	return os;
}

bool AACube::intersects(Vector start, Vector dir, Vector &location, Vector &normal) {
	const static auto epsilon = 0.00000000000001;
	Vector d_min(start);
	Vector d_max(start);

	if (dir.x != 0.0) {
		d_min.x = (min.x - start.x) / dir.x;
		d_max.x = (max.x - start.x) / dir.x;
	} else if (min.x > start.x || max.x < start.x) {
		return false;
	}

	if (dir.y != 0.0) {
		d_min.y = (min.y - start.y) / dir.y;
		d_max.y = (max.y - start.y) / dir.y;
	} else if (min.y > start.y || max.y < start.y) {
		return false;
	}

	if (dir.z != 0.0) {
		d_min.z = (min.z - start.z) / dir.z;
		d_max.z = (max.z - start.z) / dir.z;
	} else if (min.z > start.z || max.z < start.z) {
		return false;
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

	return (max_delta >= min_delta) && (min_delta > -epsilon);
}
