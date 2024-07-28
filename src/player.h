#ifndef PLAYER_H
#define PLAYER_h

#include "types.h"

class Player {
 private:
 protected:
  Color color;

 public:
  Color getColor();
  virtual Move getMove() = 0;
};

#endif
