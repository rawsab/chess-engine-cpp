#ifndef __TEXTVIEW_H__
#define __TEXTVIEW_H__
#include <iostream>
#include <sstream>
#include "view.h"
#include "types.h"
#include "board.h"

class TextView : public View {
  Board* board;

  public:
    TextView(Board* b);
    void notify() override;
    void print();
    ~TextView();
};

#endif

