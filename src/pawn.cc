#include "pawn.h"

#include "board.h"

using namespace std;

Pawn::Pawn(Color c, Square *pos, Board *b)
    : Piece{PieceType::Pawn, c, 1, pos, b}, enpassant{false} {}

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
    if (currentRow < 7 &&
        !board->getSquare(currentRow, currentCol - 1).getPiece()) {
      moves.push_back(Move{currentRow, currentCol, currentRow, currentCol - 1});
    }
    /// finish off
  }
  return moves;
}

bool Pawn::canMove(int newRow, int newCol) const {
  if (pos) {
    int col = pos->getCol();
    int row = pos->getRow();

    // Square board->getSquare(newRow, newCol) = board->getSquare(newRow, newCol);

    if (getColor() == Color::White) {
      if (newCol == col + 1 && newRow == row + 1 && newRow < 8 && newCol < 8 &&
          (board->getSquare(newRow, newCol).getPiece()->getColor() == Color::Black ||
           (enpassant && board->getSquare(newRow, newCol).getPiece() == nullptr))) {
        return true;
      } else if (newCol == col && newRow == row - 1 && newRow >= 0 &&
                 board->getSquare(newRow, newCol).getPiece() == nullptr) {
        return true;
      } else if (newCol == col - 1 && newRow == row + 1 && newCol >= 0 &&
                 newRow < 8 &&
                 (board->getSquare(newRow, newCol).getPiece()->getColor() == Color::Black ||
                  (enpassant &&
                   board->getSquare(newRow, newCol).getPiece() == nullptr))) {
        return true;
      } else if (newCol == col && newRow == row - 2 && row == 6 &&
                 !board->getSquare(newRow, newCol).getPiece() &&
                 !board->getSquare(newRow - 1, newCol).getPiece()) {
        return true;
      }
    } else if (getColor() == Color::Black) {
      if (newCol == col - 1 && newRow == row - 1 && newRow >= 0 &&
          newCol >= 0 &&
          (board->getSquare(newRow, newCol).getPiece()->getColor() == Color::White ||
           (enpassant && board->getSquare(newRow, newCol).getPiece() == nullptr))) {
        return true;
      } else if (newCol == col && newRow == row + 1 && newRow < 8 && board->getSquare(newRow,newCol).getPiece() == nullptr) {
        return true;
      } else if (newCol == col + 1 && newRow == row - 1 && newCol < 8 &&
                 newRow >= 0 &&
                 (board->getSquare(newRow, newCol).getPiece()->getColor() == Color::White ||
                  (enpassant &&
                   board->getSquare(newRow, newCol).getPiece() == nullptr))) {
        return true;
      } else if (newCol == col && newRow == row + 2 && newRow < 8 && row == 1 &&
                 !board->getSquare(newRow, newCol).getPiece() &&
                 !board->getSquare(newRow + 1, newCol).getPiece()) {
        return true;
      }
    }
  }
  return false;
}

// fix white moving back down
// fix pawn cant go to a place where a pawn already was 