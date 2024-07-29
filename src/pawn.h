#ifndef PAWN_H
#define PAWN_H

#include "piece.h"
#include <vector>

class Pawn : public Piece {
  private:
    bool enpassant;

   public:
    Pawn(Color c, Square *pos, Board *b);
    vector<Move> getMoves() const override;
    bool canMove(int newRow, int newCol) const override;
};

#endif
