#ifndef __VIEW_H__
#define __VIEW_H__
#include <iostream>
#include <sstream>
#include <vector>
#include "types.h"
#include "board.h"

using namespace std;

class View {
  protected:
  public:
    View();

    virtual void notify() = 0;  
    virtual ~View();
};

#endif

