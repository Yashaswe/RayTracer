/*
 * Point.cpp
 *
 *  Created on: Jan 26, 2025
 *      Author: yash
 */

#include "Point.h"
#include <iostream>



Point::Point(float x, float y, float z)
	: x_(x), y_(y), z_(z)
{

}

float Point::x() const{
	return x_;
}

float Point::y() const{
	return y_;
}

float Point::z() const{
	return z_;
}

ostream& operator<<(ostream& os, const Point& point){
	os << "Point(" << point.x() << ", " << point.y() << ", " << point.z() << ")";
	return os;
}

istream& operator>>(istream& is, Point& point){
	// format is:      <1, 2, 3>
	char ch;
	float x, y, z;
	is >> ch; // <
	is >> x >> ch; // x,
	is >> y >> ch; // y,
	is >> z ; // z
	is >> ch; // >

	point = Point(x, y, z);
	return is;
}



