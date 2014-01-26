//
//  Segment.h
//  lanaSnake
//
//  Created by Andy Stanton on 19/06/2013.
//  Copyright (c) 2013 Andy Stanton. All rights reserved.
//

#ifndef __lanaSnake__Segment__
#define __lanaSnake__Segment__

#include "../foundation/Vec2d.h"
#include "../foundation/Colour.h"

class Segment {
private:
    Colour* colour;
    Vec2d* relativeCoord;
public:
    Segment(Vec2d*, Colour*);
    Vec2d* getRelativeCoord();
    void setRelativeCoord(Vec2d* relativeCoord);
    Colour* getColour();
};

#endif /* defined(__lanaSnake__Segment__) */
