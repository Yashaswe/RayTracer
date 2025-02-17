/*
 * Sphere.cpp
 *
 *  Created on: Feb 3, 2025
 *      Author: yash
 */

#include "Sphere.h"

#include "Vector.h"
#include "Unit.h"
#include "utils.h"

#include <cmath>

ostream& operator<<(ostream& os, const Sphere& sphere){
	os << "Sphere: " << sphere.center << " " << sphere.radius << " " << sphere.color << " " << sphere.material;
	return os;
}
istream& operator>>(istream& is, Sphere& sphere){


	string type;
	is >> type;
	is >> sphere.center;

	is >> type;
	is >> sphere.radius;
	is >> type;
	sphere.readAppearance(is);

	return is;
}

optional<Hit> Sphere::intersect(const Ray& ray) const{
	Vector D = ray.dir();
	Vector L(center, ray.origin());

	float a = dot(D, D);
	float b = 2*dot(D, L);
	float c = dot(L,L) - radius*radius;

	pair<float, float> roots = findRoots(a, b, c);
	float t1 = roots.first;
	float t2 = roots.second;
	if(t1 > ZERO){
		return getHit(t1, ray);
	}
	return getHit(t2, ray);
}


optional<Hit> Sphere::getHit(float t, const Ray& ray) const{
	if(t < ZERO) return {};

	Point hit_point = ray.point(t);
	Unit normal(center, hit_point);
	return Hit{hit_point, normal, color, material, t};

}





