#ifndef TYPES_H
#define TYPES_H

#include <string>

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

struct Move {
    int r;  // row
    int c;  // column
    int nr; // new row
    int nc; // new column

    Move(const std::string& from, const std::string& to);
    Move(Move&& other) noexcept;
    Move& operator=(Move&& other) noexcept;
    Move(const Move& other);
    Move& operator=(const Move& other);
    ~Move();
};

#endif
