/*
 *  CPixel.cpp
 *  P_Bitmap
 *
 *  Created by Le Gal on 24/10/06.
 *  Copyright 2006 __MyCompanyName__. All rights reserved.
 *
 */

#include "CPixel.h"

CPixel::CPixel(int r, int g, int b){
	red   = r;
	green = g;
	blue  = b;
}

CPixel::CPixel(){
	red   = 0;
	green = 0;
	blue  = 0;
}

int CPixel::Red(){
	return red;
}

void CPixel::Red(int r){
	red = (r>255)?255:r;
	red = (red>=0)?red:0;
}

int CPixel::Green(){
	return green;
}

void CPixel::Green(int g){
	green = (g>255)?255:g;
	green = (green>=0)?green:0;
}

int CPixel::Blue(){
	return blue;
}

void CPixel::Blue(int b){
	blue = (b>255)?255:b;
	blue = (blue>=0)?blue:0;
}

void CPixel::RGB(int r, int g, int b){
	Red(r);
	Green(g);
	Blue(b);
}

void CPixel::RGB(int r, int g, int b, int alpha) {
	Red(compute_component(alpha, Red(), r));
	Green(compute_component(alpha, Green(), g));
	Blue(compute_component(alpha, Blue(), b));
}

int CPixel::compute_component(int alpha, int previous_color, int wished_color) {
    int pix_comp = ( (100 - alpha)*previous_color + alpha*wished_color )/100;

    if( pix_comp <= 255 ) {
        return pix_comp;
    }
    else {
        std::cerr << "computed transparency out of range" << std::endl;
        return previous_color;
    }
}
