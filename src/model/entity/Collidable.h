//
//  Collidable.h
//  lanaSnake
//
//  Created by Andy Stanton on 06/06/2013.
//  Copyright (c) 2013 Andy Stanton. All rights reserved.
//

#ifndef lanaSnake_Collidable_h
#define lanaSnake_Collidable_h

#include "../foundation/Vec2d.h"
#include "Drawable.h"

class Collidable: public virtual Coordinated {
public:
    Collidable(){}
    virtual ~Collidable(){}
    
    virtual bool collidesWith(Vec2d* coords) = 0;
};

#endif
