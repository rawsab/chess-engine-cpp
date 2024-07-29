#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"
#include <vector>

class Queen : public Piece {
  private:

  public:
    Queen(Color c, Square *pos);
    vector<Move> getMoves() const override;
    // bool canMove(int newRow, int newCol) const override;
};

#endif
