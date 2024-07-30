#include "square.h"

using namespace std;

Square::Square(int r, int c, Piece* p): row{r}, col{c}, piece{p} {}

void Square::updateSquare(Piece *p) {
    piece = p;
}

int Square::getRow() const {
    return row;
}
int Square::getCol() const {
    return col;
}

// gets piece at square
Piece* Square::getPiece() const {
    return piece;
}
