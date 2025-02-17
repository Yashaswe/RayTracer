/*
 * Hyperboloid.h
 *
 *  Created on: Feb 13, 2025
 *      Author: yash
 */

#ifndef HYPERBOLOID_H_
#define HYPERBOLOID_H_

#include "Shape.h"

class Hyperboloid: public Shape{
private:
	float radiiX;
	float radiiZ;
	float upperHeight;
	float lowerHeight;

public:
	friend ostream& operator<<(ostream& os, const Hyperboloid& hyperboloid);
	friend istream& operator>>(istream& is, Hyperboloid& hyperboloid);

	optional<Hit> getHit(float t, const Ray& ray) const override;
	optional<Hit> intersect(const Ray& ray) const override;

};


#endif /* HYPERBOLOID_H_ */
