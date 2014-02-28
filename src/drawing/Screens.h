//
//  Screens.h
//  lanaSnake
//
//  Created by Andy Stanton on 12/06/2013.
//  Copyright (c) 2013 Andy Stanton. All rights reserved.
//

#ifndef lanaSnake_Screens_h
#define lanaSnake_Screens_h

#include "GLFW/glfw3.h"
#include "Text.h"
#include "../drawing/Palette.h"
#include "../drawing/Alphabet.h"

class Screens {
private:
    Palette * palette;
    GLfloat width, height;
    void drawParagraph(string text, GLfloat height, GLfloat pixelSize);
    GLfloat linebreak(GLfloat height, GLfloat pixelSize);
public:
    Screens(GLfloat width, GLfloat height);
    void drawStartScreen(void);
    void drawCompleteScreen(void);
    void drawDeadScreen(GLint count);
};

#endif
