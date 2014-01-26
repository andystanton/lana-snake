//
//  snake.h
//  snake
//
//  Created by Andy Stanton on 23/05/2013.
//  Copyright (c) 2013 Andy Stanton. All rights reserved.
//

#ifndef __snake__snake__
#define __snake__snake__

#include <vector>
#include <deque>
#include "Entity.h"
#include "../foundation/Colour.h"
#include "Collidable.h"
#include "Drawable.h"
#include "Segment.h"
#include "../../common/Logger.h"
#include "../../static/palette.h"

using namespace std;

class Snake: public Entity, public Collidable, public Drawable {
public:
    static const int MIN_LENGTH = 2;
    static const int MAX_LENGTH = MIN_LENGTH + 100;
    
    Snake(Vec2d*);
    vector<Segment*>* getMesh();
    bool incrementLength(Colour*);
    void resetSnake();
    Vec2d* getDirection();
    bool update();
    void addDirectionToQueue(Vec2d*);
    bool collidesWith(Vec2d* coords);
    void logState();
    
private:
    static Logger* log;
    static Vec2d* BASE_DIR;
    deque<Vec2d*> directionQueue;
    vector<Segment*>* segments;
    bool changeDirection();
    bool changeDirection(Vec2d*);
    Vec2d* direction;
    bool live;
};

#endif /* defined(__snake__snake__) */
