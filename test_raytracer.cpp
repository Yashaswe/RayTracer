
#include "test_raytracer.h"
#include "Scene.h"

#include <string>
#include <vector>
using namespace std;

void test_raytracer(const string& dir, const vector<string>& namesList)
{
	for ( const string& name : namesList) {
		Scene(dir+"/"+name+".txt").render(dir+"/"+name+".ppm");
	}
}
