/*
 * Camera.cpp
 *
 *  Created on: Feb 3, 2025
 *      Author: yash
 */

#include "Camera.h"

ostream& operator<<(ostream& os, const Camera& camera){
	os << "Camera: " << camera.pos << " " << camera.view_size << " cm " << camera.samples << "px";
	return os;
}

istream& operator>>(istream& is, Camera& camera){
	string type;
	float num;
	Point point;
	is >> type;
	is >> camera.pos;
	is >> type;
	is >> camera.view_size;
	is >> type;
	is >> camera.samples;
	is >> type;
	is >> camera.depth >> type >> point >> type >> point;
	return is;

}



