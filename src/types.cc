#include "types.h"

// Default constructor
Move::Move() : r(0), c(0), nr(0), nc(0) {}
Move::Move(int x, int y, int nx, int ny) : r(x), c(y), nr(nx), nc(ny) {}

// Destructor
Move::~Move() {
    // No dynamic memory to clean up
}

// Copy constructor
Move::Move(const Move& other) 
    : r(other.r), c(other.c), nr(other.nr), nc(other.nc) {}

// Copy assignment operator
Move& Move::operator=(const Move& other) {
    if (this != &other) {
        r = other.r;
        c = other.c;
        nr = other.nr;
        nc = other.nc;
    }
    return *this;
}

// Move constructor
Move::Move(Move&& other) noexcept 
    : r(other.r), c(other.c), nr(other.nr), nc(other.nc) {
    other.r = 0;
    other.c = 0;
    other.nr = 0;
    other.nc = 0;
}

// Move assignment operator
Move& Move::operator=(Move&& other) noexcept {
    if (this != &other) {
        r = other.r;
        c = other.c;
        nr = other.nr;
        nc = other.nc;

        other.r = 0;
        other.c = 0;
        other.nr = 0;
        other.nc = 0;
    }
    return *this;
}
