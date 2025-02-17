/*
 * Camera.h
 *
 *  Created on: Feb 3, 2025
 *      Author: yash
 */

#ifndef CAMERA_H_
#define CAMERA_H_

#include "Point.h"
#include <iostream>
using namespace std;

struct Camera{
	Point pos;
	float view_size;
	int samples;
	int depth;

	friend ostream& operator<<(ostream& os, const Camera& camera);
	friend istream& operator>>(istream& is, Camera& camera);
};



#endif /* CAMERA_H_ */
