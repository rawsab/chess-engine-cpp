#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H
#include "view.h"
#include "window.h"

class GraphicsView : public View {
    Xwindow graphicsWindow;
    Board* board;

   public:
    GraphicsView(Board* b);

    void renderDisplay();
};

#endif
