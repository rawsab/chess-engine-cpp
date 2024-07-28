#include "square.h"

using namespace std;

Square::Square(int r, int c, Piece* p = nullptr): row{r}, col{c}, piece{p} {}

Square::updateSquare(Piece *p) {
    piece = p;
}

int Square::getRow() const {
    return row;
}
int Square::getCol() const {
    return col;
}

int Square::getPiece() const {
    return piece;
}