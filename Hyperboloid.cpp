/*
 * Hyperboloid.cpp
 *
 *  Created on: Feb 13, 2025
 *      Author: yash
 */

#include "Hyperboloid.h"
#include "Unit.h"
#include "utils.h"


ostream& operator<<(ostream& os, const Hyperboloid& hyperboloid){
	os << "Hyperboloid: " << hyperboloid.center << " " << hyperboloid.radiiX << " " << hyperboloid.radiiZ << " " << hyperboloid.upperHeight << " " << hyperboloid.lowerHeight << " " << hyperboloid.color << " " << hyperboloid.material;
	return os;
}
istream& operator>>(istream& is, Hyperboloid& hyperboloid){


	string type;
	is >> type;

	is >> hyperboloid.center;

	is >> type;
	is >> hyperboloid.radiiX >> hyperboloid.radiiZ >> hyperboloid.upperHeight >> hyperboloid.lowerHeight;

	is >> type;
	//	cout << type << endl;
	hyperboloid.readAppearance(is);

	return is;
}

optional<Hit> Hyperboloid::intersect(const Ray& ray) const{
	float skewX = (ray.dir().x())/(radiiX);
	float radiiY = max(upperHeight, lowerHeight);
	float skewY = (ray.dir().y())/(radiiY);
	float skewZ = (ray.dir().z())/(radiiZ);
	Vector D(skewX, skewY, skewZ);

	//	Vector L(center, ray.origin());
	Vector L((ray.origin().x() - center.x()) / (radiiX),
			(ray.origin().y() - center.y()) / (radiiY),
			(ray.origin().z() - center.z()) / (radiiZ));


	float a = D.x()*D.x() - D.y()*D.y() + D.z()*D.z();
	float b = 2*(D.x()*L.x() - D.y()*L.y() + D.z()*L.z());
	float c = L.x()*L.x() - L.y()*L.y() + L.z()*L.z() - 1;

	pair<float, float> roots = findRoots(a, b, c);
	float t1 = roots.first;
	float t2 = roots.second;
	optional<Hit> hit = getHit(t1, ray);
	if(hit){
		return hit;
	}
	return getHit(t2, ray);
}

optional<Hit> Hyperboloid::getHit(float t, const Ray& ray) const{

	Point hit_point = ray.point(t);
	if(t < ZERO || hit_point.y() > upperHeight + center.y() || hit_point.y() < center.y() - lowerHeight ){
		return {};
	}

	float H = std::max(upperHeight, lowerHeight);
	float nx = 2 * (hit_point.x() - center.x()) / (radiiX * radiiX);
	float ny = -2 * (hit_point.y() - center.y()) / (H * H);
	float nz = 2 * (hit_point.z() - center.z()) / (radiiZ * radiiZ);
	Unit normal(nx, ny, nz);


	return Hit{hit_point, normal, color, material, t};
}





