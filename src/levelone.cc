#include "levelone.h"
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <random>

using namespace std;


LevelOne::LevelOne(Color c, Board *b) : Computer{c, b} {}

// random number generator
int getRandom(int min, int max) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distribution(min, max);

    return distribution(gen);
}


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

    while (!pieces.empty()) {
        int randomPieceIndex = getRandom(0, pieces.size() - 1);

        while (pieces[randomPieceIndex] == nullptr) {
            randomPieceIndex = getRandom(0, pieces.size() - 1);
        }

        Piece* chosenPiece = pieces[randomPieceIndex]; // choose random piece

        vector<Move> moves = chosenPiece->getMoves();

        while (!moves.empty()) {
            int randomMoveIndex = getRandom(0, moves.size() - 1);

            Move empty = Move{0, 0, 0, 0};

            while (moves[randomMoveIndex] == empty) {
                randomMoveIndex = getRandom(0, moves.size() - 1);
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

