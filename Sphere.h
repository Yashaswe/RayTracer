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
#include "Shape.h"

using namespace std;

class Sphere: public Shape{
private:
	float radius;
public:


	friend ostream& operator<<(ostream& os, const Sphere& sphere);
	friend istream& operator>>(istream& is, Sphere& sphere);


	optional<Hit> intersect(const Ray& ray) const override;
	optional<Hit> getHit(float t, const Ray& ray) const override;
};



#endif /* SPHERE_H_ */
