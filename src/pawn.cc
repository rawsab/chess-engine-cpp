#include "pawn.h"

#include "board.h"

using namespace std;

Pawn::Pawn(Color c, Square *pos, Board *b)
    : Piece{PieceType::Pawn, c, 1, pos, b}, enpassant{false} {}

vector<Move> Pawn::getMoves() const {
  vector<Move> moves;
  if (!pos) return moves;

  int row = pos->getRow();
  int col = pos->getCol();

  // Potential move directions for white pawns
  vector<pair<int, int>> directionsWhite = {{1, 0}, {1, 1}, {1, -1}, {2, 0}};

  // Potential move directions for black pawns
  vector<pair<int, int>> directionsBlack = {
      {-1, 0}, {-1, 1}, {-1, -1}, {-2, 0}};

  vector<pair<int, int>> directions =
      getColor() == Color::White ? directionsWhite : directionsBlack;

  for (const auto &direction : directions) {
    int newRow = row + direction.first;
    int newCol = col + direction.second;

    if (canMove(newRow, newCol)) {
      moves.emplace_back(Move(row,col, newRow, newCol));
    }
  }

  return moves;
}

bool Pawn::canMove(int newRow, int newCol) const {
  if (pos) {
    int col = pos->getCol();
    int row = pos->getRow();

    // Square board->getSquare(newRow, newCol) = board->getSquare(newRow,
    // newCol);

    if (getColor() == Color::White) {
      if (newCol == col + 1 && newRow == row - 1 && newRow >= 0 && newCol < 8 &&
          (board->getSquare(newRow, newCol).getPiece()->getColor() ==
               Color::Black ||
           (enpassant &&
            board->getSquare(newRow, newCol).getPiece() == nullptr))) {
        return true;
      } else if (newCol == col && newRow == row - 1 && newRow >= 0 &&
                 board->getSquare(newRow, newCol).getPiece() == nullptr) {
        return true;
      } else if (newCol == col - 1 && newRow == row - 1 && newCol >= 0 &&
                 newRow >= 0 &&
                 (board->getSquare(newRow, newCol).getPiece()->getColor() ==
                      Color::Black ||
                  (enpassant &&
                   board->getSquare(newRow, newCol).getPiece() == nullptr))) {
        return true;
      } else if (newCol == col && newRow == row - 2 && row == 6 &&
                 !board->getSquare(newRow, newCol).getPiece() &&
                 !board->getSquare(newRow + 1, newCol).getPiece()) {
        return true;
      }
    } else if (getColor() == Color::Black) {
      if (newCol == col - 1 && newRow == row + 1 && newRow < 8 &&
          newCol >= 0 &&
          (board->getSquare(newRow, newCol).getPiece()->getColor() ==
               Color::White ||
           (enpassant &&
            board->getSquare(newRow, newCol).getPiece() == nullptr))) {
        return true;
      } else if (newCol == col && newRow == row + 1 && newRow < 8 &&
                 board->getSquare(newRow, newCol).getPiece() == nullptr) {
        return true;
      } else if (newCol == col + 1 && newRow == row + 1 && newCol < 8 &&
                 newRow < 8 &&
                 (board->getSquare(newRow, newCol).getPiece()->getColor() ==
                      Color::White ||
                  (enpassant &&
                   board->getSquare(newRow, newCol).getPiece() == nullptr))) {
        return true;
      } else if (newCol == col && newRow == row + 2 && newRow < 8 && row == 1 &&
                 !board->getSquare(newRow, newCol).getPiece() &&
                 !board->getSquare(newRow - 1, newCol).getPiece()) {
        return true;
      }
    }
  }
  return false;
}

// fix white moving back down
// fix pawn cant go to a place where a pawn already was