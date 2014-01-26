//
//  Vec2d.cpp
//  lanaSnake
//
//  Created by Andy Stanton on 04/06/2013.
//  Copyright (c) 2013 Andy Stanton. All rights reserved.
//

#include "Vec2d.h"

Vec2d* Vec2d::UP     = new Vec2d( 0, -1);
Vec2d* Vec2d::DOWN   = new Vec2d( 0,  1);
Vec2d* Vec2d::LEFT   = new Vec2d(-1,  0);
Vec2d* Vec2d::RIGHT  = new Vec2d( 1,  0);
Vec2d* Vec2d::ORIGIN = new Vec2d( 0,  0);

Vec2d::Vec2d(GLint x, GLint y) {
    setCoords(x, y);
}

Vec2d::Vec2d(Vec2d* coords) {
    setCoords(coords);
}

void Vec2d::setX(GLint x) {
    this->x = x;
}

void Vec2d::setY(GLint y) {
    this->y = y;
}

void Vec2d::setCoords(GLint x, GLint y) {
    this->x = int(x);
    this->y = int(y);
}

void Vec2d::setCoords(Vec2d* coords) {
    setCoords(coords->getX(), coords->getY());
}

GLint Vec2d::getX() {
    return this->x;
}

GLint Vec2d::getY() {
    return this->y;
}

bool Vec2d::equals(Vec2d *other) {
    return this->x == other->x && this->y == other->y;
}

string* Vec2d::toString() {
    stringstream out;
    out << "(" << this->x << ", " << this->y << ")";
    return new string(out.str());
}

void Vec2d::applyOffset(Vec2d* offset) {
    x += offset->getX();
    y += offset->getY();
}

Vec2d* Vec2d::getOffset(Vec2d* offset) {
    return new Vec2d(getX() + offset->getX(), getY() + offset->getY());
}

Vec2d* Vec2d::applyScale(GLfloat scale) {
    return new Vec2d((GLfloat) getX() * scale, (GLfloat)getY() * scale);
}

Vec2d* Vec2d::getInverse() {
    return new Vec2d(-x, -y);
}
