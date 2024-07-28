#ifndef __DISPLAY_H__
#define __DISPLAY_H__
#include <iostream>
#include <sstream>

class View {
  protected:
    vector<vector<Square>> board;
  public:
    View();

    void notify(Move turn);

    virtual void print(std::ostream &out) {}
    virtual void update() {}
  
    virtual ~View() = 0;
};

#endif

