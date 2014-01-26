//
//  Character.h
//  lanaSnake
//
//  Created by Andy Stanton on 02/06/2013.
//  Copyright (c) 2013 Andy Stanton. All rights reserved.
//

#ifndef __lanaSnake__Character__
#define __lanaSnake__Character__

#include <iostream>

class Character {
private:
    bool** pixels;
public:
    Character(bool**);
    bool** getPixels();
};

#endif /* defined(__lanaSnake__Character__) */
