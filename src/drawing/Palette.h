#ifndef __snake__palette__
#define __snake__palette__

#include "../model/foundation/Colour.h"

using namespace std;

class Palette {
private:
    static Palette* palette;
    Colour** pointerColours;
    Colour* bgColour;
    Palette();
    ~Palette();
public:
    static Palette* getInstance();

    Colour* getPink();
    Colour* getBgColour();
    Colour* getRandomColour();
};

#endif /* defined(__snake__palette__) */