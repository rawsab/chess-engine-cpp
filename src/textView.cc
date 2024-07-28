#include "textView.h"
#include "types.h"
#include <iostream>

using namespace std;

TextView::TextView(Board* b) : View(), board {b} {
    // Constructor
}


void TextView::print() {
    // Print the board
    cout << " ,-----------------," << endl;
    for (int i = 0; i < 8; ++i) {
        cout << i << "| ";
        for (int j = 0; j < 8; ++j) {
            Piece* curPiece = board->getSquare(i, j).getPiece();
            if (curPiece == nullptr) {
                cout << "  ";
                continue;
            } 
            PieceType pp = curPiece->getType();
            switch (pp) {
                case PieceType::Bishop:
                    cout << "b";
                    break;
                case PieceType::Rook:
                    cout << "r";
                    break;
                case PieceType::Knight:
                    cout << "n";
                    break;
                case PieceType::King:
                    cout << "k";
                    break;
                case PieceType::Queen:
                    cout << "q";
                    break;
                case PieceType::Pawn:
                    cout << "p";
                    break;
                default:
                    cout << " ";
                    break;
            }
            cout << " ";
        }
        cout << "|" << endl;
    }
    cout << " '-----------------' " << endl;
    cout << "   a b c d e f g h" << endl;
}

TextView::~TextView() {
    // Destructor
}
