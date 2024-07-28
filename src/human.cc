#include "human.h"
#include "types.h"
#include "player.h"
#include <iostream>

Human::Human(Color c) : Player(c) {
    // Constructor implementation
}

Move Human::getMove() {
    cout << "called";
    string from, to;
	cin >> from >> to;
    int r, c, nr, nc;
    if (from.size() == 2 && to.size() == 2) {
        c = from[0] - 'a';
        r = from[1] - '1';
        nc = to[0] - 'a';
        nr = to[1] - '1';
    } else {
        r = c = nr = nc = 0;
    }

	Move turn(r, c, nr, nc);
	return turn;
}

Human::~Human() {
    // Destructor implementation (if needed)
}
