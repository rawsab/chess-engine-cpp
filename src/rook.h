#ifndef ROOK_H
#define ROOK_H

#include <vector>

#include "piece.h"

using namespace std;

class Rook : public Piece {
 private:
  bool canCastle;

 public:
  Rook(Color c, Square *pos);
  bool getCanCastle() const;
  void setCanCastle();
  vector<Move> getMoves() const override;
  ~Rook() = default;
};

#endif
