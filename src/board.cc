#include "board.h"
#include <iostream>
#include <string>

Board::Board() : whiteScore(0), blackScore(0) {
    board = vector<vector<Square>>(8, vector<Square>(8, Square(0, 0, nullptr)));

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            board[i][j] = Square{i, j, nullptr};
        }
    }

    // board[6][1].updateSquare(new Pawn(Color::Black, &board[6][1], this));
    // // Setup pawns
    for (int i = 0; i < 8; ++i) {
        board[1][i].updateSquare(new Pawn(Color::Black, &board[1][i], this));
        board[6][i].updateSquare(new Pawn(Color::White, &board[6][i], this));
    }

    // Setup other pieces
    // White
    board[0][0].updateSquare(new Rook(Color::Black, &board[0][0], this));
    board[0][7].updateSquare(new Rook(Color::Black, &board[0][7], this));
    board[0][1].updateSquare(new Knight(Color::Black, &board[0][1], this));
    board[0][6].updateSquare(new Knight(Color::Black, &board[0][6], this));
    board[0][2].updateSquare(new Bishop(Color::Black, &board[0][2], this));
    board[0][5].updateSquare(new Bishop(Color::Black, &board[0][5], this));
    board[0][3].updateSquare(new Queen(Color::Black, &board[0][3], this));
    board[0][4].updateSquare(new King(Color::Black, &board[0][4], this));

    // Black
    board[7][0].updateSquare(new Rook(Color::White, &board[7][0], this));
    board[7][7].updateSquare(new Rook(Color::White, &board[7][7], this));
    board[7][1].updateSquare(new Knight(Color::White, &board[7][1], this));
    board[7][6].updateSquare(new Knight(Color::White, &board[7][6], this));
    board[7][2].updateSquare(new Bishop(Color::White, &board[7][2], this));
    board[7][5].updateSquare(new Bishop(Color::White, &board[7][5], this));
    board[7][3].updateSquare(new Queen(Color::White, &board[7][3], this));
    board[7][4].updateSquare(new King(Color::White, &board[7][4], this));
}

Piece* Board::createPiece(const string& p, int r, int c) {
    Piece* piece = nullptr;
    Color color = (isupper(p[0]) ? Color::White : Color::Black);

    switch (tolower(p[0])) {
        case 'k':
            piece = new King(color, &board[r][c], this);
            break;
        case 'q':
            piece = new Queen(color, &board[r][c], this);
            break;
        case 'n':
            piece = new Knight(color, &board[r][c], this);
            break;
        case 'b':
            piece = new Bishop(color, &board[r][c], this);
            break;
        case 'r':
            piece = new Rook(color, &board[r][c], this);
            break;
        case 'p':
            piece = new Pawn(color, &board[r][c], this);
            break;
        default:
            // Handle invalid piece input if necessary
            break;
    }
    return piece;
}

void Board::updatePiece(const string& p, int r, int c) {
    board[r][c].updateSquare(createPiece(p, r, c));
    return;
}


void Board::clearBoard() {
    board = vector<vector<Square>>(8, vector<Square>(8, Square(0, 0, nullptr)));

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            board[i][j] = Square(i, j, nullptr);
        }
    }
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
  Piece* currentPiece = getSquare(m.r, m.c).getPiece();
  if (!currentPiece || currentPiece->getColor() != c) return false;

    if(currentPiece->canMove(m.nr, m.nc)) {
        Move turn {m.r, m.c, m.nr, m.nc};
        // Make a temporary move
        Board::move(turn);
        bool isInCheck = isCheck(c);
        // Undo the move
        undoMove();

        // make sure move doesnt put our king in check
        if (!isInCheck) {
            return true;
        }
    }
    return false;
}

void Board::move(Move m) {
    Square* src = &board[m.r][m.c];
    Square* dst = &board[m.nr][m.nc];
    Piece* p = src->getPiece();
    Piece* dstOccupant = dst->getPiece();
    dst->updateSquare(p);
    src->updateSquare(nullptr);
    p->updateSquare(dst);

    pastMoves.push(MoveHistory{m, dstOccupant});
}

void Board::undoMove() {

    MoveHistory m = this->popLastMove();

    Square* src = &board[m.move.nr][m.move.nc];
    Square* dst = &board[m.move.r][m.move.c];
    Piece* p = src->getPiece();
    dst->updateSquare(p);
    src->updateSquare(m.captured);
    p->updateSquare(dst);

}

bool Board::isCheck(Color c) {
    Square* kingSquare = nullptr;
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            Square& square = board[row][col];
            Piece* piece = square.getPiece();
            if (piece && piece->getType() == PieceType::King && piece->getColor() == c) {
                kingSquare = &square;
                break;
            }
        }
        if (kingSquare) break;
    }

    if (!kingSquare) return false; // King not found

    // Check all pieces of the opposite color to see if they can attack the king
    Color opposingColor = (c == Color::White) ? Color::Black : Color::White;
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            Square& square = board[row][col];
            Piece* piece = square.getPiece();
            if (piece && piece->getColor() == opposingColor) {
                std::vector<Move> moves = piece->getMoves();
                for (const Move& move : moves) {
                    if (move.nr == kingSquare->getRow() && move.nc == kingSquare->getCol()) {
                        return true; // King is in check
                    }
                }
            }
        }
    }

    return false; // King is not in check
}

bool Board::isCheckmate(Color c) {
    // Step 2: Check if any move can get the king out of check
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            Square& square = board[row][col];
            Piece* piece = square.getPiece();
            if (piece && piece->getColor() == c) {
                std::vector<Move> moves = piece->getMoves();
                for (const Move& move : moves) {
                    Move turn {move.r, move.c, move.nr, move.nc};

                    // Make a temporary move
                    Board::move(turn);

                    bool isStillInCheck = isCheck(c);

                    // Undo the move
                    undoMove();

                    // If the move gets the king out of check, it's not checkmate
                    if (!isStillInCheck) {
                        return false;
                    }
                }
            }
        }
    }

    // If no valid move gets the king out of check, it's checkmate
    return true;
}

bool Board::isStalemate(Color c) {
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

void Board::addPastMoves(Move& m, Piece* p) { 
    pastMoves.push(MoveHistory{std::move(m), p});
}

MoveHistory Board::popLastMove() { 
    MoveHistory lastMove = pastMoves.top();
    pastMoves.pop();
    return lastMove;
}

stack<MoveHistory> Board::getPastMoves() { 
    return pastMoves; 
}