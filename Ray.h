/*
 * Ray.h
 *
 *  Created on: Jan 27, 2025
 *      Author: yash
 */

#ifndef RAY_H_
#define RAY_H_
#include "Point.h"
#include "Vector.h"
#include "iostream"


class Ray{

private:
	Point p_;
	Vector d_;

public:
	Ray(const Point& p,  const Vector& d);
	Ray(Point p1,  Point p2);

	Point origin() const;
	Vector dir() const;

	Point point(float t);



};

ostream& operator<<(ostream& os, const Ray& ray);


#endif /* RAY_H_ */
