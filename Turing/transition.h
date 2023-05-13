
#ifndef TURING_TRANSITION_H
#define TURING_TRANSITION_H

#include <vector>
#include "state.h"
#include <string>
class State;
class Transition
{
private:
    // zero for start position of transition and 1 for end;
    std::vector<State *>states;
    char write;
    char read;
    // left=-1 right=1
    int move;

public:
    Transition(std::vector<State *>states,char read,char write,int move);
    void setStates(std::vector<State *>);
    std::vector<State *> getStates()const;

    char getRead()const;
    char getWrite()const;
    int getMove()const;
    void setMove(int move);

};

#endif //TURING_TRANSITION_H
