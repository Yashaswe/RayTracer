/*
 * Cylinder.h
 *
 *  Created on: Feb 11, 2025
 *      Author: yash
 */

#ifndef CYLINDER_H_
#define CYLINDER_H_

#include <optional>

#include "Point.h"
#include "Hit.h"
#include "Ray.h"
#include "Shape.h"

class Cylinder: public Shape{
private:
	float radius;
public:
	float height;


	friend ostream& operator<<(ostream& os, const Cylinder& cylinder);

	friend istream& operator>>(istream& is, Cylinder& cylinder);
	optional<Hit> getHit(float t, const Ray& ray) const override;

	optional<Hit> intersect(const Ray& ray) const override;

};





#endif /* CYLINDER_H_ */
