/*
 * Hit.h
 *
 *  Created on: Feb 3, 2025
 *      Author: yash
 */

#ifndef HIT_H_
#define HIT_H_

#include "Point.h"
#include "Vector.h"
#include "Color.h"
#include "Material.h"


struct Hit{
	Point intersection;
	Vector normal;
	Color color;
	Material material;
	float t;

	Hit(const Point& i, const Vector& normal, const Color& color, const Material& mat, float t)
		: intersection(i), normal(normal), color(color), material(mat), t(t)
	{

	}

};


#endif /* HIT_H_ */
