#include <iostream>
#include <string>
#include <sstream>
#include "controller.h"
#include <memory>

int main (int argc, char* argv[]) {
    unique_ptr<ChessController> c{new ChessController()};
    c->createGame();
    return 0;
}


