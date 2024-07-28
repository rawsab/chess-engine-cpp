#ifndef PIECE_H
#define PIECE_H

#include <vector>

#include "types.h"
#include "square.h"
#include "board.h"


using namespace std;

class Piece {
 private:
 protected:
  int points;
  PieceType type;
  Color color;
  Square* pos;
  Board* board;

  void getlinearMoves(int row, int col, vector<Move>& moves);

 public:
  Piece(PieceType t, Color c, int points, Square* pos);
  virtual vector<Move> getMoves(const Board& b) const = 0;
  void move(Move m);
  bool isValidMove(Move m, const Board& b) const;
  bool canCheck(const Board& b) const;
  int getPoints() const;
  Color getColor() const;
  PieceType getType() const;
  virtual ~Piece();
};

#endif