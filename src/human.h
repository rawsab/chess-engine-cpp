#ifndef HUMAN_H
#define HUMAN_H

class Human : public Player {
 public:
    Human(Color c);
    Move getMove() override;

    ~Human();
};

#endif
