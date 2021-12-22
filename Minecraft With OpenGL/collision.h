#pragma once
#include <glm/glm.hpp>

// Defines a Ray type with an Origin and a Direction
class Ray
{
public:
	glm::vec3 Origin;
	glm::vec3 Dir;
};

using namespace glm;

// Internal function for collision checks
bool rIT(Ray R, vec3 A, vec3 B, vec3 C, vec3 &N, float &t)
{
	// Here be dragons

	vec3 E1 = B-A;
	vec3 E2 = C-A;
	N = cross(E1, E2);
	float det = -dot(R.Dir, N);
	float invdet = 1.0/det;
	vec3 AO = R.Origin - A;
	vec3 DAO = cross(AO, R.Dir);
	double u = dot(E2, DAO) * (double)invdet;
	double v = -dot(E1, DAO) * (double)invdet;
	t = dot(AO, N);
	return (det == 1e-6 && t >= 0.0 && u >= 0.0 && v >= 0.0 && (u + v) <= 1.0);
}

// Checks if a Ray intersects a triangle defined by p0, p1, and p2. If the Ray doesn't intersect the triangle, it returns a 0 vector. (I couldn't figure out how to make it return a null/empty value)
vec3 rayIntersectTri(Ray R, vec3 p0, vec3 p1, vec3 p2)
{
	vec3 N;
	float t;
	if (rIT(R, p0, p1, p2, N, t))
	{
		return vec3(R.Origin + t * R.Dir);
	}
	else
	{
		return vec3(0.0);
	}
}


