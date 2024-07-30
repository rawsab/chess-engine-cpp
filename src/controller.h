#ifndef CHESSCONTROLLER_H
#define CHESSCONTROLLER_H

#include <string>
#include "player.h"
#include "human.h"
#include "board.h"
#include "view.h"
#include "textView.h"
#include "types.h"
#include "graphicsView.h"

class ChessController {
private:
    Player *p0;  // white
    Player *p1;  // black
    int p0Score;
    int p1Score;
    Board *board;
    TextView *textDisplay;
    GraphicsView *graphicsDisplay;
    int playerTurn;

   public:
    ChessController();

    void addToScore(Color c, int score);
    void createGame();
    ~ChessController();
};

#endif // CHESSCONTROLLER_H
