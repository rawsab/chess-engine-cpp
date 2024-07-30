#include "pawn.h"
#include "board.h"

using namespace std;

Pawn::Pawn(Color c, Square *pos, Board *b)
    : Piece{PieceType::Pawn, c, 1, pos, b}, enpassant{false} {}

vector<Move> Pawn::getMoves() const {
  vector<Move> moves;
  vector<Move> validMoves;

  if (!pos) {
    return moves;
  }

  int currentRow = pos->getRow();
  int currentCol = pos->getCol();

  if (getColor() == Color::White){
    // move forwards one
    moves.push_back(Move{currentRow, currentCol, currentRow - 1, currentCol});
    // move forwards two
    if (currentRow == 6){
      moves.push_back(Move{currentRow, currentCol, currentRow - 2, currentCol});
    }
    // diagonal captures
    if (currentCol - 1 >= 0){
      moves.push_back(Move{currentRow, currentCol, currentRow - 1, currentCol - 1});
    }
    if (currentCol + 1 < 8){
      moves.push_back(Move{currentRow, currentCol, currentRow - 1, currentCol + 1});
    }
  }
  else {
    // move forwards one
    moves.push_back(Move{currentRow, currentCol, currentRow + 1, currentCol});
    // move forwards two
    if (currentRow == 1){
      moves.push_back(Move{currentRow, currentCol, currentRow + 2, currentCol});
    }
    // diagonal captures
    if (currentCol - 1 >= 0){
      moves.push_back(Move{currentRow, currentCol, currentRow + 1, currentCol - 1});
    }
    if (currentCol + 1 < 8){
      moves.push_back(Move{currentRow, currentCol, currentRow + 1, currentCol + 1});
    }
  }

  for (auto move : moves){
    if (canMove(move.nr, move.nc)){
      validMoves.push_back(move);
    }
  }

  return validMoves;  
}

bool Pawn::canMove(int newRow, int newCol) const {
  if (!pos){
    return false;
  }

  int row = pos->getRow();
  int col = pos->getCol();

  if (newRow < 0 || newRow >= 8 || newCol < 0 || newCol >= 8){
    return false;
  }

  // if moving forward and there is a piece in the way
  if ((newCol == col) && (board->getSquare(newRow, newCol).getPiece())){
    return false;
  }

  // two square move blocked
  if (getColor() == Color::White && row == 6 && newRow == row - 2 && board->getSquare(row - 1, newCol).getPiece()){
      return false;
  }
  else if (getColor() == Color::Black && row == 1 && newRow == row + 2 && board->getSquare(row + 1, newCol).getPiece()){
      return false;
  }

  // cannot move backwards
  if (getColor() == Color::White){
    if (newRow != row - 1 && newRow != row - 2){
      return false;
    }
  }
  else {
    if (newRow != row + 1 && newRow != row + 2){
      return false;
    }
  }

  // diagonal movement restrictions
  if (newCol > col + 1 || newCol < col - 1){
    return false;
  }
  if (newCol != col){
    if (newRow > row + 1 || newRow < row - 1){
      return false;
    }
    if (getColor() == Color::White && board->getSquare(newRow, newCol).getPiece()->getColor() != Color::Black){
      return false;
    }
    if (getColor() == Color::Black && board->getSquare(newRow, newCol).getPiece()->getColor() != Color::White){
      return false;
    }
  }

  return true;  
}
