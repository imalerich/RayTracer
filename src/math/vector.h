#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

/**
 * Representation of a single Vector in 3d space.
 * The starting coordinate of the Vector is assumed
 * to be the origin.
 */
class Vector {
public:
	Vector();
	Vector(double X, double Y, double Z);
	friend ostream& operator<<(ostream &os, const Vector &vector);

	/*
	 * The minimum vector is considered to be the Vector with the
	 * smaller magnitude.
	 */
	static Vector min(const Vector &a, const Vector &b);
	
	
	/**
	 * The maximum Vector is considred to be the Vetor with the 
	 * larger magnitude.
	 */
	static Vector max(const Vector &a, const Vector &b);

	/**
	 * \return The magnitude of thie Vector.
	 */
	inline double magnitude() const {
		return distance(Vector());
	}

	/**
	 * Normalizes this vector, such that it's magnitude will be 1.
	 */
	inline void normalize() {
		auto m = magnitude();
		x /= m;
		y /= m;
		z /= m;
	}

	/**
	 * Utility for setting each value of this Vector.
	 * \param X The new x value for this vector.
	 * \param Y The new y value for this vector.
	 * \param Z The new z value for this vector.
	 */
	inline void set(double X, double Y, double Z) {
		x = X;
		y = Y;
		z = Z;
	}

	/**
	 * Utility for setting each value of this Vector.
	 * \param other Vector match.
	 */
	inline void set(Vector other) {
		x = other.x;
		y = other.y;
		z = other.z;
	}

	/**
	 * Tests for equality of two Vectors.
	 * Returns 'true' if both Vectors reside at the 
	 * same point in space.
	 */
	inline bool operator==(const Vector &other) {
		// const static auto epsilon = pow(2, -52);
		const static auto epsilon = 0.00000000001;
		return fabs(x - other.x) < epsilon && fabs(y - other.y) < epsilon && fabs(z - other.z) < epsilon;
	}

	/**
	 * Tests if this vector is:
	 * 	left of, below, and behind
	 * the other vector.
	 */
	inline bool operator<(const Vector &other) {
		return x < other.x && y < other.y && z < other.z;
	}

	/**
	 * Tests if this vector is:
	 *  right of, above, and infront of
	 * the other vector.
	 */
	inline bool operator>(const Vector &other) {
		return x > other.x && y > other.y && z > other.z;
	}

	/**
	 * Performs the dot product on this Vector and
	 * and the input 'other' Vector.
	 * \param other Other Vector to take the dot product with.
	 * \return Resulting scalar value.
	 */
	 double dot(const Vector &other);

	 /**
	  * Takes the cross product of this Vector and the
	  * input 'other' Vector.
	  * \param other Other Vector take the corss product with.
	  * \return Resulting Vector.
	  */
	 Vector cross(const Vector &other);

	/**
	 * Computes the distance between this Vector and the
	 * 'other' Vector.
	 * \param other Other Vector used for distance calculation.
	 * \return The distance between the two vectors.
	 */
	 double distance(const Vector &other) const;

	/**
	 * Produces a new Vector whos values are the
	 * sum of this Vectors values, and the corresponding
	 * value in the 'other' Vector.
	 * \param other Other Vector to add to this Vector.
	 * \return The resulting Vector value.
	 */
	Vector operator+(const Vector &other);

	/**
	 * Produces a new Vector whos values are the
	 * difference of this Vectors values, and the corresponding
	 * value in the 'other' Vector.
	 * \param other Other Vector to subtract from this Vector.
	 * \return The resulting Vector value.
	 */
	Vector operator-(const Vector &other);

	/**
	 * Produces the opposite of this Vector.
	 * \return The resulting Vector value.
	 */
	Vector operator-();

	/**
	 * Scales each component of this Vector with
	 * the corresponding component in the input Vector.
	 * \param other Other Vector to scale this Vector by.
	 * \return The resulting Vector.
	 */
	Vector operator*(const Vector &other);

	/*
	 * Scales each component of this Vector
	 * with the inverse of the corresponding component
	 * in the input Vector.
	 * \param other Other Vector to divide this Vector by.
	 * \return The resulting Vector.
	 */
	Vector operator/(const Vector &other);

	/**
	 * Scales each coordinate value of this object
	 * by the input scalar.
	 * \Vector scalar Scalar to apply to this Vector.
	 * \return The resulting Vector value.
	 */
	Vector operator*(double scalar);

	double x; /**< Coordinate along the x axis. */
	double y; /**< Coordinate along the y axis. */
	double z; /**< Coordinate along the z axis. */

private:
};

#endif