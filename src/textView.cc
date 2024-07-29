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
                if ((i + j) % 2 == 0) cout << "  ";
                else cout << "_ ";
                continue;
            } 
            PieceType pp = curPiece->getType();
            Color pc = curPiece->getColor();
            switch (pp) {
                case PieceType::Bishop:
                    cout << (pc == Color::White ? "B" : "b");
                    break;
                case PieceType::Rook:
                    cout << (pc == Color::White ? "R" : "r");
                    break;
                case PieceType::Knight:
                    cout << (pc == Color::White ? "N" : "n");
                    break;
                case PieceType::King:
                    cout << (pc == Color::White ? "K" : "k");
                    break;
                case PieceType::Queen:
                    cout << (pc == Color::White ? "Q" : "q");
                    break;
                case PieceType::Pawn:
                    cout << (pc == Color::White ? "P" : "p");
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
