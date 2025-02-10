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
#include <vector>

using namespace std;

class Scene{
private:
	Color ambientL;
	vector<Light> lights;
	Sphere sphere;
	Camera camera;

public:
	Scene(const string& filename);
	void render(const string& filename) const;
	Color trace(Ray ray) const;
};



#endif /* SCENE_H_ */
