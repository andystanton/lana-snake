
#ifndef lanaSnake_alphabet_h
#define lanaSnake_alphabet_h

#include <map>
#include "../model/foundation/Character.h"
#include <iostream>

using namespace std;

class Alphabet {
private:
    Alphabet();
    ~Alphabet();
    
    static bool** initaliseArray();
    static Alphabet* alphabet;
    
    map<int, Character*> alphabetMap;
    
    void addToAlphabet(int ascii, Character* character);
    
public:
    static const int CHARACTER_WIDTH = 5;
    static const int CHARACTER_HEIGHT = 7;
    
    static Alphabet* getInstance();
    
    Character* getChar(int character);
};

#endif