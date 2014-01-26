//
//  Drawable.h
//  lanaSnake
//
//  Created by Andy Stanton on 19/06/2013.
//  Copyright (c) 2013 Andy Stanton. All rights reserved.
//

#ifndef lanaSnake_Drawable_h
#define lanaSnake_Drawable_h

#include <vector>
#include "Coordinated.h"
#include "Segment.h"
#include "../foundation/Vec2d.h"

class Drawable: public virtual Coordinated {
public:
    Drawable(){}
    virtual ~Drawable(){}
    
    virtual vector<Segment*>* getMesh() = 0;
};

#endif
