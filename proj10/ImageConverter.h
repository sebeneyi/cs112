/*
 * ImageConverter.h declares a class for
 *  various image conversion operations.
 *
 *  Author:  Joel Adams, CS112 @ Calvin College.
 *  Created: March 2015
 *  Revised: November 2016.
 *
 * Student: Sebene Yi (ssy3), for CS 112 at Calvin College (proj10)
 * Date: May 06, 2019
 */

#ifndef IMAGECONVERTER_H_
#define IMAGECONVERTER_H_

#include <tsgl.h>     // Canvas, ColorInt, etc.
#include <iostream>   // cout, cerr, ...
#include <string>     // string
#include <omp.h>      // OpenMP functions

using namespace tsgl;
using namespace std;

class ImageConverter {
public:
	ImageConverter(const std::string& imageFileName, int width, int height);
	~ImageConverter();

	void invertImage();
	void invertImage2();
	void invertImage3();

	void makeSepia();
	void blurImage(int numPixels);

private:
    Canvas      myCanvas1;
    string      myImageFileName;
    int         myWidth;
    int         myHeight;
};


#endif /* IMAGECONVERTER_H_ */
