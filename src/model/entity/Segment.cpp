//
//  Segment.cpp
//  lanaSnake
//
//  Created by Andy Stanton on 19/06/2013.
//  Copyright (c) 2013 Andy Stanton. All rights reserved.
//

#include "Segment.h"

Segment::Segment(Vec2d* relativeCoord, Colour* colour) {
    this->relativeCoord = relativeCoord;
    this->colour = colour;
}

Vec2d* Segment::getRelativeCoord() {
    return relativeCoord;
}

void Segment::setRelativeCoord(Vec2d* relativeCoord) {
    this->relativeCoord = relativeCoord;
}

Colour* Segment::getColour() {
    return colour;
}