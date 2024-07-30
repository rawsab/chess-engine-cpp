#ifndef COMPUTER_H
#define COMPUTER_H

#include "player.h"

class Computer : public Player {
 protected:
    Board *board;

 public:
    Computer(Color c, Board *b);
    virtual Move getMove() = 0;

    virtual ~Computer();
};


// Levels for move generation difficulties

class LevelOne : public Computer {
 public:
    LevelOne(Color c, Board *b);
    Move getMove() override;
};

class LevelFour : public Computer {
 public:
    LevelFour(Color c, Board *b);
    Move getMove() override;
};

#endif
