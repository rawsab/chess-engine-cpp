#ifndef LEVELFOUR_H
#define LEVELFOUR_H
#include "computer.h"

class LevelFour : public Computer {
 public:
    LevelFour(Color c, Board *b);
    Move getMove() override;
    ~LevelFour() {};
};

#endif
