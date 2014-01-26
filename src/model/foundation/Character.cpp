//
//  Character.cpp
//  lanaSnake
//
//  Created by Andy Stanton on 02/06/2013.
//  Copyright (c) 2013 Andy Stanton. All rights reserved.
//

#include "Character.h"

Character::Character(bool** pixels) {
    this->pixels = pixels;
}

bool** Character::getPixels() {
    return this->pixels;
}
