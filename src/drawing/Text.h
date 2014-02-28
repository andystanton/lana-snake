//
//  Text.h
//  lanaSnake
//
//  Created by Andy Stanton on 06/06/2013.
//  Copyright (c) 2013 Andy Stanton. All rights reserved.
//

#ifndef __lanaSnake__Text__
#define __lanaSnake__Text__

#include <string>
#include "GLFW/glfw3.h"
#include "Primitive.h"
#include "../drawing/Alphabet.h"

using namespace std;

class Text {
private:
    static Alphabet * alphabet;
public:
    static void init();
    static void drawCharacter(char character, GLint pixelSize);
    static void writeText(string text, GLint pixelSize);
    static void writeText(string text);
    static void writeCentredParagraph(string text, GLfloat width, GLfloat height, GLint pixelSize);
    static void writeCentredParagraph(string text, GLfloat width, GLfloat height);
};

#endif /* defined(__lanaSnake__Text__) */
