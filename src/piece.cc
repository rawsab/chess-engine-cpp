#include "piece.h"
#include "board.h"

using namespace std;

Piece::Piece(PieceType t, Color c, int points, Square* pos)
    : points{points}, type{t}, color{c}, pos{pos} {}

void Piece::getlinearMoves(int row, int col, vector<Move>& moves) {
  int currentRow = pos->getRow();
  int currentCol = pos->getCol();
  int newRow = currentRow + row;
  int newCol = currentCol + col;

  while (newCol >= 0 && newCol < 8 && newRow >= 0 && newRow < 8) {
    // logic for checking moves.
    Piece* oldPiece = board->getSquare(newRow, newCol).getPiece();
    if (oldPiece && oldPiece->getColor() != color) {
      moves.push_back(Move{MoveType::Regular, oldPiece->getType(), type,
                           oldPiece->getColor(), color, currentRow, currentCol,
                           newRow, newCol});
      break;
    }

    moves.push_back(Move{MoveType::Regular, oldPiece->getType(), type,
                         oldPiece->getColor(), color, currentRow, currentCol,
                         newRow, newCol});
    newRow += row;
    newCol += col;
  }
}

bool Piece::canCheck() const {
  vector<Move> moves = getMoves();
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

Piece::~Piece() {}