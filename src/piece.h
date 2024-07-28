#ifndef PIECE_H
#define PIECE_H

#include <vector>

#include "board.h"
#include "types.h"

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
  void move(Move);
  bool isValidMove(Move, const Board &);
  bool canCheck(const Board &);
  int getValue();
  virtual ~Piece();
};

#endif