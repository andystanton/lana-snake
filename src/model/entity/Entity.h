//
//  Entity.h
//  lanaSnake
//
//  Created by Andy Stanton on 02/06/2013.
//  Copyright (c) 2013 Andy Stanton. All rights reserved.
//

#ifndef __lanaSnake__Entity__
#define __lanaSnake__Entity__

#include <GLFW/glfw3.h>
#include "../foundation/Vec2d.h"
#include "Coordinated.h"

using namespace std;

class Entity: public virtual Coordinated {
protected:
    Vec2d* coords;
    
public:
    Entity();
    Entity(Vec2d*);
    Vec2d* getCoords();
    void setCoords(Vec2d* coords);
    void setCoords(GLint x, GLint y);
    void offsetX(GLint);
    void offsetY(GLint);
};

#endif /* defined(__lanaSnake__Entity__) */
