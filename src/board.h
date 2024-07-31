#ifndef BOARD_H
#define BOARD_H

#include "types.h"
#include "square.h"
#include "rook.h"
#include "bishop.h"
#include "king.h"
#include "knight.h"
#include "queen.h"
#include "pawn.h"
#include <vector>
#include <stack>

using namespace std;


class Board {
 private:
   vector<vector<Square>> board;
   int whiteScore;
   int blackScore;
   stack<MoveHistory> pastMoves;

  public:
   Board();
   ~Board();

   void clearBoard();

   vector<vector<Square>> getSquares();
   Square getSquare(int row, int col);

   bool canMove(Move m, Color c); // make virtual
   void move(Move m); // make virtual
   void undoMove();
   void setupBoard();
   bool isCheck(Color c);
   bool isCheckmate(Color c);
   bool isStalemate(Color c);
   Piece* createPiece(const string& p, int r, int c);
   void updatePiece(const string& p, int r, int c);
   float getWhiteScore();
   float getBlackScore();
   stack<MoveHistory> getPastMoves();
   void addPastMoves(Move& m, PieceType movedType, Piece* captured = nullptr);
   MoveHistory popLastMove();
   void updateWhiteScore();  // make virtual
   void updateBlackScore(); // make virtual
  bool isLastMoveTwoSquarePawnMove(int col) const;
  bool isCastlingPossible(Color color, bool kingSide) const;
  bool isSquareUnderAttack(int row, int col, Color color) const;
};

#endif
