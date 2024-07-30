#include "computer.h"
#include <stdlib.h>
#include <random>
#include <algorithm>

#include <iostream>

using namespace std;

Computer::Computer(Color c, Board *b) : Player{c}, board{b} {}

Computer::~Computer() {}