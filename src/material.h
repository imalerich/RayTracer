#ifndef MATERIAL_H
#define MATERIAL_H

#include <assert.h>

#include "math/vector.h"

class Material {
public:
	Material(Vector Diffuse, double SpecScalar, double SpecPow, double Reflect, double Refract) :
		diffuse{Diffuse}, spec_scalar{SpecScalar}, spec_pow{SpecPow}, reflect{Reflect}, refract{Refract} { }

	/**
	 * Generates a random Material.
	 */
	static inline Material rand_mat() {
		auto diffuse = Vector::rand_vec() + Vector(0.5, 0.5, 0.5);
		auto spec_scalar = (rand() % 1000) / 1000.0;
		auto spec_pow = (rand() % 32);
		auto reflect = (rand() % 1000) / 1000.0;
		auto refract = (rand() % 1000) / 1000.0;

		assert(spec_pow >= 0.0);
		assert(reflect <= 1.0 && reflect >= 0.0);
		assert(refract <= 1.0 && refract >= 0.0);
		assert(spec_scalar <= 1.0 && spec_scalar >= 0.0);

		return Material(diffuse, spec_scalar, spec_pow, pow(reflect, 2), pow(refract, 2));
	}

	const Vector diffuse; /**< Diffuse color. */

	const double spec_scalar; /**< Scalar applied to the specular lighting. */
	const double spec_pow; /**< Power used for specular calculation. */

	const double reflect; /**< Reflection index. (0.0, 1.0) */
	const double refract; /**< Refraction index. (0.0, 1.0) */
};

#endif
