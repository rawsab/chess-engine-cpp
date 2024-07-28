#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"
#include "board.h"

class Player {
 private:
 protected:
  Color color;
  Board *board;

 public:
  Player(Color c, Board *b);
  virtual ~Player();

  Color getColor();
  virtual Move getMove() = 0;
};

#endif
