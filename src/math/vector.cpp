#include <math.h>
#include <algorithm>
#include "vector.h"

Vector::Vector() {
	x = 0.0;
	y = 0.0;
	z = 0.0;
}

Vector::Vector(double X, double Y, double Z) {
	x = X;
	y = Y;
	z = Z;
}

ostream& operator<<(ostream &os, const Vector &vector) {
	os << "(x: " << vector.x << ", y: " << vector.y << ", z: " << vector.z << ")";
	return os;
}

double Vector::dot(const Vector &other) {
	return x * other.x + y * other.y + z * other.z;
}

double Vector::distance(const Vector &other) const {
	return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2) + pow(z - other.z, 2));
}

Vector Vector::cross(const Vector &other) {
	auto X = y * other.z + z * other.y;
	auto Y = z * other.x + x * other.z;
	auto Z = x * other.y + y * other.x;

	return Vector(X, Y, Z);
}

Vector Vector::operator+(const Vector &other) {
	return Vector(x + other.x, y + other.y, z + other.z);
}

Vector Vector::operator-(const Vector &other) {
	return Vector(x - other.x, y - other.y, z - other.z);
}

Vector Vector::operator-() {
	return Vector(-x, -y, -z);
}

Vector Vector::operator*(const Vector &other) {
	return Vector(x * other.x, y * other.y, z * other.z);
}

Vector Vector::operator/(const Vector &other) {
	return Vector(x / other.x, y / other.y, z / other.z);
}

Vector Vector::operator*(double scalar) {
	return Vector(x * scalar, y * scalar, z * scalar);
}

Vector Vector::min(const Vector &a, const Vector &b) {
	auto ma = a.magnitude();
	auto mb = b.magnitude();
	return ma < mb ? a : b;
}

Vector Vector::max(const Vector &a, const Vector &b) {
	auto ma = a.magnitude();
	auto mb = b.magnitude();
	return ma > mb ? a : b;
}
