//
//  World.cpp
//  lanaSnake
//
//  Created by Andy Stanton on 04/06/2013.
//  Copyright (c) 2013 Andy Stanton. All rights reserved.
//

#include "World.h"

World::World(GLint xBound, GLint yBound) {
    bounds = new Vec2d(xBound, yBound);
    centre = new Vec2d(xBound/2, yBound/2);
    entities = vector<Entity*>();
    entities.push_back(this);
}

GLint World::getXBound() {
    return this->bounds->getX();
}

GLint World::getYBound() {
    return this->bounds->getY();
}

Vec2d* World::getOrigin() {
    return centre;
}

bool World::collidesWith(Vec2d* coords) {
    return coords->getX() < 0 || coords->getX() >= this->getXBound() || coords->getY() < 0 || coords->getY() >= this->getYBound();
}