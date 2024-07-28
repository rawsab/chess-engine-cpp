#ifndef CHESSCONTROLLER_H
#define CHESSCONTROLLER_H

#include <string>
#include "player.h"
#include "human.h"
// #include "Board.h"
#include "View.h"
#include "types.h"

class ChessController {
private:
    Player *p0;  // white
    Player *p1;  // black
    int p0Score;
    int p1Score;
    // Board board;
    int textDisplay;
    int playerTurn;

public:
    ChessController();

    void createGame();
    ~ChessController();
};

#endif // CHESSCONTROLLER_H
