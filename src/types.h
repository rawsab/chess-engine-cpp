#ifndef TYPES_H
#define TYPES_H

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
};

struct Move {
  int r, c, nr, nc;
  MoveType getMoveType();
};

#endif
