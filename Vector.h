/*
 * Vector.h
 *
 *  Created on: Jan 26, 2025
 *      Author: yash
 */

#ifndef VECTOR_H_
#define VECTOR_H_

#include "Point.h"
#include "iostream"


class Vector{
private:
	float x_ = 0;
	float y_ = 0;
	float z_ = 0;

public:
	Vector() = default;
	Vector(float x, float y, float z);
	Vector(const Point& p1, const Point& p2);

	float x() const;
	float y() const;
	float z() const;

	float sq_length() const;
	float length() const;

	Vector operator-(const Vector& other) const;
//	Vector operator-();
	Vector operator*(float scalar) const;
	bool operator==(const Vector& other) const = default;


};

float dot(const Vector& v1, const Vector& v2);

Vector operator+(const Vector& v1, const Vector& v2);
Vector operator-(const Vector& v);
Vector operator*(float scalar, Vector& v);
Vector operator/(const Vector& v, float scalar);

Point operator+(const Point& p,  const Vector& v);
Point operator-(const Point& p, const Vector& v);

ostream& operator<<(ostream& os, const Vector& v);

#endif /* VECTOR_H_ */
