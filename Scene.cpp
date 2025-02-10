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
#include "Canvas.h"
#include "Vector.h"
#include "Unit.h"
#include <cmath>


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

			ifs >> sphere;
			cout << sphere << endl;

		}
		else if(type == "camera"){

			ifs >> camera;
			cout << camera << endl;
		}
		else if(type == "cylinder"){

		}
		else if(type == "ellipsoid"){

		}
		else if(type =="cone"){

		}
		else if(type =="hyperboloid"){

		}
		else if(type =="plane"){

		}
	}
}


void Scene::render(const string& filename) const{

	float halfView = camera.view_size*0.5;
	float viewToSample = camera.view_size/(camera.samples-1);


	int width = camera.samples;
	Canvas canvas(width, width);
	for(int x = 0; x < width; x++){
		for(int y = 0; y < width; y++){

			float i = (viewToSample)*x - halfView;
			float j = -(viewToSample)*y + halfView;

			Ray ray = Ray(camera.pos, Point(i, j, 0));
			Color pixelColor = trace(ray);
			canvas.setPixel(x ,y , pixelColor);
		}
	}
	canvas.saveImage(filename);

}

Color Scene::trace(Ray ray) const{
	optional<Hit> hit = sphere.intersect(ray);
	Color color(0,0,0);

	if(!hit){
		return color;
	}

	Color ambient = hit->material.ka * sphere.color * ambientL;
	color=color + ambient;

	for(const Light& light:lights){

		//diffuse
		Unit L(hit->intersection, light.pos);
		Unit N = hit->normal;
		float NdotL = dot(N, L);

		Color diffuse = hit->material.kd * light.color * sphere.color * max(0.0f, NdotL);

		//specular
		Unit viewDir(hit->intersection, camera.pos);

		Unit R = 2*N*NdotL - L;

		float RdotV = max(0.0f, dot(R, viewDir));
		float specularFactor = pow(RdotV, hit->material.n);

		Color specular = hit->material.ks * light.color * sphere.color * specularFactor;
		color = color + diffuse + specular;
	}

	return color;
}
