//
//  Primitive.h
//  lanaSnake
//
//  Created by Andy Stanton on 06/06/2013.
//  Copyright (c) 2013 Andy Stanton. All rights reserved.
//

#ifndef __lanaSnake__Primitive__
#define __lanaSnake__Primitive__

#include "GLFW/glfw3.h"
#include "../model/foundation/Vec2d.h"

class Primitive {
public:
    static const GLint DEFAULT_PIXEL_SIZE = 20;
    static void drawSquare();
    static void drawSquare(GLfloat pixelSize);
    static void translate(Vec2d*);
    static void translate(Vec2d*, GLfloat pixelSize);
};

#endif /* defined(__lanaSnake__Primitive__) */
