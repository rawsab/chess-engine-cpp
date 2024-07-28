#include "piece.h"

using namespace std;

Piece::Piece(PieceType t, Color c, int points, Square *pos) : points{points}, type{t}, color{c}, pos{pos} {}

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