#include "Image.h"

#include "Color.h"

#include <algorithm>
#include <string>
#include <ostream>
#include <fstream>
#include <cassert>

using uchar = unsigned char;
using namespace std;

void Image::setPixel(int w, int h, const Color& c) const
{
	image[h][w] = c;
}


Color Image::getPixel(int w, int h) const
{
	return image[h][w];
}



Image::Image(int width, int height)
:
				  width(width),
				  height(height)
{
	makeCanvas();
	clear();
}


Image::~Image()
{
	destroyCanvas();
}


void Image::clear()
{
	//set the whole canvas to black
	fillRegion(0, 0, width, height, BLACK);
}


void Image::saveImage(const std::string& file_name) const
{
	std::ofstream ofs(file_name.c_str(), std::ios::binary);

	// write the header information
	ofs << "P6" << std::endl;
	ofs << width << "\t" << height << std::endl;
	ofs << 255 << std::endl;

	// save the image data one row at a time
	for(int y = 0; y < height; ++y) {
		for(int x = 0; x < width; ++x) {
			Color c = getPixel(x, y);
			ofs << uchar(255*c.r()) << uchar(255*c.g()) << uchar(255*c.b());
		}
	}
}


void Image::fillRegion(int w0, int h0, int width, int height, const Color& c) const
{
	int w1 = w0 + width;
	int h1 = h0 + height;

	for(int y = h0; y < h1; ++y) {
		for(int x = w0; x < w1; ++x) {
			setPixel(x, y, c);
		}
	}
}


void Image::makeCanvas()
{
	image = new Color*[height];
	for(int h = 0; h < height; ++h) {
		image[h] = new Color[width];
	}
}


void Image::destroyCanvas() const
{
	for(int h = 0; h < height; ++h) {
		delete [] image[h];
	}
	delete [] image;
}
