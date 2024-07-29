#include "rook.h"

using namespace std;

Rook::Rook(Color c, Square*pos,  Board *b): Piece{PieceType::Rook, c, 5, pos, b}, canCastle{true} {}

bool Rook::getCanCastle() const { return canCastle; }

void Rook::setCanCastle() { canCastle = false; }

vector<Move> Rook::getMoves() const {
    vector<Move> moves;
    if (!pos) return moves;
    
    getlinearMoves(1, 0, moves);
    getlinearMoves(-1, 0, moves);
    getlinearMoves(0, 1, moves);
    getlinearMoves(0, -1, moves);

    return moves;
}
