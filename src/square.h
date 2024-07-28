#ifndef SQUARE_H
#define SQUARE_H

#include "types.h"

class Piece;

class Square {
 private:
    Piece* piece;
    int row;
    int col;

 public:
    Square(int r, int c, Piece* p = nullptr);
    ~Square() {};

    void updateSquare(Piece* p);
    Piece* getPiece() const;
    int getRow() const;
    int getCol() const;
};

#endif
