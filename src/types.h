#ifndef TYPES_H
#define TYPES_H

#include <string>

class Piece;

enum class MoveType { 
  Promotion, 
  EnPassant, 
  CastlePawn2, 
  Regular 
};

enum class Color {
  Black,
  White,
  NoColor,
};

enum class PieceType {
  Bishop,
  Rook,
  Knight,
  King,
  Queen,
  Pawn,
  NoPiece,
};

std::ostream& operator<<(std::ostream& os, const PieceType& pieceType);


struct Move {
    int r;  // row
    int c;  // column
    int nr; // new row
    int nc; // new column

    // Default constructor
    Move();
    Move(int x, int y, int nx, int ny);

    // Destructor
    ~Move();

    // Copy constructor
    Move(const Move& other);

    // Copy assignment operator
    Move& operator=(const Move& other);

    // Move constructor
    Move(Move&& other) noexcept;

    // Move assignment operator
    Move& operator=(Move&& other) noexcept;

    bool operator==(const Move& other) const;
};

struct MoveHistory{
  Move move;
  Piece* captured;
};

#endif
