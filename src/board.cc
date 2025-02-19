#include "board.h"
#include <iostream>
#include <string>

Board::Board() : whiteScore(0), blackScore(0) {
    setupBoard();
}

void Board::setupBoard() {
    board = vector<vector<Square>>(8, vector<Square>(8, Square(0, 0, nullptr)));

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            board[i][j] = Square{i, j, nullptr};
        }
    }

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
    
    // creates piece based on color and type
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
            break;
    }
    return piece;
}

// updates piece at square
void Board::updatePiece(const string& p, int r, int c) {
    board[r][c].updateSquare(createPiece(p, r, c));
    return;
}


void Board::clearBoard() {
    board = vector<vector<Square>>(8, vector<Square>(8, Square(0, 0, nullptr)));
    // sets all board parts to nullptr
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            board[i][j] = Square(i, j, nullptr);
        }
    }
}


Board::~Board() { }

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
        // makes temporary move
        Board::move(turn);
        bool isInCheck = isCheck(c);
        // undo move
        undoMove();

        // make sure move doesnt put our king in check
        if (!isInCheck) {
            return true;
        }
    }
    return false;
}

void Board::move(Move m) {
    // moves src piece to dest
    Square* src = &board[m.r][m.c];
    Square* dst = &board[m.nr][m.nc];
    Piece* p = src->getPiece();
    Piece* dstOccupant = dst->getPiece();
    dst->updateSquare(p);
    src->updateSquare(nullptr);
    if(p) {
        p->updateSquare(dst);
    }
    // castling logic 
    if ((p->getType() == PieceType::King) && (m.nc - m.c == 2 || m.nc - m.c == -2)) {
        int rookR = (p->getColor() == Color::White) ? 7 : 0;
        int rookC = (m.nc > m.c) ? 7 : 0;
        int newRookC = (m.nc > m.c) ? m.nc - 1 : m.nc + 1;

        King *k = dynamic_cast<King*>(p);
        if (k->getCanCastle()){
            Square* rookSquare = &board[rookR][rookC];
            Rook *r = dynamic_cast<Rook*>(rookSquare->getPiece());

            if (r->getCanCastle()){
                Square* newRookSquare = &board[rookR][newRookC];
                r->updateSquare(newRookSquare);
                rookSquare->updateSquare(nullptr);
                newRookSquare->updateSquare(r);

                r->setCanCastle(false);
                k->setCanCastle(false);
            }
            else {
                return; // fix this
            }
        }
        else {
            return; // fix this
        }

        Square* rookSquare = &board[m.r][rookC];
        Square* newRookSquare = &board[m.r][newRookC];

        // move rook and king
        Piece* rook = rookSquare->getPiece();
    }

    // update castling status if king or rook moved
    if (p->getType() == PieceType::King) {
        King* k = dynamic_cast<King*>(p);
        k->setCanCastle(false);
    }
    if (p->getType() == PieceType::Rook) {
        Rook* r = dynamic_cast<Rook*>(p);
        r->setCanCastle(false);
    }

    // enpassant logic
    // if no dest exists, set to nullptr
    if (m.nc != m.c && !dstOccupant){
        if (p->getColor() == Color::White && m.r == 3 && isLastMoveTwoSquarePawnMove(m.nc)){
          board[m.nr + 1][m.nc].updateSquare(nullptr);
        }
        if (p->getColor() == Color::Black && m.r == 4 && isLastMoveTwoSquarePawnMove(m.nc)){
          board[m.nr - 1][m.nc].updateSquare(nullptr);
        }
    }

    // pawn promotion
    if ((p->getType() == PieceType::Pawn) && (m.nr == 0 || m.nr == 7)) {
        Piece* promotedPiece = nullptr;
        string promotionType;
        while (promotionType != "q" && promotionType != "r" && promotionType != "b" && promotionType != "n") {
            cout << "What piece you would like to promote to (b, n, q, r)? ";
            cin >> promotionType;
            promotionType = tolower(promotionType[0]);
        }
        // for creating black or white pieces (createPiece)
        if (p->getColor() == Color::White) {
            promotionType = toupper(promotionType[0]);
        }
        else {
            promotionType = tolower(promotionType[0]);
        }
        promotedPiece = createPiece(promotionType, m.nr, m.nc);
        dst->updateSquare(promotedPiece);
        promotedPiece->updateSquare(dst);
    }

    // add to move history
    addPastMoves(m, p->getType(), dstOccupant);
}

