/*
 * Sphere.h
 *
 *  Created on: Feb 3, 2025
 *      Author: yash
 */

#ifndef SPHERE_H_
#define SPHERE_H_

#include <iostream>
#include <optional>
#include "Point.h"
#include "Vector.h"
#include "Color.h"
#include "Ray.h"
#include "Material.h"
#include "Hit.h"

using namespace std;

class Sphere{
private:
public:

	Point center;
	Material material;
	float radius;
	Color color;
	optional<Hit> intersect(const Ray& ray) const;
	friend ostream& operator<<(ostream& os, const Sphere& sphere);
	friend istream& operator>>(istream& is, Sphere& sphere);
};



#endif /* SPHERE_H_ */
