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

 public:
  Piece(PieceType t, Color c, int points);
  virtual vector<Move> getMoves() const = 0;
  void move(Move m);
  bool isValidMove(Move m, const Board& b) const;
  bool canCheck(const Board& b) const;
  int getPoints() const;
  Color getColor() const;
  PieceType getType() const;
  virtual ~Piece();
};

#endif