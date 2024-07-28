#include "board.h"
#include "square.h"

Board::Board() : whiteScore(0), blackScore(0) {
    setupBoard();
}

Board::~Board() {
}

void Board::setupBoard() {
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

bool Board::canMove(Move m, Color c) {
    return false;
}

void Board::move(Move m) {
}

bool Board::isCheck(Color c) {
    return false;
}

bool Board::isCheckmate(Color c) {
    return false;
}

bool Board::isStalemate() {
    return false;
}

float Board::getWhiteScore() {
    return whiteScore;
}

float Board::getBlackScore() {
    return blackScore;
}

void Board::updateWhiteScore() {
}

void Board::updateBlackScore() {
}

