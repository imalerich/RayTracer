#define _USE_MATH_DEFINES
#include <math.h>
#include <algorithm>
#include <numeric>
#include <random>

#include "perlin.h"

PerlinNoise::PerlinNoise() : PerlinNoise(0) { }

PerlinNoise::PerlinNoise(unsigned seed) {
	p.resize(256);
	iota(p.begin(), p.end(), 0);
	default_random_engine engine(seed);
	shuffle(p.begin(), p.end(), engine);
	p.insert(p.end(), p.begin(), p.end());
}

double PerlinNoise::get(double x, double y, double z) {
	// find the unit cube that contains the coordiante
	auto X = (int)floor(x) & 255;
	auto Y = (int)floor(y) & 255;
	auto Z = (int)floor(z) & 255;

	// find the relative x, y, z of the point in the cube
	x -= floor(x);
	y -= floor(y);
	z -= floor(z);

	// computes the fade curves
	auto u = fade(x);
	auto v = fade(y);
	auto w = fade(z);

	// hash coordinates
	auto A = p[X] + Y;
	auto AA = p[A] + Z;
	auto AB = p[A + 1] + Z;
	auto B = p[X + 1] + Y;
	auto BA = p[B] + Z;
	auto BB = p[B + 1] + Z;

	auto res =	lerp(w, 
				lerp(v, 
				lerp(u, grad(p[AA], x, y, z), grad(p[BA], x-1, y, z)), 
				lerp(u, grad(p[AB], x, y-1, z), grad(p[BB], x-1, y-1, z))),	
				lerp(v, 
				lerp(u, grad(p[AA+1], x, y, z-1), grad(p[BA+1], x-1, y, z-1)), 
				lerp(u, grad(p[AB+1], x, y-1, z-1),	grad(p[BB+1], x-1, y-1, z-1))));
	return (res + 1.0) / 2.0;
}

double PerlinNoise::grad(int hash, double x, double y, double z) {
	auto h = hash & 15;

	auto u = h < 8 ? x : y,
		   v = h < 4 ? y : h == 12 || h == 14 ? x : z;
	return ((h & 1) == 0 ? u : -u) + ((h & 2) == 0 ? v : -v);
}

double PerlinNoise::fade(double t) {
	return t * t * t * (t * (t * 6 - 15) + 10);
}

double PerlinNoise::lerp(double w, double a, double b) {
	return (1.0 - w) * a + w * b;
}

double PerlinNoise::cerp(double a, double b, double w) {
	auto c = (1.0 - cos(w * M_PI)) * 0.5;
	return (1.0 - c) * a + c * b;
}
