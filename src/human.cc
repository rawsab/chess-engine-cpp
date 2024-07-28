#include "human.h"
#include "types.h"
#include "player.h"
#include <iostream>

Human::Human(Color c) : Player(c) {
    // Constructor implementation
}

Move Human::getMove() {
    string start, end;
	cin >> start >> end;
	Move turn(start, end);
	return turn;
}

Human::~Human() {
    // Destructor implementation (if needed)
}
