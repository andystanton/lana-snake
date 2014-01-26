//
//  World.h
//  lanaSnake
//
//  Created by Andy Stanton on 04/06/2013.
//  Copyright (c) 2013 Andy Stanton. All rights reserved.
//

#ifndef __lanaSnake__World__
#define __lanaSnake__World__

#include <vector>
#include "Entity.h"
#include "Collidable.h"



class World: public Entity, public Collidable {
private:
    Vec2d* bounds;
    Vec2d* centre;
    vector<Entity*> entities;
public:
    World(GLint xBound, GLint yBound);
    
    GLint getXBound();
    GLint getYBound();
    
    Vec2d* getOrigin();
    
    bool collidesWith(Vec2d* coords);
};

#endif /* defined(__lanaSnake__World__) */
