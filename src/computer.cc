#include "computer.h"
#include <stdlib.h>
#include <random>
#include <algorithm>

#include <iostream>

using namespace std;

Computer::Computer(Color c, Board *b) : Player{c}, board{b} {}

Computer::~Computer() {}

// random number generator
int Computer::getRandom(int min, int max) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distribution(min, max);

    return distribution(gen);
}

