#include "computer.h"
#include <stdlib.h>
#include <algorithm>

using namespace std;

Computer::Computer(Color c, Board *b) : Player{c}, board{b} {}


LevelOne::LevelOne(Color c, Board *b) : Computer{c, b} {}

void LevelOne::generateMove() {
    // get all pieces of the color
    vector<Piece*> pieces;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
          Piece* p = board->getSquare(i, j).getPiece();
          if (p && p->getColor() == color) {
            pieces.push_back(p);
          }
        }
    }

    if (pieces.size() == 0) return;

    while (!pieces.empty()) {
        Piece* chosenPiece = pieces[rand() % pieces.size()]; // choose random piece
        vector<Move> moves = chosenPiece->getMoves();
        
        while (!moves.empty()) {
            Move chosenMove = moves[rand() % moves.size()]; // choose random move
            board->move(chosenMove);
            if (!(board->isCheck(color))) {
                return;
            }
            else {
                board->undoMove();
                moves.erase(remove(moves.begin(), moves.end(), chosenMove), moves.end());
            }
        }

        pieces.erase(remove(pieces.begin(), pieces.end(), chosenPiece), pieces.end());
    }
    
    return;
}


