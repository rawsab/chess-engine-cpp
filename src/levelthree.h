#ifndef LEVELTHREE_H
#define LEVELTHREE_H
#include "computer.h"

class LevelThree : public Computer {
 public:
    LevelThree(Color c, Board *b);
    Move getMove() override;
    ~LevelThree() {};
};

#endif
