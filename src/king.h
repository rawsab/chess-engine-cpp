#ifndef KING_H
#define KING_H

#include "piece.h"
#include <vector>

class King : public Piece {
  private:
    bool canCastle;

  public:
    King(Color c, Square *pos, Board* b);
    vector<Move> getMoves() const override;
    bool getCanCastle() const;
    void setCanCastle();
    bool canMove(int newRow, int newCol) const override;
};

#endif
