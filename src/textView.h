#ifndef __TEXTVIEW_H__
#define __TEXTVIEW_H__
#include <iostream>
#include <sstream>
#include "view.h"
#include "types.h"
#include "board.h"
#include <memory>

class TextView : public View {
  shared_ptr<Board> board;

  public:
    TextView(shared_ptr<Board> b);
    void print();
    ~TextView();
};

#endif

