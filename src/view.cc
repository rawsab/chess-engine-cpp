#include "view.h"
#include <vector>
#include <iostream>
#include <sstream>
#include "types.h"

using namespace std;


View::View() {
    board = vector<vector<char>>(8, vector<char>(8, ' '));
    // Initialize the board with the standard chess layout
    string initialBoard[8] = {
        "rnbqkbnr",
        "pppppppp",
        "        ",
        "        ",
        "        ",
        "        ",
        "PPPPPPPP",
        "RNBQKBNR"
    };

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            board[i][j] = initialBoard[i][j];
        }
    }
}

void View::notify(Move turn) {
    board[turn.nr][turn.nc] = board[turn.r][turn.c];

}

View::~View() {
    // Destructor
}
