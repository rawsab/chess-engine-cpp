#include "controller.h"
#include "player.h"
#include "human.h"
#include "board.h"
#include "view.h"
#include "types.h"

using namespace std;

ChessController::ChessController() : p0(NULL), p1(NULL), textDisplay(NULL), p0Score(0), p1Score(0) {
    board = new Board();
    textDisplay = new TextView();
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
            p0 = new Human(Color::White);
            p1 = new Human(Color::Black);
        } else if (cmd == "move") {
            // read input
            string startPos, endPos;
            cin >> startPos >> endPos;

            Move turn; // make move turn off move we need to make

            // checks if move is valid for player
            bool isValidMove;
            if (playerTurn % 2) {
                turn = p0->getMove();
                isValidMove = board->canMove(turn, Color::White);
            } else {
                turn = p1->getMove();
                isValidMove = board->canMove(turn, Color::Black);
            }

            // change to isValidMove
            if (true) {
                board->move(turn);
                textDisplay->print(); // prints board
                playerTurn++;
            } else {
                cout << "Invalid move" << endl;
            }

        }

    }
}

ChessController::~ChessController() {}

