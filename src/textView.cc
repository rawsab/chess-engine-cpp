#include "textView.h"
#include <iostream>

using namespace std;

TextView::TextView() : View() {
    // Constructor
}

void TextView::print() {
    // Print the board
    cout << " ,-----------------," << endl;
    for (int i = 0; i < 8; ++i) {
        cout << i << "| ";
        for (int j = 0; j < 8; ++j) {
            cout << board[i][j] << ' ';
        }
        cout << "|" << endl;
    }
    cout << " '-----------------' " << endl;
    cout << "   0 1 2 3 4 5 6 7" << endl;
}

TextView::~TextView() {
    // Destructor
}
