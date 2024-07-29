#include "controller.h"
#include "player.h"
#include "human.h"
#include "board.h"
#include "view.h"
#include "types.h"
#include <string>

using namespace std;

ChessController::ChessController() : p0(nullptr), p1(nullptr), textDisplay(nullptr), p0Score(0), p1Score(0), playerTurn(0) {
    board = new Board();
    textDisplay = new TextView(board);
    // board->setupBoard();
}


void ChessController::createGame(){
    string cmd;
    bool setupMode = true;

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

            textDisplay->print(); // prints board
            setupMode = false;
        } else if (cmd == "move") {
            // read input
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
            if (isValidMove) {
                board->move(turn);
                textDisplay->print(); // prints board
                playerTurn++;
            } else {
                cout << "Invalid move" << endl;
            }

        } else if (cmd == "setup") {
            if (!setupMode) {
                cout << "Can not enter setup mode" << endl;
                continue;
            }
            board->clearBoard();

            string op;
            while (cin >> op) {
                if (op == "+") {
                    string piece, pos;
                    cin >> piece >> pos;

                    // sets piece at position
                    int r, c;
                    if (pos.size() == 2) {
                        c = pos[0] - 'a';
                        r = pos[1] - '1' + 1;
                        board->updatePiece(piece, r, c);
                    }
                    
                    textDisplay->print();
                } if (op == "-") {
                    string pos;
                    cin >> pos;

                    // sets piece at position
                    int r, c;
                    if (pos.size() == 2) {
                        c = pos[0] - 'a';
                        r = pos[1] - '1' + 1;
                        board->updatePiece(nullptr, r, c);
                    }
                    
                    textDisplay->print();
                } 
 
            }
        }
    }
}

ChessController::~ChessController() {}

