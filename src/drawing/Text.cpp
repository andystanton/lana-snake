//
//  Text.cpp
//  lanaSnake
//
//  Created by Andy Stanton on 06/06/2013.
//  Copyright (c) 2013 Andy Stanton. All rights reserved.
//

#include "Text.h"

void Text::init() {
    alphabet::initAlphabet();
}

void Text::drawCharacter(char character, GLint pixelSize) {
    float resetVal = -alphabet::CHARACTER_HEIGHT * pixelSize;
    if (alphabet::alphabet[character]) {
        bool** charValues = alphabet::alphabet[character]->getPixels();
        for (int i=0; i<alphabet::CHARACTER_WIDTH; i++) {
            for (int j=0; j<alphabet::CHARACTER_HEIGHT; j++) {
                if (charValues[i][j]) {
                    Primitive::drawSquare(pixelSize);
                }
                glTranslatef(0.0f, pixelSize, 0.0f);
            }
            glTranslatef(pixelSize, resetVal, 0.0f);
        }
    }
}

void Text::writeText(string text, GLint pixelSize) {
    for(string::iterator it = text.begin(); it != text.end(); ++it) {
        drawCharacter(*it, pixelSize);
        glTranslatef(pixelSize, 0.0f, 0.0f);
    }
}

void Text::writeText(string text) {
    writeText(text, Primitive::DEFAULT_PIXEL_SIZE);
}

void Text::writeCentredParagraph(string text, GLfloat width, GLfloat height, GLint pixelSize) {
    GLint lettersWidth = (GLint) (pixelSize * (text.size() * alphabet::CHARACTER_WIDTH + text.size() - 1));
    glTranslatef((width-lettersWidth)/2, height - (alphabet::CHARACTER_HEIGHT * Primitive::DEFAULT_PIXEL_SIZE/2), 0.0f);
    Text::writeText(text, pixelSize);
}

void Text::writeCentredParagraph(string text, GLfloat width, GLfloat height) {
    writeCentredParagraph(text, width, height, Primitive::DEFAULT_PIXEL_SIZE);
}
