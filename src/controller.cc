#include "controller.h"
#include "player.h"
#include "human.h"
#include "board.h"
#include "View.h"
#include "types.h"

using namespace std;

ChessController::ChessController() : p0(NULL), p1(NULL), textDisplay(NULL), p0Score(0), p1Score(0) {
    // board = new Board();
    // board->setupBoard();
}


void ChessController::createGame(){
    string cmd;

    while (cin >> cmd) {
        if (cmd == "game") {
            string firstPlayer, secondPlayer;
            cin >> firstPlayer >> secondPlayer;
            
            if (firstPlayer != "human" && secondPlayer != "human") {
                cerr << "Players can't both be computers" << endl;
                continue;
            }

            // for now set both players to human
            // initialize both to NoColor for now
            p0 = new Human(Color::NoColor);
            // p1 = new Human(Color::NoColor);
        } 
    }
}

ChessController::~ChessController() {}

