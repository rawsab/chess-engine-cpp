#ifndef PIECE_H
#define PIECE_H

#include <vector>

#include "types.h"

class Board;

using namespace std;


class Piece {
 private:
 protected:
  int points;
  PieceType type;
  Color color;
  vector<Move> moves;

 public:
  Piece(PieceType t, Color c);
  virtual vector<Move> getMoves() const = 0;
  PieceType getType();
  void move(Move m);
  bool isValidMove(Move m, const Board& b);
  bool canCheck(const Board& b);
  int getPoints() const;
  Color getColour() const;
  PieceType getType() const;
  virtual ~Piece();
};

#endif