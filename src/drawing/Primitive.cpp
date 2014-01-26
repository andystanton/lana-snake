//
//  Primitive.cpp
//  lanaSnake
//
//  Created by Andy Stanton on 06/06/2013.
//  Copyright (c) 2013 Andy Stanton. All rights reserved.
//

#include "Primitive.h"

void Primitive::drawSquare() {
    drawSquare(DEFAULT_PIXEL_SIZE);
}

void Primitive::drawSquare(GLfloat pixelSize) {
    glShadeModel(GL_FLAT);
    GLfloat vertices[8] = {
        0           ,0
        ,pixelSize  ,0
        ,pixelSize  ,pixelSize
        ,0          ,pixelSize
    };
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(2, GL_FLOAT, 0, vertices);
	glDrawArrays(GL_QUADS, 0, 4);
	glDisableClientState(GL_VERTEX_ARRAY);
}

void translate(Vec2d* coords) {
    translate(coords);
}

void translate(Vec2d* coords, GLfloat pixelSize) {
    glTranslatef(coords->getX() * pixelSize, coords->getY() * pixelSize, 0);
}
