#ifndef PERLIN_H
#define PERLIN_H

#include <vector>
#include "vector.h"

/**
 * 2 dimmensional Perlin noise buffer.
 *
 * Based on the implementation
 * https://github.com/sol-prog/Perlin_Noise
 */
class PerlinNoise {
public:
	PerlinNoise();
	PerlinNoise(unsigned seed);

	/**
	 * Returns the Perlin noise value for
	 * this grid the given coordinate.
	 * \param x X coordinate.
	 * \param y Y coordinate.
	 * \return The perlin noise value.
	 */
	double get(double x, double y, double Z);

private:
	/**
	 * Linearly Interpolates 'a' and 'b' by factor 'w'.
	 * Where 'w' referes to the weighting applied to 'b'.
	 * \param w Weighting value.
	 * \param a First weighted value.
	 * \param b Second weighted value.
	 */
	double lerp(double w, double a, double b);

	/**
	 * Interpolates using the cosine function 'a' and 'b' by factor 'w'.
	 * Where 'w' referes to the weighting applied to 'b'.
	 * \param w Weighting value.
	 * \param a First weighted value.
	 * \param b Second weighted value.
	 */
	double cerp(double w, double a, double b);

	/**
	 * Fades the input value.
	 */
	double fade(double t);

	/**
	 * Computes the dot product of the distance and gradient vectors.
	 */
	double grad(int hash, double x, double y, double z);

	vector<int> p; /**< Permutation vector. */
};

#endif
