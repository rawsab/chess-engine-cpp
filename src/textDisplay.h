#include "display.h"
#include "types.h"

class TextDisplay : public Display {
protected:
    vector<vector<Square>> board;

public:
    void notify(Move turn);

    void print(std::ostream &out);
    void update();

    ~TextDisplay();
};