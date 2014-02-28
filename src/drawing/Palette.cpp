
#include "Palette.h"

Palette* Palette::palette;

Palette::Palette() {
    pointerColours = new Colour*[5];
    pointerColours[0] = new Colour(0xFF66B3);
    pointerColours[1] = new Colour(0xD1F2A5);
    pointerColours[2] = new Colour(0xEFFAB4);
    pointerColours[3] = new Colour(0xFFC48C);
    pointerColours[4] = new Colour(0xFF9F80);
    bgColour = new Colour(0xE5B2CC);
}

Palette::~Palette() {
}

Palette* Palette::getInstance() {
    if (palette == nullptr) {
        palette = new Palette();
    }
    return palette;
}

Colour* Palette::getPink() {
    return pointerColours[0];
}

Colour* Palette::getBgColour() {
    return bgColour;
}

Colour* Palette::getRandomColour() {
    return pointerColours[abs(rand() % 5)];
}

