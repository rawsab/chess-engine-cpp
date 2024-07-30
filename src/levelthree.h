#ifndef LEVELTHREE_H
#define LEVELTHREE_H
#include "computer.h"

class LevelThree : public Computer {
 public:
    LevelThree(Color c, shared_ptr<Board> b);
    Move getMove() override;
    ~LevelThree() {};
};

#endif
