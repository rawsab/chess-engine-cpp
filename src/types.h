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
    MoveType moveType;
    PieceType oldPieceType;
    PieceType newPieceType;
    int r;  // row
    int c;  // column
    int nr; // new row
    int nc; // new column
};

#endif
