#ifndef POINT_H
#define POINT_H

/**
 * Representation of a single point in 3d space.
 * A Point can be used as a Vector with a position
 * at the origin. In this case, the use of the typedef
 * 'OVector' provided in this file is encouraged.
 */
class Point {
public:
	Point();
	Point(double X, double Y, double Z);

	/**
	 * Produces a new Point whos values are the
	 * sume of this Points values, and the corresponding
	 * value in the 'other' Point.
	 * \param other Other Point to add to this point.
	 * \return The resulting Point value.
	 */
	Point operator+(Point &other);

	/**
	 * Scales each value of this point with
	 * the corresponding value in the input Point.
	 * \param other Other Point to scale this point by.
	 * \return The resulting Point value.
	 */
	Point operator*(Point &other);

	/**
	 * Scales each coordinate value of this object
	 * by the input scalar.
	 * \point scalar Scalar to apply to this point.
	 * \return The resulting Point value.
	 */
	Point operator*(double scalar);

	double x; /**< Coordinate along the x axis. */
	double y; /**< Coordinate along the y axis. */
	double z; /**< Coordinate along the z axis. */

private:
};

/**
 * Use of OVector (for Origin Vector) is encouraged
 * when using a Point as a vector.
 */
typedef Point OVector;

#endif