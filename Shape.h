/*
 * Shape.h
 *
 *  Created on: Feb 12, 2025
 *      Author: yash
 */

#ifndef SHAPE_H_
#define SHAPE_H_

#include "Point.h"
#include "Material.h"
#include "Color.h"
#include "Ray.h"
#include "Hit.h"

#include <iostream>
#include <optional>

class Shape{
private:

protected:
	Point center;
	Material material;
	Color color;

public:
	virtual optional<Hit> intersect(const Ray& ray) const = 0;
	void readAppearance(istream& is);
	pair<float, float> findRoots(float a, float b, float c) const;
	virtual optional<Hit> getHit(float t, const Ray& ray) const = 0;
	friend istream& operator>>(istream& is, Shape& shape);
};



#endif /* SHAPE_H_ */
