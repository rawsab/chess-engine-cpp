#ifndef PAWN_H
#define PAWN_H

#include "piece.h"
#include <vector>

class Pawn : public Piece {
  private:
    bool canMove2;

  public:
    Pawn(Color c, Square *pos);
    vector<Move> getMoves() const override;
};

#endif