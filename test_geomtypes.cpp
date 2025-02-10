
#include "test_geomtypes.h"

#include "Point.h"
#include "Vector.h"
#include "Color.h"
#include "utils.h"
#include "Unit.h"
#include "Ray.h"
#include "Scene.h"
#include <cassert>

void test_geomtypes()
{

	//Color

	Color c2(1, 1, 1);

	Scene scene("scene.txt");

	// Point
	Point p1(5, 4, 9);
	Point p2(2, 8, 12);

	assert(Point() == Point(0, 0, 0));

	assert(p1.x() == 5);
	assert(p2.y() == 8);
	assert(p2.z() == 12);

	Point p3(7, 12, 21);

	assert(p1  == Point(5, 4, 9));
	assert(p2  == Point(2, 8, 12));



	// Vector

	Vector v1(2, 5, 8);
	Vector v2(-4, 2, 10);
	Vector v3(1, 1, 1);

	assert(Vector() == Vector(0, 0, 0));

	assert(Vector(p1, p2) == Vector(-3, 4, 3));

	assert(v2.x() == -4);
	assert(v1.y() == 5);
	assert(v1.z() == 8);

	assert(v1.sq_length() == 93);
	assert(v2.sq_length() == 120);

	assert(eq_zero(Vector(0,0,0).length()) - 0);

	assert(dot(v1, v2) == 82);

	assert(v1 + v2 == Vector(-2, 7, 18));
	assert(v1 - v2 == Vector(6, 3, -2));
	assert(-v1 == Vector(-2, -5, -8));
	assert(-v2 == Vector(4, -2, -10));
	assert((5*v1) ==Vector(10, 25, 40));
	assert(v1 * 2 == Vector(4, 10, 16));
	assert(0.1 * v2 == Vector(-0.4, 0.2, 1));

	assert(v1/2 == Vector(1, 2.5, 4));
	assert(v2/5 == Vector(-0.8, 0.4, 2));

	assert(p3 + v1 == Point(9, 17, 29));
	assert(p1 - v2 == Point(9, 2, -1));

	//Unit

	Unit u1(2, 4, 6);
	Unit u2(6, 3, 9);
	Unit u3(5, 0, 0);
	Unit u4(v1);
	Unit u5(p1, p2);
	cout << u5 << endl;
	Unit u6( 1, 2, 3);
	cout << u6 << endl;


	assert(u3 == Unit(3, 0, 0));
	assert(eq_zero(u4.x() == 0.207390338946085));
	assert(eq_zero(u4.y() == 0.518475847365213));
	assert(eq_zero(u4.z() == 0.82956135578434));


	// Ray
	Ray r3(Point(1, 2, 2), Vector(1, 2, 3));
	Ray r1(p1, v1);
	Ray r2(p1, p2);
	cout << r1 << endl;
	cout << r2 << endl;
	assert(r3.point(5) == Point(6, 12, 17));

}
