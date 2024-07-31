#ifndef CHESSCONTROLLER_H
#define CHESSCONTROLLER_H

#include <string>
#include "player.h"
#include "human.h"
#include "board.h"
#include "view.h"
#include "textView.h"
#include "types.h"
#include "graphicsView.h";

class ChessController {
private:
    Player *p0;  // white
    Player *p1;  // black
    int p0Score;
    int p1Score;
    Board *board;
    vector<View *> observers;
    int playerTurn;

public:
    ChessController();

    void printScore();
    void createGame();
    void registerWin();
    void registerStalemate();
    void playComputerBlack();
    void playComputerWhite();
    void notifyObservers();
    ~ChessController();
};

#endif // CHESSCONTROLLER_H
