#include <iostream>
#include <string>
#include <sstream>
#include "controller.h"

int main (int argc, char* argv[]) {
    ChessController *c = new ChessController;
    c->createGame();
    return 0;
}


