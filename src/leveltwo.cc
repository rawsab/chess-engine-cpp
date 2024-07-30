#include "leveltwo.h"
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;


LevelTwo::LevelTwo(Color c, Board *b) : Computer{c, b} {}

Move LevelTwo::getMove() {
    std::vector<Move> capturingOrCheckingMoves;
    std::vector<Move> otherMoves;

    // gets all pieces of the color
    vector<Piece*> pieces;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
          Piece* p = board->getSquare(i, j).getPiece();
          if ((p != nullptr) && (p->getColor() == color)) {
            pieces.push_back(p);
          }
        }
    }


    // iterates through all the pieces
    for (Piece* piece : pieces) {
        if (piece != nullptr && piece->getColor() == color) {
            vector<Move> moves = piece->getMoves();
            for (Move& move : moves) {
                Piece* targetPiece = board->getSquare(move.nr, move.nc).getPiece();

                // Prioritize capturing moves
                if (targetPiece && targetPiece->getColor() != color) {
                    capturingOrCheckingMoves.push_back(move);
                } else {
                    Move turn {move.r, move.c, move.nr, move.nc};
                    if(board->canMove(turn, color)){
                        // makes temporary move
                        board->move(turn);

                        bool isOurKingInCheck = board->isCheck(color);
                        bool isCheck = board->isCheck((color == Color::White) ? Color::Black : Color::White);

                        // undo move
                        board->undoMove();

                        // invalid move
                        if(isOurKingInCheck) {
                            continue;
                        }

                        // prioritize capture/checking moves
                        if (isCheck) {
                            capturingOrCheckingMoves.push_back(move);
                        } else {
                            otherMoves.push_back(move);
                        }

                    }
                }
            }
        }
    }



    // choose move based on priority
    Move chosenMove;
    if (!capturingOrCheckingMoves.empty()) {
        int randomMoveIndex = getRandom(0, capturingOrCheckingMoves.size() - 1);
        return capturingOrCheckingMoves[randomMoveIndex];
    } else if (!otherMoves.empty()) {
        int randomMoveIndex = getRandom(0, otherMoves.size() - 1);
        return otherMoves[randomMoveIndex];
    } else {
        return Move{-1, -1, -1, -1}; // no valid moves available
    }
}
