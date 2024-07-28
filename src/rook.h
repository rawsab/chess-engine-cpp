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
  Rook(Color c);
  bool getCanCastle() const;
  void setCanCastle();
  vector<Move> possibleMoves();
};

#endif