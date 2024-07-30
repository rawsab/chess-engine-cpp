#ifndef LEVELONE_H
#define LEVELONE_H
#include "computer.h"

class LevelOne : public Computer {
 public:
    LevelOne(Color c, Board *b);
    Move getMove() override;

    ~LevelOne() {};
};

#endif
