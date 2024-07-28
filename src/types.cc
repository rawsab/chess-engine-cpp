#include "types.h"
#include <string>
#include <utility>

Move::Move(const std::string& from, const std::string& to) {
    if (from.size() == 2 && to.size() == 2) {
        c = from[0] - 'a';
        r = from[1] - '1';
        nc = to[0] - 'a';
        nr = to[1] - '1';
    }
}

// Move constructor
Move::Move(Move&& other) noexcept 
    : r(std::exchange(other.r, 0)), c(std::exchange(other.c, 0)), 
      nr(std::exchange(other.nr, 0)), nc(std::exchange(other.nc, 0)) {}

// Move assignment operator
Move& Move::operator=(Move&& other) noexcept {
    if (this != &other) {
        r = std::exchange(other.r, 0);
        c = std::exchange(other.c, 0);
        nr = std::exchange(other.nr, 0);
        nc = std::exchange(other.nc, 0);
    }
    return *this;
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

// Destructor
Move::~Move() {
    // No dynamic resources to release
}
