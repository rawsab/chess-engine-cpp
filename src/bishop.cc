#include "bishop.h"

Bishop::Bishop(Color c, Square *pos, Board *b) 
    : Piece{PieceType::Bishop, c, 3, pos, b} {}

vector<Move> Bishop::getMoves() const {
    vector<Move> moves;
    if (!pos) return moves;

    // diagonal movement
    getlinearMoves(1, 1, moves);
    getlinearMoves(1, -1, moves);
    getlinearMoves(-1, 1, moves);
    getlinearMoves(-1, -1, moves);

    return moves;
}

bool Bishop::canMove(int newRow, int newCol) const {
  if (!pos) return false;

  vector<Move> moves;

  int row = pos->getRow();
  int col = pos->getCol();

  Move possibleMove{row, col, newRow, newCol};

  if (row != newRow && col != newCol){
    moves = getMoves();
  }
  
  for (auto move : moves){
    if (move == possibleMove){
      return true;
    }
  }
  return false;
}
