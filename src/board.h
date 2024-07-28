#ifndef BOARD_H
#define BOARD_H

#include "types.h"
#include "square.h"
#include <vector>

using namespace std;

class Board {
 private:
   vector<vector<Square>> board;
   int whiteScore;
   int blackScore;

 public:
   Board();
   ~Board();

   void setupBoard();

   vector<vector<Square>> getSquares();
   Square getSquare(int row, int col);

   virtual void move(Move m) = 0;
   bool isCheck(Color c);
   bool isCheckmate(Color c);
   bool isStalemate();

   float getWhiteScore();
   float getBlackScore();
   virtual void updateWhiteScore() = 0;
   virtual void updateBlackScore() = 0;
};

#endif
