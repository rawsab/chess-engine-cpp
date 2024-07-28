#include "view.h"
#include <vector>
#include <iostream>
#include <sstream>
#include "types.h"

using namespace std;


View::View() {
    board = vector<vector<char>>(8, vector<char>(8, ' '));
    // Initialize the board with the standard chess layout

    vector<vector<char>> initBoard = {
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
    };

    board = initBoard;
}

void View::notify(Move turn) {
    board[turn.nr][turn.nc] = board[turn.r][turn.c];

}

View::~View() {
    // Destructor
}
