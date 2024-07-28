#include "board.h"

Board::Board() : whiteScore{0}, blackScore{0} {
    // initialize 8x8 board
    board = vector<vector<Square>>(8, vector<Square>(8));
    setupBoard();
}

void Board::setupBoard() {
    // to implement
}

vector<vector<Square>> Board::getSquares() {
    return board;
}

Square Board::getSquare(int row, int col) {
    if (row < 0 || row > 7 || col < 0 || col > 7) {
        throw "Square out of bounds";
    }
    return board[row][col];
}

bool Board::isCheck(Color c) {
    // to implement
}

bool Board::isCheckmate(Color c) {
    // to implement
}

bool Board::isStalemate() {
    // to implement
}

float Board::getWhiteScore() {
    return whiteScore;
}

float Board::getBlackScore() {
    return blackScore;
}

Board::~Board() {}
