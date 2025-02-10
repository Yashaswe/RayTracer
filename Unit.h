/*
 * Unit.h
 *
 *  Created on: Jan 27, 2025
 *      Author: yash
 */

#ifndef UNIT_H_
#define UNIT_H_

#include "Vector.h"
#include "iostream"


class Unit: public Vector{
private:


public:

	Unit(float x, float y, float z);
	Unit(const Vector& v);
	Unit(const Point& p1, const Point& p2);



};

ostream& operator<<(ostream& os, const Unit& u);


#endif /* UNIT_H_ */
