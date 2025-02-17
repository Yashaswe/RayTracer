/*
 * Cone.h
 *
 *  Created on: Feb 13, 2025
 *      Author: yash
 */

#ifndef CONE_H_
#define CONE_H_

#include "Shape.h"

class Cone : public Shape {
private:
    float radiiX;
    float radiiZ;
    float height;

public:
    friend ostream& operator<<(ostream& os, const Cone& cone);
    friend istream& operator>>(istream& is, Cone& cone);

    optional<Hit> getHit(float t, const Ray& ray) const override;
    optional<Hit> intersect(const Ray& ray) const override;
};



#endif /* CONE_H_ */
