#include "rook.h"

using namespace std;

Rook::Rook(Color c, Square*pos): Piece{PieceType::Rook, c, 5, pos}, canCastle{true} {}

bool Rook::getCanCastle() const { return canCastle; }

void Rook::setCanCastle() { canCastle = false; }

vector<Move> Rook::getMoves() const {
    vector<Move> moves;
    // Rooks can move horizontally or vertically until they hit another piece or the edge of the board
    // If we just figure out the max bounds, everything less thatn the max bound is a valid move. 


}
