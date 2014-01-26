//
//  Pickup.h
//  lanaSnake
//
//  Created by Andy Stanton on 02/06/2013.
//  Copyright (c) 2013 Andy Stanton. All rights reserved.
//

#ifndef __lanaSnake__Pickup__
#define __lanaSnake__Pickup__

#include <vector>
#include "Entity.h"
#include "../foundation/Colour.h"
#include "Collidable.h"
#include "Drawable.h"

using namespace std;

class Pickup: public Collidable, public Drawable, public Entity {
private:
    vector<Segment*> segments;
public:
	Pickup(Vec2d* coords, Colour* colour);
    Colour* getColour();
    bool collidesWith(Vec2d* coords);
    vector<Segment*>* getMesh();    
};

#endif /* defined(__lanaSnake__Pickup__) */
