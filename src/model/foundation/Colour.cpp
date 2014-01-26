//
//  Colour.cpp
//  lanaSnake
//
//  Created by Andy Stanton on 02/06/2013.
//  Copyright (c) 2013 Andy Stanton. All rights reserved.
//

#include "Colour.h"

Colour::Colour(int r, int g, int b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

Colour::Colour(float r, float g, float b) {
    this->r = r*255;
    this->g = g*255;
    this->b = b*255;
}

Colour::Colour(int hexValue) {
    r = ((hexValue >> 16) & 0xff);
    g = ((hexValue >> 8) & 0xff);
    b = (hexValue & 0xff);
}

GLfloat* Colour::getColour3fv() {
    GLfloat* colour = new GLfloat[3];
    colour[0] = r/255.f;
    colour[1] = g/255.f;
    colour[2] = b/255.f;
    return colour;
}

float Colour::getR() {
    return r/255.f;
}

float Colour::getG() {
    return g/255.f;
}

float Colour::getB() {
    return b/255.f;
}
