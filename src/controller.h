#ifndef CHESSCONTROLLER_H
#define CHESSCONTROLLER_H

#include <string>
#include "player.h"
#include "human.h"
#include "board.h"
#include "view.h"
#include "textView.h"
#include "types.h"
#include <memory>

class ChessController {
private:
    unique_ptr<Player> p0;
    unique_ptr<Player> p1;
    int p0Score;
    int p1Score;
    shared_ptr<Board> board;
    unique_ptr<TextView> textDisplay;
    int playerTurn;

public:
    ChessController();

    void addToScore(Color c, int score);
    void createGame();
    ~ChessController();
};

#endif // CHESSCONTROLLER_H
