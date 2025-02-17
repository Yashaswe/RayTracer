/*
 * Shape.cpp
 *
 *  Created on: Feb 12, 2025
 *      Author: yash
 */

#include "Shape.h"
#include "Unit.h"

#include "utils.h"
#include "cmath"

void Shape::readAppearance(istream& is){
	is >> color >> material;
}

istream& operator>>(istream& is, Shape& shape){
	shape.readAppearance(is);
	return is;

}


pair<float, float> Shape::findRoots(float a, float b, float c) const{
	pair<float, float> roots;
	float discriminant = b*b - 4*a*c;
	if(discriminant < 0){
		return {};
	}

	float sqrt_discriminant = sqrt(discriminant);
	float t1 = (-b-sqrt_discriminant)/(2*a);
	float t2 = (-b+sqrt_discriminant)/(2*a);
	roots.first = t1;
	roots.second = t2;
	return {t1, t2};
}
