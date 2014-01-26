//
//  Gameplay.h
//  lanaSnake
//
//  Created by Andy Stanton on 19/06/2013.
//  Copyright (c) 2013 Andy Stanton. All rights reserved.
//

#ifndef __lanaSnake__Gameplay__
#define __lanaSnake__Gameplay__

#include "GLFW/glfw3.h"
#include "Primitive.h"
#include "../model/entity/Drawable.h"

class Gameplay {
public:
    static void drawPause(GLfloat width);
    static void draw(Drawable*);
    static void draw(Drawable*, GLint);
};

#endif /* defined(__lanaSnake__Gameplay__) */
