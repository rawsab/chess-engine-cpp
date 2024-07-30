#ifndef COMPUTER_H
#define COMPUTER_H

#include "player.h"
#include <memory>

class Computer : public Player {
 protected:
    shared_ptr<Board> board;

 public:
    Computer(Color c, shared_ptr<Board> b);

    virtual Move getMove() = 0;
    int getRandom(int min, int max);
    ~Computer();
};


#endif