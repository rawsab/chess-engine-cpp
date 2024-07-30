#ifndef COMPUTER_H
#define COMPUTER_H

#include "player.h"

class Computer : public Player {
 protected:
    Board *board;

 public:
    Computer(Color c, Board *b);

    virtual Move getMove() = 0;

    ~Computer();
};


#endif