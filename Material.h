/*
 * Material.h
 *
 *  Created on: Feb 3, 2025
 *      Author: yash
 */

#ifndef MATERIAL_H_
#define MATERIAL_H_

#include <iostream>
using namespace std;

struct Material{
	float ka, kd, ks, kt, n, ior;

	friend ostream& operator<<(ostream& os, const Material& material);
	friend istream& operator>>(istream& is, Material& material);
};




#endif /* MATERIAL_H_ */
