#include "king.h"
#include "board.h"

#include <iostream>

using namespace std;

King::King(Color c, Square *pos, Board *b)
    : Piece{PieceType::King, c, 40, pos, b}, canCastle{true} {}

bool King::getCanCastle() const { return canCastle; }
void King::setCanCastle(bool b) { canCastle = b; }

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
    if (currentCol + 1 < 8) {
        if (board->getSquare(currentRow, currentCol + 1).getPiece()->getColor() != color) {
            moves.push_back(Move{currentRow, currentCol, currentRow, currentCol + 1});
        }
    }
    if (currentCol - 1 >= 0) {
        if (board->getSquare(currentRow, currentCol - 1).getPiece()->getColor() != color) {
            moves.push_back(Move{currentRow, currentCol, currentRow, currentCol - 1});
        }
    }

    if (currentCol + 2 < 8) {
        if (board->getSquare(currentRow, currentCol + 2).getPiece()->getColor() != color) {
            moves.push_back(Move{currentRow, currentCol, currentRow, currentCol + 2});
        }
    }
    if (currentCol - 2 >= 0) {
        if (board->getSquare(currentRow, currentCol - 2).getPiece()->getColor() != color) {
            moves.push_back(Move{currentRow, currentCol, currentRow, currentCol - 2});
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

  // check for castling
  int castleRow;
  if (color == Color::White){
    castleRow = 7;
  }
  else {
    castleRow = 0;
  }

  if (canCastle && row == castleRow && col == 4 && newRow == castleRow && (newCol == 6 || newCol == 2)){
    if (newCol == 6 && board->getSquare(castleRow, 5).getPiece() == nullptr && board->getSquare(castleRow, 6).getPiece() == nullptr){
        // check for rook
        if (board->getSquare(castleRow, 7).getPiece() && board->getSquare(castleRow, 7).getPiece()->getType() == PieceType::Rook){
            Rook *r = dynamic_cast<Rook*>(board->getSquare(castleRow, 7).getPiece());
            if (r->getCanCastle()){
                return true;
            }
        }
    }
    else if (newCol == 2 && board->getSquare(castleRow, 1).getPiece() == nullptr && board->getSquare(castleRow, 2).getPiece() == nullptr && board->getSquare(castleRow, 3).getPiece() == nullptr){
        // check for rook
        if (board->getSquare(castleRow, 0).getPiece() && board->getSquare(castleRow, 0).getPiece()->getType() == PieceType::Rook){
            Rook *r = dynamic_cast<Rook*>(board->getSquare(castleRow, 0).getPiece());
            if (r->getCanCastle()){
                return true;
            }
        }
    }
  }

  return false;
}
