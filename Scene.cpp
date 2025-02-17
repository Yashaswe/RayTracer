/*
 * Scene.cpp
 *
 *  Created on: Jan 27, 2025
 *      Author: yash
 */

#include "Scene.h"
#include "Color.h"
#include "Point.h"
#include "Light.h"
#include "Vector.h"
#include "Cone.h"
#include "Unit.h"
#include <cmath>
#include "Image.h"

using namespace std;


Scene::Scene(const string& filename){
	ifstream ifs(filename);

	if (!ifs) {
		cerr << "Error: Failed to open file "<< filename  << endl;
		return;
	}

	cout << "Scene:" << endl;
	string type;



	while(ifs >> type){
		if(type == "light_ambient"){
			ifs >> ambientL;
			cout << "Ambient:" << ambientL << endl;
		}
		else if(type == "light_source"){
			Light light;

			ifs >> light;
			lights.push_back(light);
			cout << light << endl;
		}
		else if(type == "sphere"){
			Sphere* sphere = new Sphere();
			ifs >> *sphere;
			shapes.push_back(sphere);
			cout << *sphere << endl;
		}
		else if(type == "camera"){

			ifs >> camera;
			cout << camera << endl;
		}
		else if(type == "cylinder"){
			Cylinder* cylinder = new Cylinder();
			ifs >> *cylinder;
			shapes.push_back(cylinder);
			cout << *cylinder << endl;

		}
		else if(type == "ellipsoid"){

		}
		else if(type =="cone"){
			Cone* cone = new Cone();
			ifs >> *cone;
			shapes.push_back(cone);
			cout << *cone << endl;

		}
		else if(type =="hyperboloid"){
			Hyperboloid* hyperboloid = new Hyperboloid();
			ifs >> *hyperboloid;
			shapes.push_back(hyperboloid);
			cout << *hyperboloid << endl;


		}
		else if(type =="plane"){

		}
	}
}


void Scene::render(const string& filename) const{

	float halfView = camera.view_size*0.5;
	float viewToSample = camera.view_size/(camera.samples-1);


	int width = camera.samples;
	Image canvas(width, width);
	for(int x = 0; x < width; x++){
		for(int y = 0; y < width; y++){

			float i = (viewToSample)*x - halfView;
			float j = -(viewToSample)*y + halfView;

			Ray ray = Ray(camera.pos, Point(i, j, 0));
			Color pixelColor = trace(ray, camera.depth);
			canvas.setPixel(x ,y , pixelColor);
		}
	}
	canvas.saveImage(filename);
}

//
//Color Scene::trace(Ray ray) const{
//	Color color(0,0,0);
//	int count = 0;
//	optional<Hit> hit = findClosestHit(ray, spheres);
//
//	if(!hit){
//		return color;
//	}
//	Color ambient = hit->material.ka * hit->color * ambientL;
//	color=color + ambient;
//
//	for(const Light& light:lights){
//
//		//diffuse
//		Unit L(hit->intersection, light.pos);
//		Unit N = hit->normal;
//		float NdotL = dot(N, L);
//
//		Color diffuse = hit->material.kd * light.color * hit->color * max(0.0f, NdotL);
//
//		//specular
//		Unit viewDir(hit->intersection, camera.pos);
//
//		Unit R = 2*N*NdotL - L;
//
//		float RdotV = max(0.0f, dot(R, viewDir));
//		float specularFactor = pow(RdotV, hit->material.n);
//
//		Color specular = hit->material.ks * light.color * hit->color * specularFactor;
//		color = color + diffuse + specular;
//	}
//	return color;
//}

//Recursive Ray Tracing
Color Scene::trace(const Ray& ray, int depth) const{
	Color color(0,0,0);
	if(depth <= 0){
		return color;
	}


	optional<Hit> hit = findClosestHit(ray, shapes);

	if(!hit){
		return color;
	}


	Color ambient = hit->material.ka * hit->color * ambientL;


	color = color + ambient;
	Unit N = hit->normal;
	const Point& intersection = hit->intersection;
	Unit V = -ray.dir();
	float NdotV = dot(N, V);
	if(NdotV < 0){
		return color;
	}

	for(const Light& light:lights){
		Vector v(intersection, light.pos);
		float dist = v.length();
		Ray lightRay = Ray(intersection, light.pos);
		optional<Hit> obstacle = findClosestHit(lightRay, shapes, dist);
		if(obstacle){
			continue;
		}

		//diffuse
		Unit L(intersection, light.pos);

		float NdotL = dot(N, L);
		if(NdotL > 0){

			Color diffuse = hit->material.kd * light.color * hit->color * max(0.0f, NdotL);

			//specular



			Unit R = 2*N*NdotL - L;

			float RdotV = max(0.0f, dot(R, V));
			float specularFactor = pow(RdotV, hit->material.n);

			Color specular = hit->material.ks * light.color * hit->color * specularFactor;
			color = color + diffuse + specular;

		}

	}
	// calculating the direction of reflection



	Unit Vr = 2*N*NdotV - V;
	Ray Ireflection(intersection, Vr);
	Color reflection = hit->material.ks*trace(Ireflection, depth-1);
	//		// calculating the direction of refraction
	//		Vector refractionV = (V-N)/(hit->material.ior)+N;
	//
	//		Ray Irefraction(intersection, refractionV);
	//		Color refraction = hit->material.kt*trace(Irefraction, depth-1);
	return color + reflection;
}


optional<Hit> Scene::findClosestHit(const Ray& ray, const vector<Shape*>& shapes, float maxDist) const{
	optional<Hit> closestHit;
	float minDist = maxDist;
	for(const Shape* shape: shapes){

		optional<Hit> hit = shape->intersect(ray);
		if(hit && hit->t < minDist){
			minDist = hit->t;
			closestHit = hit;
		}

	}
	return closestHit;
}


