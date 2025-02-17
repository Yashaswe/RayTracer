/*
 * Ray.cpp
 *
 *  Created on: Jan 27, 2025
 *      Author: yash
 */

#include "Ray.h"

Ray::Ray( const Point& p,  const Vector& d)
	: p_(p), d_(d)
{

}

Ray::Ray(Point p1, Point p2)
	: Ray(p1, Vector(p1, p2))
{

}

Point Ray::origin() const{
	return p_;
}

Vector Ray::dir() const{
	return d_;
}

Point Ray::point(float t) const{
	Point result = p_ + t * d_;
	return result;
}

ostream& operator<<(ostream& os, const Ray& ray){
	os << "Ray: " << ray.origin() << "," << ray.dir();
	return os;
}




