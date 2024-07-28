#ifndef PIECE_H
#define PIECE_H

#include <vector>

#include "types.h"

class Board;

using namespace std;


class Piece {
 private:
 protected:
  PieceType type;
  Color color;
  vector<Move> moves;

 public:
  virtual vector<Move> getMoves() = 0;
  PieceType getType();
  void move(Move m);
  bool isValidMove(Move m, const Board& b);
  bool canCheck(const Board& b);
  int getValue();
  virtual ~Piece();
};

#endif