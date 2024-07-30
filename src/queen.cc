#include "queen.h"
#include "board.h"

using namespace std;

Queen::Queen(Color c, Square *pos,  Board *b)
    : Piece{PieceType::Queen, c, 9, pos, b} {}

vector<Move> Queen::getMoves() const {
    vector<Move> moves;
    if (!pos) return moves;

    // horizontal/vertical movement
    getlinearMoves(1, 0, moves);
    getlinearMoves(-1, 0, moves);
    getlinearMoves(0, 1, moves);
    getlinearMoves(0, -1, moves);

    // diagonal movement
    getlinearMoves(1, 1, moves);
    getlinearMoves(1, -1, moves);
    getlinearMoves(-1, 1, moves);
    getlinearMoves(-1, -1, moves);

    return moves;
}


bool Queen::canMove(int newRow, int newCol) const {
  if (!pos) return false;

  vector<Move> moves;

  int row = pos->getRow();
  int col = pos->getCol();

  Move possibleMove{row, col, newRow, newCol};

  if (row == newRow && col != newCol){
    getlinearMoves(0, 1, moves);
    getlinearMoves(0, -1, moves);

  } else if (col == newCol && row != newRow){
    getlinearMoves(1, 0, moves);
    getlinearMoves(-1, 0, moves);
  } else if (row != newRow && col != newCol){
    getlinearMoves(1, 1, moves);
    getlinearMoves(1, -1, moves);
    getlinearMoves(-1, 1, moves);
    getlinearMoves(-1, -1, moves);
  }

  for (auto move : moves){
    if (move == possibleMove){
      return true;
    }
  }
  return false;
}
