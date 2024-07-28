#include "controller.h"

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
<<<<<<< HEAD
            // initialize both to NoColor for now
            p0 = new Human(Color::NoColor);
            p1 = new Human(Color::NoColor);
=======
            p0 = new Human(0);
            p1 = new Human(1);
>>>>>>> d30aeef8b1bfd48f1f5f4f3ac595e29dadb96a7a
        } 
    }
}

ChessController::~ChessController(){
}

