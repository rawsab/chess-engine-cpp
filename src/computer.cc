#include "computer.h"
#include <stdlib.h>
#include <random>
#include <algorithm>

#include <iostream>

using namespace std;

Computer::Computer(Color c, Board *b) : Player{c}, board{b} {}

Computer::~Computer() {}

LevelThree::LevelThree(Color c, Board *b) : Computer{c, b} {}
LevelFour::LevelFour(Color c, Board *b) : Computer{c, b} {}

Move LevelThree::getMove(){
    return Move{};
}

Move LevelFour::getMove(){
    return Move{};
}