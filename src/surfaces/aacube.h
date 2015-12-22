#ifndef AACUBE_H
#define AACUBE_H

#include "surface.h"

/**
 * Axis-Aligned cube surface.
 * This surface is defined exclusively
 * by it's minimum and maximum coordinates.
 */
class AACube : public Surface {
public:
	AACube(Material Mat, Vector coord, double width);
	AACube(Material Mat, Vector Min, Vector Max);
	friend ostream& operator<<(ostream &os, const AACube &AACube);

	virtual AABBox bounding_box();
	virtual bool intersects(Vector start, Vector dir, Vector &location, Vector &normal);
	
	virtual bool intersects(Vector start, Vector dir) {
		Vector loc, norm;
		return intersects(start, dir, loc, norm);
	}

	virtual bool intersects(Vector start, Vector dir, Vector &location) {
		Vector norm;
		return intersects(start, dir, location, norm);
	}
	
private:
	Vector min;
	Vector max;
};

#endif
