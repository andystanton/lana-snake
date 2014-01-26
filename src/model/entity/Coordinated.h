//
//  Coordinated.h
//  lanaSnake
//
//  Created by Andy Stanton on 19/06/2013.
//  Copyright (c) 2013 Andy Stanton. All rights reserved.
//

#ifndef lanaSnake_Coordinated_h
#define lanaSnake_Coordinated_h

#include "../foundation/Vec2d.h"

class Coordinated {
public:
    Coordinated(){}
    virtual ~Coordinated(){}

    virtual Vec2d* getCoords() = 0;
    virtual void setCoords(Vec2d* coords) = 0;
    virtual void setCoords(GLint x, GLint y) = 0;
};

#endif
