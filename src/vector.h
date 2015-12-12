#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

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
	 double distance(const Vector &other);

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
	 * Scales each value of this Vector with
	 * the corresponding value in the input Vector.
	 * \param other Other Vector to scale this Vector by.
	 * \return The resulting Vector value.
	 */
	Vector operator*(const Vector &other);

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