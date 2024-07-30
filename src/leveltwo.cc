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


    // Iterate through all the pieces of the given color
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            Piece* piece = board->getSquare(row, col).getPiece();
            if (piece != nullptr && piece->getColor() == color) {
                std::vector<Move> moves = piece->getMoves();
                for (const Move& move : moves) {
                    Piece* targetPiece = board->getSquare(move.nr, move.nc).getPiece();

                    // Prioritize capturing moves
                    if (targetPiece && targetPiece->getColor() != color) {
                        capturingOrCheckingMoves.push_back(move);
                    } else {
                        Move turn {move.r, move.c, move.nr, move.nc};

                        // cout << "trying move " << (color == Color::Black ? "Black" : "White") << move.r << move.c << move.nr << move.nc << endl;
                        if(board->canMove(turn, color)){
                            // cout << "successful move " << move.r << move.c << move.nr << move.nc << endl;

                            // Make a temporary move
                            board->move(turn);

                            bool isCheck = board->isCheck((color == Color::White) ? Color::Black : Color::White);

                            // Undo the move
                            board->undoMove();

                            // Prioritize checking moves
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
    }



    // Choose a move based on the priority
    Move chosenMove;
    if (!capturingOrCheckingMoves.empty()) {
        return capturingOrCheckingMoves.front();
    } else if (!otherMoves.empty()) {
        return otherMoves.front();
    } else {
        return Move{-1, -1, -1, -1}; // No valid moves available
    }
}
