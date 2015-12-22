#ifndef AACUBE_H
#define AACUBE_H

#include "surface.h"

class AACube : public Surface {
public:
	AACube(Vector Min, Vector Max);
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
