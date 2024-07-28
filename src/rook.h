#ifndef ROOK_H
#define ROOK_H

#include <vector>

#include "piece.h"

using namespace std;

class Rook : public Piece {
 private:
  /* data */
 public:
  Rook(Square);
  vector<Move> possibleMoves();
  ~Rook();
};

Rook::Rook(/* args */) {}

Rook::~Rook() {}

#endif