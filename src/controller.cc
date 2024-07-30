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
}

// prints scores at game end
void ChessController::printScore() {
    cout << "Current score: " << endl;
    cout << "White: " << ((double)p0Score / 2) << endl;
    cout << "Black: " << ((double)p1Score / 2) << endl;
}

// registers win - checkmate or resign
void ChessController::registerWin(){
  cout << (playerTurn % 2 == 0 ? "White" : "Black") << " wins! --------------" << endl;
  if (playerTurn % 2 == 0) {
    p0Score += 2;
  } else {
    p1Score += 2;
  }
  // reset board
  board->setupBoard();
  playerTurn = 0;
}

void ChessController::registerStalemate(){
  cout << "Stalemate --------------" << endl;
  p0Score += 1;
  p1Score += 1;
  // reset board
  board->setupBoard();
  playerTurn = 0;
}

void ChessController::playComputerWhite(){
  cout << "White Turn" << endl;
  cout << "Computer is making move" << endl;

  Move turn = p0->getMove();
  if(turn.nr == -1 && turn.nc == -1) {
    registerStalemate();
    return;
  }
  board->move(turn);
}

void ChessController::playComputerBlack(){
  cout << "Black Turn" << endl;
  cout << "Computer is making move" << endl;
  
  Move turn = p1->getMove();
  if(turn.nr == -1 && turn.nc == -1) {
    registerStalemate();
    return;
  }
  board->move(turn);
}

// starts chess session
void ChessController::createGame(){
    string cmd;
    bool setupMode = true;
    string firstPlayer, secondPlayer;
    
    while (cin >> cmd) {        
        // creates a new game with two players
        if (cmd == "game") {
            cin >> firstPlayer >> secondPlayer;
            
            if (firstPlayer != "human" && secondPlayer != "human") {
                cerr << "Players can't both be computers" << endl;
                continue;
            }

            // if board starts at stalemate in setup
            if(board->isStalemate(((playerTurn) % 2 == 0) ? Color::White : Color::Black)) { 
              registerStalemate();
              continue;
            }

            // sets white player
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

            // sets black player
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
            if (playerTurn % 2 == 0 && firstPlayer != "human") {
                textDisplay->print();
                playComputerWhite();
                playerTurn = 1;
            } else if(playerTurn % 2 > 0 && secondPlayer != "human") {
                textDisplay->print();
                playComputerBlack();
                playerTurn = 0;
            }

            textDisplay->print();
            setupMode = false;
        } else if (cmd == "move") {
            Move turn;

            // checks if it is stalemate
            if(board->isStalemate(((playerTurn) % 2 == 0) ? Color::White : Color::Black)) { 
              registerStalemate();
              continue;
            }
            
            // checks if move is valid for human players
            bool isValidMove = true;
            if (playerTurn % 2 == 0 && firstPlayer == "human") {
                turn = p0->getMove();
                isValidMove = board->canMove(turn, Color::White);
            } else if (secondPlayer == "human"){
                turn = p1->getMove();
                isValidMove = board->canMove(turn, Color::Black);
            }

            if (isValidMove) {
                board->move(turn);
                textDisplay->print();

                Color opposingColor = ((playerTurn + 1) % 2 == 0) ? Color::White : Color::Black;
                // checks if we check opposing player
                if(board->isCheck(opposingColor)){
                    // checks if it is checkmate
                    if(board->isCheckmate(opposingColor)){
                      registerWin();
                      continue;
                    }
                }

                // plays computer turns
                if(firstPlayer != "human" || secondPlayer != "human"){
                  playerTurn++;
                  if (firstPlayer != "human") {
                      playComputerWhite();
                  }
                  else if (secondPlayer != "human") {
                      playComputerBlack();
                  }
                  textDisplay->print();

                  Color opposingColor = ((playerTurn + 1) % 2 == 0) ? Color::White : Color::Black;
                  // checks if computer checks human
                  if(board->isCheck(opposingColor)){
                      // checks if it is checkmate
                      if(board->isCheckmate(opposingColor)){
                        registerWin();
                        continue;
                      }
                  }
                }

                playerTurn++;
            } else {
                cout << "Invalid move" << endl;
            }

        } else if (cmd == "undo") {
          // undo feature to take back last move
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
          // handling setup input
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
            } else if (op == "-") {
              string pos;
              cin >> pos;

              // sets piece at position
              int r, c;
              if (pos.size() == 2) {
                c = pos[0] - 'a';
                r = pos[1] - '1' + 1;
                board->updatePiece("", r, c);
              }

              textDisplay->print();
            } else if (op == "=") {
              // sets turn to go next
              string col;
              cin >> col;
              if (col == "white") {
                playerTurn = 0;
              } else if (col == "black") {
                playerTurn = 1;
              }
            } else if (op == "done") {
                // checks if exactly one black and one white king + no pawns on promotion squares + no king in check
                int whiteKings = 0;
                int blackKings = 0;
                bool pawnOnPromotionPos = false;
                for (int row = 0; row < 8; ++row) {
                  for (int col = 0; col < 8; ++col) {
                      Piece* piece = board->getSquare(row, col).getPiece();
                      // checks if one black and one white king
                      if (piece && piece->getType() == PieceType::King) {
                          if(piece->getColor() == Color::White){
                            whiteKings++;
                          } else if(piece->getColor() == Color::Black){
                            blackKings++;
                          }
                      }
                      // checks if not pawns on promotion pos
                      if(piece && piece->getType() == PieceType::Pawn){
                        if((row == 0 && piece->getColor() == Color::White) || (row == 7 && piece->getColor() == Color::Black)){
                          pawnOnPromotionPos = true;
                        }
                      }
                  }
                }
                // checks if no king in check
                if(whiteKings == 1 && blackKings == 1 && !pawnOnPromotionPos && !board->isCheck(Color::White) && !board->isCheck(Color::Black)){
                  cout << "Exiting setup" << endl;
                  break;
                } else {
                  cout << "Conditions to exit setup not met" << endl;
                  continue;
                }
            } else {
              cout << "Invalid command" << endl;
            }
          }
        } else if (cmd == "resign") {
          if (setupMode) {
            cout << "Not playing a game" << endl;
            continue;
          }

          playerTurn++;
          registerWin();
          continue;
        }
        else {
          cout << "Invalid command" << endl;
        }

        // Whos turn is next
        cout << (playerTurn % 2 == 0 ? "White Turn" : "Black Turn") << endl;
    }
    printScore();
}

ChessController::~ChessController() {}

