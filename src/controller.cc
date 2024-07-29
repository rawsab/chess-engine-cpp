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
            if (playerTurn % 2 == 0) {
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

                cout << "checking for check for " << ((playerTurn + 1) % 2 == 0 ? "White" : "Black") << endl;
                if(board->isCheck(((playerTurn + 1) % 2 == 0) ? Color::White : Color::Black)){
                    cout << ((playerTurn + 1) % 2 == 0 ? "White" : "Black") << " in check" << endl;
                }
                playerTurn++;
            } else {
                cout << "Invalid move" << endl;
            }

        } else if (cmd == "undo") {
          if (board->getPastMoves().empty()) {
            cout << "No moves to undo" << endl;
          }
          else {
            MoveHistory lastMove = board->popLastMove();
            board->undoMove(lastMove);
            textDisplay->print();
            playerTurn--;
          }

        } else if (cmd == "setup") {
          if (!setupMode) {
            cout << "Can not enter setup mode" << endl;
            continue;
          }
          board->clearBoard();

          string op;
          while (cin >> op) {
            if (op == "+") {  // TODO: make sure capitalization is correct
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
            } else if (op ==
                       "-") {  // TODO: make sure capitalization is correct
              string pos;
              cin >> pos;

              // sets piece at position
              int r, c;
              if (pos.size() == 2) {
                c = pos[0] - 'a';
                r = pos[1] - '1' + 1;
                // renive piece
                board->updatePiece("", r, c);
              }

              textDisplay->print();
            } else if (op == "=") {
              string col;
              cin >> col;
              if (col == "white") {
                playerTurn = 0;
              } else if (col == "black") {
                playerTurn = 1;
              }
            } else if (op == "done") {
              cout << "Exiting setup" << endl;
              break;
            }
          }
        } else if (cmd == "resign") {
          if (setupMode) {
            cout << "Not playing a game" << endl;
            continue;
          }

          if (playerTurn % 2 == 0) {
            p1Score += 1;
          } else {
            p0Score += 1;
          }

          cout << "Current score: " << std::endl;
          cout << "White: " << p0Score << std::endl;
          cout << "Black: " << p1Score << std::endl;

          playerTurn = 0;  // reset to white turn
        }

        // remove this
        cout << (playerTurn % 2 == 0 ? "White Turn" : "Black Turn") << endl;
    }
}

ChessController::~ChessController() {}

