/*
 * Point.h
 *
 *  Created on: Jan 26, 2025
 *      Author: yash
 */

#ifndef POINT_H_
#define POINT_H_

#include <iostream>
using namespace std;


class Point{
private:
	float x_= 0;
	float y_= 0;
	float z_= 0;

public:
	Point() = default;
	Point(float x, float y, float z);

	float x() const;
	float y() const;
	float z() const;

	bool operator==(const Point& other) const = default;

};

ostream& operator<<(ostream& os, const Point& point);
istream& operator>>(istream& is, Point& point);



#endif /* POINT_H_ */
