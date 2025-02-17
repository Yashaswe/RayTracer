/*
 * Scene.h
 *
 *  Created on: Jan 27, 2025
 *      Author: yash
 */



#ifndef SCENE_H_
#define SCENE_H_
#include <fstream>
#include <iostream>
#include <string>

#include "Camera.h"
#include "Light.h"
#include "Sphere.h"
#include "Cylinder.h"
#include "Hyperboloid.h"
#include "Shape.h"
#include <vector>
#include <cfloat>

using namespace std;

class Scene{
private:
	Color ambientL;
	vector<Light> lights;

	vector<Shape*> shapes;
	Camera camera;

public:
	Scene(const string& filename);
	void render(const string& filename) const;
	Color trace(Ray ray) const;
	optional<Hit> findClosestHit(const Ray& ray, const vector<Shape*>& shapes, float maxDist = FLT_MAX) const;

	// recursive Ray Tracing
	Color trace(const Ray& ray, int depth) const;
};



#endif /* SCENE_H_ */
