#ifndef SQUARE_H
#define SQUARE_H

#include "types.h"
#include "piece.h"

class Square {
 private:
    Piece* piece;
    int row;
    int col;

 public:
    Square(int r, int c) ;
    Square(int r, int c, Piece* p) ;
    ~Square() {};

    void updateSquare(Piece* p);
    Piece* getPiece();
};

#endif
