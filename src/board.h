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

   void move(Move m);
   bool isCheck(Color c);
   bool isCheckmate(Color c);
   bool isStalemate();

   float getWhiteScore();
   float getBlackScore();
   void updateWhiteScore();
   void updateBlackScore();
};

#endif
