#ifndef LEVELTWO_H
#define LEVELTWO_H
#include "computer.h"

class LevelTwo : public Computer {
 public:
    LevelTwo(Color c, shared_ptr<Board> b);
    Move getMove() override;
    ~LevelTwo() {};
};

#endif
