/*
 * Light.h
 *
 *  Created on: Jan 27, 2025
 *      Author: yash
 */

#ifndef LIGHT_H_
#define LIGHT_H_
#include "Point.h"
#include "Color.h"
#include "iostream"


struct Light{

	Point pos;
	Color color;
};

ostream& operator<<(ostream& os, const Light& light);
istream& operator>>(istream& is, Light& light);


#endif /* LIGHT_H_ */
