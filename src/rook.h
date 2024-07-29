#ifndef ROOK_H
#define ROOK_H

#include <vector>

#include "piece.h"

using namespace std;

class Rook : public Piece {
 private:
  bool canCastle;

 public:
  Rook(Color c, Square *pos, Board *b);
  bool getCanCastle() const;
  void setCanCastle();
  vector<Move> getMoves() const override;
  bool canMove(int newRow, int newCol) const override;
};

#endif
