#ifndef VECTOR_H
#define VECTOR_H

#include "point.h"

class Vector {
public:
	Vector();
	Vector(Point Pos, Point Dir);

	Point pos; /**< Initial starting point of the vector. */
	Point dir; /**< Direction of the vector. */
};

#endif