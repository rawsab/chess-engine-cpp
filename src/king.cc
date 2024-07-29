#include "king.h"
#include "board.h"

using namespace std;

King::King(Color c, Square *pos, Board *b)
    : Piece{PieceType::King, c, 40, pos, b} {}

vector<Move> King::getMoves() const {
    vector<Move> moves;
    if (!pos) return moves;

    int currentRow = pos->getRow();
    int currentCol = pos->getCol();

    // King can only move one square in all directions

    if (currentRow + 1 < 8) {
        if (board->getSquare(currentRow + 1, currentCol).getPiece()->getColor() != color) {
            moves.push_back(Move{currentRow, currentCol, currentRow + 1, currentCol});
        }
        if (currentCol + 1 < 8) {
            if (board->getSquare(currentRow + 1, currentCol + 1).getPiece()->getColor() != color) {
                moves.push_back(Move{currentRow, currentCol, currentRow + 1, currentCol + 1});
            }
        }
        if (currentCol - 1 >= 0) {
            if (board->getSquare(currentRow + 1, currentCol - 1).getPiece()->getColor() != color) {
                moves.push_back(Move{currentRow, currentCol, currentRow + 1, currentCol - 1});
            }
        }
    }
    if (currentRow - 1 >= 0) {
        if (board->getSquare(currentRow - 1, currentCol).getPiece()->getColor() != color) {
            moves.push_back(Move{currentRow, currentCol, currentRow - 1, currentCol});
        }
        if (currentCol + 1 < 8) {
            if (board->getSquare(currentRow - 1, currentCol + 1).getPiece()->getColor() != color) {
                moves.push_back(Move{currentRow, currentCol, currentRow - 1, currentCol + 1});
            }
        }
        if (currentCol - 1 >= 0) {
            if (board->getSquare(currentRow - 1, currentCol - 1).getPiece()->getColor() != color) {
                moves.push_back(Move{currentRow, currentCol, currentRow - 1, currentCol - 1});
            }
        }
    }

    return moves;
}

bool King::canMove(int newRow, int newCol) const {
  vector<Move> moves = getMoves();
  if (!pos) return false;

  int row = pos->getRow();
  int col = pos->getCol();

  Move possibleMove{row, col, newRow, newCol};

  for (auto move : moves){
    if (move == possibleMove) return true;
  }

  return false;
}
