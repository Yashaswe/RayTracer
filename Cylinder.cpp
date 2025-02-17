/*
 * Cylinder.cpp
 *
 *  Created on: Feb 11, 2025
 *      Author: yash
 */

#include "Cylinder.h"

#include "Vector.h"
#include "Unit.h"
#include "utils.h"

#include <cmath>

ostream& operator<<(ostream& os, const Cylinder& cylinder){
	os << "Cylinder: " << cylinder.center << " " << cylinder.radius << " " << cylinder.height << " " << cylinder.material;
	return os;
}


istream& operator>>(istream& is, Cylinder& cylinder){
	string type;
	is >> type;
	is >> cylinder.center;

	is >> type;
	is >> cylinder.radius;
	is >> cylinder.height;
	is >> type;

	cylinder.readAppearance(is);

	return is;
}


optional<Hit> Cylinder::intersect(const Ray& ray) const{
	Vector D = ray.dir();
	Vector L(center, ray.origin());

	float a = dot(D, D) - D.y()*D.y();
	float b = 2*(dot(D, L) - D.y()*L.y());
	float c = dot(L,L) - L.y()*L.y() - radius*radius;
	pair<float, float> roots = findRoots(a, b, c);
	float t1 = roots.first;
	float t2 = roots.second;
	if(t1 > ZERO){
		return getHit(t1, ray);
	}
	return getHit(t2, ray);
}

optional<Hit> Cylinder::getHit(float t, const Ray& ray) const{
	Vector D = ray.dir();

	float upperLimit = center.y() + height/2;
	float lowerLimit = center.y() - height/2;
	Point hit_point = ray.point(t);
	if(t < ZERO || hit_point.y() > upperLimit || hit_point.y() < lowerLimit){
		return {};
	}

	Point lifted_center(center.x(), hit_point.y(), center.z());
	Unit normal(lifted_center, hit_point);

	return Hit{hit_point, normal, color, material, t};
}




