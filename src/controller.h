#ifndef CHESSCONTROLLER_H
#define CHESSCONTROLLER_H

#include <string>
#include "types.h"
#include "player.h"
#include "human.h"
#include "computer.h"
#include "board.h"
#include "display.h"
#include "textDisplay.h"

class ChessController {
private:
    Player *p0;  // white
    Player *p1;  // black
    int p0Score;
    int p1Score;
    // Board board;
    TextDisplay textDisplay;
    int playerTurn;

public:
    ChessController();

    void createGame();
    ~ChessController();
};

#endif // CHESSCONTROLLER_H
