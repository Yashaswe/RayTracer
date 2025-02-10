/*
 * Sphere.cpp
 *
 *  Created on: Feb 3, 2025
 *      Author: yash
 */

#include "Sphere.h"
#include "Vector.h"
#include "Unit.h"
#include <cmath>

ostream& operator<<(ostream& os, const Sphere& sphere){
	os << "Sphere: " << sphere.center << " " << sphere.radius << sphere.material;
	return os;
}
istream& operator>>(istream& is, Sphere& sphere){
	string type;
	is >> type;
	is >> sphere.center;

	is >> type;
	is >> sphere.radius;
	is >> type;

	is >> sphere.color;
	is >> sphere.material;
	return is;
}

optional<Hit> Sphere::intersect(const Ray& ray) const{
	Vector D = ray.dir();
	Vector L(center, ray.origin());

	float a = dot(D, D);
	float b = 2*dot(D, L);
	float c = dot(L,L) - radius*radius;

	float discriminant = b*b - 4*a*c;
	if(discriminant<0){
		return {};
	}
	else{
		float sqrt_discriminant = sqrt(discriminant);
		float t1 = (-b-sqrt_discriminant)/(2*a);
		float t2 = (-b+sqrt_discriminant)/(2*a);
		float t = -1;
		if(t1>0){
			t = t1;
		}
		else if(t2 >0){
			t = t2;
		}
		if(t < 0){
			return {};
		}
		Point hit_point = ray.origin() + ray.dir()*t;
		Unit normal(center, hit_point);
		return Hit{hit_point, normal, color, material, t};

	}


}




