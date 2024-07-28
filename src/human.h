#ifndef HUMAN_H
#define HUMAN_H
#include "types.h"
#include "player.h"
class Human : public Player {
 public:
    Human(Color c);
    Move getMove() override;

    ~Human();
};

#endif
