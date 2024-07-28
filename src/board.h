#ifndef BOARD_H
#define BOARD_H

#include "types.h"

#include <vector>

class Board {
 private:
   vector<vector<Square>> board; // Faseeh will add Square class
   int whiteScore;
   int blackScore;

 public:
   Board();
   
   vector<vector<Square>> getSquares();
   Square getSquare(int row, int col);

   void move(Move m);
   bool isCheckmate(Color c);
   bool isStalemate();
   bool isInCheck(Color c); // changed name from UML

   float getWhiteScore();
   float getBlackScore();
   void updateWhiteScore();
   void updateBlackScore();
};

#endif
