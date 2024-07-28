#include "textView.h"
#include <iostream>

using namespace std;

TextView::TextView() : View() {
    // Constructor
}

ostream &operator<<(std::ostream &out, const TextDisplay &td)
{
    // Print the board
    cout << "  a b c d e f g h" << endl;
    for (int i = 0; i < 8; ++i) {
        cout << 8 - i << " ";
        for (int j = 0; j < 8; ++j) {
            cout << td.board[i][j] << ' ';
        }
        cout << 8 - i << endl;
    }
    cout << "  a b c d e f g h" << endl;
    return out;
}

TextView::~TextView() {
    // Destructor
}
