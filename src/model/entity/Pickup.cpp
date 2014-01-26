//
//  Pickup.cpp
//  lanaSnake
//
//  Created by Andy Stanton on 02/06/2013.
//  Copyright (c) 2013 Andy Stanton. All rights reserved.
//

#include "Pickup.h"

Pickup::Pickup(Vec2d* coords, Colour* colour): Entity(coords) {
    segments = vector<Segment*>();
    segments.push_back(new Segment(Vec2d::ORIGIN, colour));
}

Colour* Pickup::getColour() {
    return segments.front()->getColour();
}

bool Pickup::collidesWith(Vec2d *coords) {
    return this->coords->equals(coords);
}

vector<Segment*>* Pickup::getMesh() {
    return &segments;
}
