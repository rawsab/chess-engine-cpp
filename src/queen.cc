#include "queen.h"
#include "board.h"

using namespace std;

Queen::Queen(Color c, Square *pos,  Board *b)
    : Piece{PieceType::Knight, c, 3, pos, b} {}

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
