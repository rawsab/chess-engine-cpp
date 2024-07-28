#ifndef COMPUTER_H
#define COMPUTER_H

#include "player.h"

class Computer : public Player {
 public:
    Computer(Color c);
    virtual Move getMove() = 0;
};


// Levels for move generation difficulties

class LevelOne : public Computer {
 public:
    LevelOne(Color c);
    Move getMove() override;
};

class LevelTwo : public Computer {
 public:
    LevelTwo(Color c);
    Move getMove() override;
};

class LevelThree : public Computer {
 public:
    LevelThree(Color c);
    Move getMove() override;
};

#endif
