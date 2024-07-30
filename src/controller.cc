#include "controller.h"
#include "player.h"
#include "human.h"
#include "levelone.h"
#include "leveltwo.h"
#include "levelthree.h"
#include "levelfour.h"
#include "board.h"
#include "view.h"
#include "types.h"
#include "computer.h"
#include <string>
#include <cmath>

using namespace std;

ChessController::ChessController() : p0(nullptr), p1(nullptr), textDisplay(nullptr), p0Score(0), p1Score(0), playerTurn(0) {
    board = new Board();
    textDisplay = new TextView(board);
    // board->setupBoard();
}

void ChessController::addToScore(Color c, int score) {
    if (c == Color::White) {
      p0Score += score;
    } else {
      p1Score += score;
    }

    cout << "Current score: " << std::endl;
    cout << "White: " << ((double)p0Score / 2) << std::endl;
    cout << "Black: " << ((double)p1Score / 2) << std::endl;

    playerTurn = 0;  // reset to white turn
}

void ChessController::createGame(){
    string cmd;
    bool setupMode = true;
    string firstPlayer, secondPlayer;
    
    while (cin >> cmd) {        
        if (cmd == "game") {
            cin >> firstPlayer >> secondPlayer;
            
            if (firstPlayer != "human" && secondPlayer != "human") {
                cerr << "Players can't both be computers" << endl;
                continue;
            }

            if (firstPlayer == "human") {
                p0 = new Human(Color::White);
            } else if (firstPlayer == "computer1") {
                p0 = new LevelOne(Color::White, board);
            } else if (firstPlayer == "computer2") {
                p0 = new LevelTwo(Color::White, board);
            } else if (firstPlayer == "computer3") {
                p0 = new LevelThree(Color::White, board);
            } else if (firstPlayer == "computer4") {
                p0 = new LevelFour(Color::White, board);
            }

            if (secondPlayer == "human") {
                p1 = new Human(Color::Black);
            } else if (secondPlayer == "computer1") {
                p1 = new LevelOne(Color::Black, board);
            } else if (secondPlayer == "computer2") {
                p1 = new LevelTwo(Color::Black, board);
            } else if (secondPlayer == "computer3") {
                p1 = new LevelThree(Color::Black, board);
            } else if (secondPlayer == "computer4") {
                p1 = new LevelFour(Color::Black, board);
            }

            p0->setColor(Color::White);
            p1->setColor(Color::Black);

            // if computer starts the game
            if (firstPlayer != "human") {
                textDisplay->print();
                cout << "White Turn" << endl;
                cout << "Computer is making move" << endl;
                Move turn = p0->getMove();
                board->move(turn);

                playerTurn = 1;
            }

            textDisplay->print(); // prints board
            setupMode = false;
        } else if (cmd == "move") {
            // read input
            Move turn;

            cout << "checking stalemate --------------" << (((playerTurn) % 2 == 0) ? "White" : "Black") << endl;
            if(board->isStalemate(((playerTurn) % 2 == 0) ? Color::White : Color::Black)) { 
              cout << "stalemate --------------" << endl;
              addToScore(Color::White, 1);
              addToScore(Color::Black, 1);
            }
            
            // checks if move is valid for player
            bool isValidMove = true;
            if (playerTurn % 2 == 0) {
                if (firstPlayer == "human") {
                  turn = p0->getMove();
                  isValidMove = board->canMove(turn, Color::White);
                }
            } else {
                if (secondPlayer == "human") {
                  turn = p1->getMove();
                  isValidMove = board->canMove(turn, Color::Black);
                }
            }
            // change to isValidMove
            if (isValidMove) {
                board->move(turn);
                textDisplay->print(); // prints board

                // cout << "checking for check for " << ((playerTurn + 1) % 2 == 0 ? "White" : "Black") << endl;
                Color opposingColor = ((playerTurn + 1) % 2 == 0) ? Color::White : Color::Black;
                if(board->isCheck(opposingColor)){
                    cout << ((playerTurn + 1) % 2 == 0 ? "White" : "Black") << " in check" << endl;
                    if(board->isCheckmate(opposingColor)){
                      cout << ((playerTurn + 1) % 2 == 0 ? "White" : "Black") << "checkmate" << endl;
                      if (playerTurn % 2 == 0) {
                        addToScore(Color::Black, 2);
                      } else {
                        addToScore(Color::White, 2);
                      }
                    }
                }

                if (firstPlayer != "human") {
                    playerTurn++;
                    cout << "White Turn" << endl;
                    cout << "Computer is making move" << endl;
                    turn = p0->getMove();
                    board->move(turn);

                    textDisplay->print();
                    // isValidMove = board->canMove(turn, Color::Black);
                }
                else if (secondPlayer != "human") {
                    playerTurn++;
                    cout << "Black Turn" << endl;
                    cout << "Computer is making move" << endl;
                    turn = p1->getMove();
                    board->move(turn);

                    textDisplay->print();
                    // isValidMove = board->canMove(turn, Color::Black);
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
            board->undoMove();
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
            } else if (op == "-") {  // TODO: make sure capitalization is correct
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
            addToScore(Color::Black, 2);
          } else {
            addToScore(Color::White, 2);
          }

          playerTurn = 0;  // reset to white turn
        }
        else {
            cout << "Invalid command" << endl;
        }

        // remove this
        cout << (playerTurn % 2 == 0 ? "White Turn" : "Black Turn") << endl;
    }
}

ChessController::~ChessController() {}

