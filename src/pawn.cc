#include "pawn.h"

#include "board.h"

using namespace std;

Pawn::Pawn(Color c, Square *pos)
    : Piece{PieceType::Pawn, c, 1, pos}, canMove2{true} {}

vector<Move> Pawn::getMoves() const {
  vector<Move> moves;
  if (!pos) return moves;

  int currentRow = pos->getRow();
  int currentCol = pos->getCol();

  if (color == Color::White) {
    if (currentRow == 6 && !board->getSquare(currentRow, 5).getPiece() &&
        !board->getSquare(currentRow, 4).getPiece()) {
      moves.push_back(Move{currentRow, currentCol, 4, currentCol});
    }
    if (currentRow < 7 && !board->getSquare(currentRow, currentCol - 1).getPiece()){
			moves.push_back(Move{currentRow, currentCol, currentRow, currentCol - 1});
		}

  }
  return moves;
}
