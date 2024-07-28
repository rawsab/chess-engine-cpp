#ifndef ROOK_H
#define ROOK_H

#include <vector>

#include "piece.h"
#include "square.h"

using namespace std;

class Rook : public Piece {
 private:
  bool canCastle;

 public:
  Rook(Square *pos, Color c);
  bool getCanCastle();
  vector<Move> possibleMoves();
};

#endif