void Board::undoMove() {
    // undos last move in stack
    MoveHistory m = this->popLastMove();

    Square* src = &board[m.move.nr][m.move.nc];
    Square* dst = &board[m.move.r][m.move.c];
    Piece* p = src->getPiece();
    dst->updateSquare(p);
    src->updateSquare(m.captured);
    if(p) {
        p->updateSquare(dst);
    }
}

// checks ic color c's king is in check
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

    if (!kingSquare) return false; // king not found

    // checks pieces of opposite color to see if they can move to king's pos
    Color opposingColor = (c == Color::White) ? Color::Black : Color::White;
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            Piece* piece = getSquare(row, col).getPiece();
            if (piece && piece->getColor() == opposingColor) {
                std::vector<Move> moves = piece->getMoves();
                for (const Move& move : moves) {
                    if (move.nr == kingSquare->getRow() && move.nc == kingSquare->getCol()) {
                        return true; // check
                    }
                }
            }
        }
    }

    return false;
}

bool Board::isCheckmate(Color c) {
    // check if any moves get king out of check
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            Square& square = board[row][col];
            Piece* piece = square.getPiece();
            if (piece && piece->getColor() == c) {
                std::vector<Move> moves = piece->getMoves();
                for (const Move& move : moves) {
                    Move turn {move.r, move.c, move.nr, move.nc};

                    // makes temporary move
                    Board::move(turn);

                    bool isStillInCheck = isCheck(c);

                    // undo move
                    undoMove();

                    // valid move gets king out of check
                    if (!isStillInCheck) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

bool Board::isStalemate(Color c) {
    // if player in check, not stale
    if (isCheck(c)) {
        return false;
    }

    // checks if any legal moves available 
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            Piece* piece = getSquare(row, col).getPiece();

            if (piece && piece->getColor() == c) {
                std::vector<Move> moves = piece->getMoves();
                for (const Move& move : moves) {
                    // makes temporary move
                    Move turn {move.r, move.c, move.nr, move.nc};
                    Board::move(turn);

                    bool isStillInCheck = isCheck(c);

                    // undo move
                    undoMove();

                    // not stalemate
                    if (!isStillInCheck) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
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

void Board::addPastMoves(Move& m, PieceType movedType, Piece* captured) { 
    pastMoves.push(MoveHistory{std::move(m), movedType, captured});
}

// remove last move from stack
MoveHistory Board::popLastMove() { 
    MoveHistory lastMove = pastMoves.top();
    pastMoves.pop();
    return lastMove;
}

stack<MoveHistory> Board::getPastMoves() { 
    return pastMoves; 
}

bool Board::isLastMoveTwoSquarePawnMove(int col) const {
    if (pastMoves.empty()) return false;

    MoveHistory lastMove = pastMoves.top();
    Move move = lastMove.move;

     // Check if the last move was a two-square pawn move
    if (lastMove.movedType == PieceType::Pawn && abs(move.r - move.nr) == 2) {
        // Check if the target column matches the given column
        return move.nc == col;
    }

    return false;
}


bool Board::isCastlingPossible(Color color, bool kingSide) const {
    int row = (color == Color::White) ? 7 : 0;
    int kingCol = 4;
    int rookCol = kingSide ? 7 : 0;

    Square kingSquare = board[row][kingCol];
    Square rookSquare = board[row][rookCol];
    King* king = dynamic_cast<King*>(kingSquare.getPiece());
    Rook* rook = dynamic_cast<Rook*>(rookSquare.getPiece());

    if (!king || !rook || !king->getCanCastle() || !rook->getCanCastle()) return false;

    // Check the spaces between the king and rook
    int step = kingSide ? 1 : -1;
    for (int col = kingCol + step; col != rookCol; col += step) {
        if (board[row][col].getPiece() != nullptr) return false;
    }

    // Check if the king passes through or ends up in a square under attack
    for (int col = kingCol; col != kingCol + 2 * step; col += step) {
        if (isSquareUnderAttack(row, col, color)) return false;
    }

    return true;
}

bool Board::isSquareUnderAttack(int row, int col, Color color) const {
    // Check if any opponent piece can move to the specified square
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            Piece* piece = board[i][j].getPiece();
            if (piece && piece->getColor() != color) {
                vector<Move> opponentMoves = piece->getMoves();
                for (const Move& move : opponentMoves) {
                    if (move.nr == row && move.nc == col) {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}
