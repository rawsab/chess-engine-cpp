#ifndef __TEXTVIEW_H__
#define __TEXTVIEW_H__
#include <iostream>
#include <sstream>
#include "view.h"
#include "types.h"

class TextView : public View {
  public:
    TextView();
    void print();
    ~TextView();
};

#endif

