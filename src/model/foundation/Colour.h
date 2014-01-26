//
//  Colour.h
//  lanaSnake
//
//  Created by Andy Stanton on 02/06/2013.
//  Copyright (c) 2013 Andy Stanton. All rights reserved.
//

#ifndef __lanaSnake__Colour__
#define __lanaSnake__Colour__

#include <iostream>
#include <string>
#include <sstream>
#include <GLFW/glfw3.h>

using namespace std;

class Colour {
private:
    int r, g, b;
public:
    Colour(int r, int g, int b);
    Colour(float r, float g, float b);
    Colour(int hex);
    
    float getR();
    float getG();
    float getB();
    
    GLfloat* getColour3fv();
};

#endif /* defined(__lanaSnake__Colour__) */
