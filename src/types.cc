#include "types.h"
#include <iostream>
using namespace std;

std::ostream& operator<<(std::ostream& os, const PieceType& pieceType) {
    switch (pieceType) {
        case PieceType::Bishop: os << "Bishop"; break;
        case PieceType::Rook: os << "Rook"; break;
        case PieceType::Knight: os << "Knight"; break;
        case PieceType::King: os << "King"; break;
        case PieceType::Queen: os << "Queen"; break;
        case PieceType::Pawn: os << "Pawn"; break;
        case PieceType::NoPiece: os << "NoPiece"; break;
        default: os << "Unknown"; break;
    }
    return os;
}

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

bool Move::operator==(const Move& other) const {
  return r == other.r && c == other.c && nr == other.nr && nc == other.nc;
}