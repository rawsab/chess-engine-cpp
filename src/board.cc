#include "board.h"
#include "square.h"
#include "pawn.h"

Board::Board() : whiteScore(0), blackScore(0) {
    board = vector<vector<Square>>(8, vector<Square>(8, Square(0, 0, nullptr)));

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            board[i][j] = Square(i, j, nullptr);
        }
    }

    board[6][1].updateSquare(new Pawn(Color::White, &board[6][1]));
    // // Setup pawns
    // for (int i = 0; i < 8; ++i) {
    //     board[1][i].updateSquare(new Pawn(Color::White, &board[1][i]));
    //     board[6][i].updateSquare(new Pawn(Color::Black, &board[6][i]));
    // }

    // // Setup other pieces
    // // White
    // board[0][0].updateSquare(new Rook(Color::White, &board[0][0]));
    // board[0][7].updateSquare(new Rook(Color::White, &board[0][7]));
    // board[0][1].updateSquare(new Knight(Color::White, &board[0][1]));
    // board[0][6].updateSquare(new Knight(Color::White, &board[0][6]));
    // board[0][2].updateSquare(new Bishop(Color::White, &board[0][2]));
    // board[0][5].updateSquare(new Bishop(Color::White, &board[0][5]));
    // board[0][3].updateSquare(new Queen(Color::White, &board[0][3]));
    // board[0][4].updateSquare(new King(Color::White, &board[0][4]));

    // // Black
    // board[7][0].updateSquare(new Rook(Color::Black, &board[7][0]));
    // board[7][7].updateSquare(new Rook(Color::Black, &board[7][7]));
    // board[7][1].updateSquare(new Knight(Color::Black, &board[7][1]));
    // board[7][6].updateSquare(new Knight(Color::Black, &board[7][6]));
    // board[7][2].updateSquare(new Bishop(Color::Black, &board[7][2]));
    // board[7][5].updateSquare(new Bishop(Color::Black, &board[7][5]));
    // board[7][3].updateSquare(new Queen(Color::Black, &board[7][3]));
    // board[7][4].updateSquare(new King(Color::Black, &board[7][4]));
}

Board::~Board() {
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
    return true;
}

void Board::move(Move m) {
    if (!canMove(m, board[m.r][m.c].getPiece()->getColor())) return;

    Square src = getSquare(m.r, m.c);
    Square dst = getSquare(m.nr, m.nc);
    Piece* p = src.getPiece();
    dst.updateSquare(p);
    src.updateSquare(nullptr);

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

