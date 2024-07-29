#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"
#include <vector>

class Knight : public Piece {
  private:

  public:
    Knight(Color c, Square *pos,  Board *b);
    vector<Move> getMoves() const override;
    Move getKnightMove(int currentRow, int currentCol, int rowD, int colD) const;
};

#endif
