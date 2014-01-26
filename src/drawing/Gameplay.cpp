//
//  Gameplay.cpp
//  lanaSnake
//
//  Created by Andy Stanton on 19/06/2013.
//  Copyright (c) 2013 Andy Stanton. All rights reserved.
//

#include "Gameplay.h"

void Gameplay::draw(Drawable* drawable) {
    draw(drawable, Primitive::DEFAULT_PIXEL_SIZE);
}

void Gameplay::draw(Drawable* drawable, GLint pixelSize) {
    Vec2d* drawCoords = drawable->getCoords()->applyScale(pixelSize);
    glPushMatrix();
    glTranslatef(drawCoords->getX(), drawCoords->getY(), 0);
    for (Segment* segment : *drawable->getMesh()) {
        Vec2d* relativeOffset = segment->getRelativeCoord()->getInverse();
        glTranslatef(relativeOffset->getX() * pixelSize, relativeOffset->getY() * pixelSize, 0);
        glColor3fv(segment->getColour()->getColour3fv());
        Primitive::drawSquare(pixelSize);
    }
    glPopMatrix();
}

void Gameplay::drawPause(GLfloat width) {
    GLint smallSize = Primitive::DEFAULT_PIXEL_SIZE / 2;
    GLint pauseHeight = 4;
    
    glColor4f(1.0f, 1.0f, 1.0f, 0.4f);
    
    glPushMatrix();
    glTranslatef(width - smallSize * 3, smallSize * 2, 0.0f);
    for (int i=0; i < pauseHeight; i++) {
        Primitive::drawSquare(smallSize);
        glTranslatef(0.0f, smallSize, 0.0f);
    }
    glTranslatef(-2*smallSize, -pauseHeight*smallSize, 0.0f);
    for (int i=0; i < pauseHeight; i++) {
        Primitive::drawSquare(smallSize);
        glTranslatef(0.0f, smallSize, 0.0f);
    }
    glPopMatrix();
}
