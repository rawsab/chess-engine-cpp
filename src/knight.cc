#include "knight.h"
#include "board.h"

using namespace std;

Knight::Knight(Color c, Square *pos)
    : Piece{PieceType::Knight, c, 3, pos} {}


Move Knight::getKnightMove(int currentRow, int currentCol, int rowD, int colD) const {
    Move move;

    if (currentRow + rowD < 8 && currentRow + rowD >= 0 && currentCol + colD < 8 && currentCol + colD >= 0) {
        if (board->getSquare(currentRow + rowD, currentCol + colD).getPiece()->getColor() != color) {
            move = Move{currentRow, currentCol, currentRow + rowD, currentCol + colD};
        }
    }
    return move;
}

vector<Move> Knight::getMoves() const {
    vector<Move> moves;
    if (!pos) return moves;

    int currentRow = pos->getRow();
    int currentCol = pos->getCol();

    moves.push_back(getKnightMove(currentRow, currentCol, 2, 1));
    moves.push_back(getKnightMove(currentRow, currentCol, 2, -1));
    moves.push_back(getKnightMove(currentRow, currentCol, -2 , 1));
    moves.push_back(getKnightMove(currentRow, currentCol, -2, -1));
    moves.push_back(getKnightMove(currentRow, currentCol, 1, 2));
    moves.push_back(getKnightMove(currentRow, currentCol, 1, -2));
    moves.push_back(getKnightMove(currentRow, currentCol, -1, 2));
    moves.push_back(getKnightMove(currentRow, currentCol, -1, -2));

    return moves;
}
