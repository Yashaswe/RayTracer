/*
 * Material.cpp
 *
 *  Created on: Feb 3, 2025
 *      Author: yash
 */

#include "Material.h"

ostream& operator<<(ostream& os, const Material& material){
	os << "Mat(" << material.ka << "," << material.kd << "," << material.ks << "," << material.n <<")";
	return os;
}

istream& operator>>(istream& is, Material& material){
	// format:   material
    // ambient  0.7
    // diffuse  0.9
    // specular 0.8  phong_size 90
    // refraction 0.8 ior 1.33         // optional

	string type;
	float refraction;
	float ior;

	is >> type;
	is >> type;
	is >> material.ka;
	is >> type;
	is >> material.kd;
	is >> type;
	is >> material.ks;
	is >> type;
	is >> material.n;
	is >> type;
	is >> refraction;
	is >> type;
	is >> ior;

	return is;


}


