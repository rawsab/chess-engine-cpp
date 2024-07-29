#include "pawn.h"

#include "board.h"

using namespace std;

Pawn::Pawn(Color c, Square *pos)
    : Piece{PieceType::Pawn, c, 1, pos}, canMove2{true}, enpassant{false} {}

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

    Square newSquare = board->getSquare(newRow, newCol);

    if (getColor() == Color::White) {
      if (newCol == col + 1 && newRow == row + 1 && newRow < 8 && newCol < 8 &&
          (newSquare.getPiece()->getColor() == Color::Black ||
           (enpassant && newSquare.getPiece()->getColor() == Color::NoColor))) {
        return true;
      } else if (newCol == col && newRow == row + 1 && newRow < 8 &&
                 newSquare.getPiece()->getColor() == Color::NoColor) {
        return true;
      } else if (newCol == col - 1 && newRow == row + 1 && newCol >= 0 &&
                 newRow < 8 &&
                 (newSquare.getPiece()->getColor() == Color::Black ||
                  (enpassant &&
                   newSquare.getPiece()->getColor() == Color::NoColor))) {
        return true;
      } else if (newCol == col && newRow == row + 2 && canMove2 && !newSquare.getPiece() && !board->getSquare(newRow - 1, newCol).getPiece()){
        return true;
      }
    } else if (getColor() == Color::Black){
         if (newCol == col - 1 && newRow == row - 1 && newRow >= 0 && newCol >= 0 &&
          (newSquare.getPiece()->getColor() == Color::White ||
           (enpassant && newSquare.getPiece()->getColor() == Color::NoColor))) {
        return true;
      } else if (newCol == col && newRow == row - 1 && newRow >= 0 &&
                 newSquare.getPiece()->getColor() == Color::NoColor) {
        return true;
      } else if (newCol == col + 1 && newRow == row - 1 && newCol < 8 &&
                 newRow >= 0 &&
                 (newSquare.getPiece()->getColor() == Color::White ||
                  (enpassant &&
                   newSquare.getPiece()->getColor() == Color::NoColor))) {
        return true;
      } else if (newCol == col && newRow == row - 2 && canMove2 && !newSquare.getPiece() && !board->getSquare(newRow + 1, newCol).getPiece()){
        return true;
      }
    }
  } else {
    return false;
  }
}
