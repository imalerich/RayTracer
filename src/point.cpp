#include "point.h"

Point::Point() {
	x = 0.0;
	y = 0.0;
	z = 0.0;
}

Point::Point(double X, double Y, double Z) {
	x = X;
	y = Y;
	z = Z;
}

Point Point::operator+(Point &other) {
	return Point(x + other.x, y + other.y, z + other.z);
}

Point Point::operator*(Point &other) {
	return Point(x * other.x, y * other.y, z * other.z);
}

Point Point::operator*(double scalar) {
	return Point(x * scalar, y * scalar, z * scalar);
}