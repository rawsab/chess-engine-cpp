#include "piece.h"

using namespace std;

Piece::Piece(PieceType t, Color c, int points, Square *pos) : points{points}, type{t}, color{c}, pos{pos} {}

void Piece::getlinearMoves(int row, int col, vector<Move>& moves) {
  int currentRow = pos->getRow();
  int currentCol = pos->getCol();
  int newRow = currentRow + row;
  int newCol = currentCol + col;

  while(newCol >= 0 && newCol < 8 && newRow >= 0 && newRow < 8){
    // logic for checking moves. 

    newRow += row;
    newCol += col;
  }
}

bool Piece::canCheck(const Board& b) const {
  vector<Move> moves = getMoves(b);
  for (auto move : moves) {
    if (move.oldPieceType == PieceType::King && move.oldColorType != color) {
      return true;
    }
  }
  return false;
}

Color Piece::getColor() const { return color; }

PieceType Piece::getType() const { return type; }

int Piece::getPoints() const { return points; }