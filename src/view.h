#ifndef __VIEW_H__
#define __VIEW_H__
#include <iostream>
#include <sstream>
#include "types.h"
#include "board.h"

using namespace std;

class View {
  protected:
    vector<vector<char>> board;
  public:
    View();

    void notify(Move turn);  
    virtual ~View();
};

#endif

