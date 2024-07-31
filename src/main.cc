#include <iostream>
#include <string>
#include <sstream>
#include "controller.h"

// creates chess session
int main (int argc, char* argv[]) {
    ChessController *c = new ChessController;
    c->createGame();
    return 0;
}


