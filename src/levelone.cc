#include "levelone.h"
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <random>

using namespace std;


LevelOne::LevelOne(Color c, Board *b) : Computer{c, b} {}


Move LevelOne::getMove() {
    // get all pieces of the color
    vector<Piece*> pieces;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
          Piece* p = board->getSquare(i, j).getPiece();
          if ((p != nullptr) && (p->getColor() == color)) {
            pieces.push_back(p);
          }
        }
    }

    if (pieces.size() == 0) return Move{};
    
    // gets random piece and tries move for that piece
    while (!pieces.empty()) {
        int randomPieceIndex = Computer::getRandom(0, pieces.size() - 1);

        while (pieces[randomPieceIndex] == nullptr) {
            randomPieceIndex = Computer::getRandom(0, pieces.size() - 1);
        }

        Piece* chosenPiece = pieces[randomPieceIndex]; // choose random piece
        vector<Move> moves = chosenPiece->getMoves();
        
        // if piece doesn't have valid move, go to next piece
        while (!moves.empty()) {
            int randomMoveIndex = Computer::getRandom(0, moves.size() - 1);

            Move empty = Move{0, 0, 0, 0};

            while (moves[randomMoveIndex] == empty) {
                randomMoveIndex = Computer::getRandom(0, moves.size() - 1);
            }

            Move chosenMove = moves[randomMoveIndex]; // choose random move
            board->move(chosenMove);

            board->undoMove();

            if (!(board->isCheck(color))) {
                return chosenMove;
            }
            else {
                moves[randomMoveIndex] = empty;
            }
        }
        pieces[randomPieceIndex] = nullptr;
    }

    return Move{}; // if no moves available
}

