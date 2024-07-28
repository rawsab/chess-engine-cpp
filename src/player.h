#ifndef PLAYER_H
#define PLAYER_h

#include "types.h"
#include "board.h"

class Player {
 private:
 protected:
  Color color;
  Board *board;

 public:
  Color getColor();
  Move getMove();
};

#endif
