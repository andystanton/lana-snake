#ifndef __snake__palette__
#define __snake__palette__

#include "../model/foundation/Colour.h"

namespace palette {
    static Colour** pointerColours;
    static Colour* bgColour;
    
    static void initColours() {
        pointerColours = new Colour*[5];
        pointerColours[0] = new Colour(0xFF66B3);
        pointerColours[1] = new Colour(0xD1F2A5);
        pointerColours[2] = new Colour(0xEFFAB4);
        pointerColours[3] = new Colour(0xFFC48C);
        pointerColours[4] = new Colour(0xFF9F80);
        bgColour = new Colour(0xE5B2CC);
    }
    
    static Colour* getPink() {
        return pointerColours[0];
    }
    
    static Colour* getBgColour() {
        return bgColour;
    }
    
    static Colour* getRandomColour() {
        return pointerColours[abs(rand() % 5)];
    }
}

#endif /* defined(__snake__palette__) */