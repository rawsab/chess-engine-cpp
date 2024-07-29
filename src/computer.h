#ifndef COMPUTER_H
#define COMPUTER_H

#include "player.h"

class Computer : public Player {
 protected:
    Board *board;

 public:
    Computer(Color c, Board *b);
    virtual void generateMove() = 0;

    ~Computer();
};


// Levels for move generation difficulties

class LevelOne : public Computer {
 public:
    LevelOne(Color c, Board *b);
    void generateMove() override;
};

class LevelTwo : public Computer {
 public:
    LevelTwo(Color c, Board *b);
    void generateMove() override;
};

class LevelThree : public Computer {
 public:
    LevelThree(Color c, Board *b);
    void generateMove() override;
};

class LevelFour : public Computer {
 public:
    LevelFour(Color c, Board *b);
    void generateMove() override;
};

#endif
