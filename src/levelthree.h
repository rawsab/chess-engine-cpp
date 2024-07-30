#ifndef LEVELTWO_H
#define LEVELTWO_H
#include "computer.h"

class LevelThree : public Computer {
 public:
    LevelThree(Color c, Board *b);
    Move getMove() override;
    ~LevelThree() {};
};

#endif
