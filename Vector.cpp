/*
 * Vector.cpp
 *
 *  Created on: Jan 26, 2025
 *      Author: yash
 */

#include "Vector.h"
#include <cmath>

Vector::Vector(float x, float y, float z):
x_(x), y_(y), z_(z){

}

Vector::Vector(const Point& p1, const Point& p2)
	: Vector(p2.x() - p1.x(),  p2.y() - p1.y(), p2.z() - p1.z())
{

}

float Vector::x() const{
	return x_;
}

float Vector::y() const{
	return y_;
}

float Vector::z() const{
	return z_;
}

float Vector::sq_length() const{
	return x_*x_ + y_*y_ + z_*z_;
}

float Vector::length() const{
	return sqrt(sq_length());
}

float dot(const Vector& v1, const Vector& v2){
	float dot_product = v1.x() *v2.x() + v1.y()*v2.y() + v1.z()*v2.z();
	return dot_product;
}

Vector operator+(const Vector& v1, const Vector& v2){
	float x = v1.x() + v2.x();
	float y = v1.y() + v2.y();
	float z = v1.z() + v2.z();
	Vector vector(x, y, z);
	return vector;
}

Vector Vector::operator-(const Vector& other) const{
	float x = x_ - other.x();
	float y = y_ - other.y();
	float z = z_ - other.z();
	Vector vector(x, y, z);
	return vector;
}

//Vector Vector::operator-(){
//	float x = -x;
//	float y = -y;
//	float z = -z;
//	Vector vector(x, y, z);
//	return vector;
//}

Vector operator-(const Vector& v){
	float x = -v.x();
	float y = -v.y();
	float z = -v.z();
	Vector vector(x, y, z);
	return vector;
}

Vector Vector::operator*(float scalar) const{
	float x = x_*scalar;
	float y = y_*scalar;
	float z = z_*scalar;
	Vector vector(x, y, z);
	return vector;

}

Vector operator*(float scalar, Vector& v){
	float x = scalar*v.x();
	float y = scalar*v.y();
	float z = scalar*v.z();
	Vector vector(x, y, z);
	return vector;

}

Vector operator/(const Vector& v, float scalar){
	float x = v.x()/scalar;
	float y = v.y()/scalar;
	float z = v.z()/scalar;
	Vector vector(x, y, z);
	return vector;
}

Point operator+(const Point& p,  const Vector& v){
	float x = p.x() + v.x();
	float y = p.y() + v.y();
	float z = p.z() + v.z();
	Point point(x, y, z);
	return point;
}

Point operator-(const Point& p, const Vector& v){
	float x = p.x() - v.x();
	float y = p.y() - v.y();
	float z = p.z() - v.z();
	Point point(x, y, z);
	return point;
}

ostream& operator<<(ostream& os, const Vector& v){
	os << "Vector(" << v.x() << ", " << v.y() << ", " << v.z() << ")";
	return os;
}

