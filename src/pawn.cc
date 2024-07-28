#include "pawn.h"
#include "board.h"

using namespace std;

Pawn::Pawn(Color c, Square *pos): Piece{PieceType::Pawn, c, 1, pos}, canMove2{true} {}

vector<Move> Pawn::getMoves() const { 
    vector<Move> moves;
    if (!pos) return moves;

    int currentRow = pos->getRow();
    int currentCol = pos->getCol();

    if (color == Color::White){
        if (currentRow == 6 && !board->getSquare(currentRow, 5).getPiece() && !board->getSquare(currentRow, 4).getPiece() ){
          moves.push_back(Move{MoveType::Regular, PieceType::NoPiece,
                               PieceType::Pawn, Color::White, Color::White,
                               currentRow, currentCol, 4, currentCol});
        }
    }
    return moves;
}