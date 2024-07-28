#ifndef DISPLAY_H
#define DISPLAY_H
#include <iostream>
#include <sstream>
#include <vector>

#include "types.h"
#include "square.h"

class Display {
  protected:
    vector<vector<Square>> board;

  public:
    Display(bool isCustomGame);

    void notify(Move turn);

    virtual void print(std::ostream &out) {}
    virtual void update() {}
  
    virtual ~Display() = 0;
};

#endif

