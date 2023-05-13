
#ifndef NPDAACC_TRANSITION_H
#define NPDAACC_TRANSITION_H
#include <vector>
#include "state.h"
#include <string>
class State;
class Transition
{
private:
    std::string alphabet;
    // zero for start position of transition and 1 for end;
    std::vector<State *>states;
    std::string pop;
    std::string push;

public:
    Transition(std::string alphabet,std::vector<State *>states,std::string pop,std::string push);
    void setStates(std::vector<State *>);
    std::vector<State *> getStates()const;
    void setAlphabet(std::string);
    std::string getAlphabet()const;
    std::string getPop()const;
    std::string getPush()const;


};

#endif //NPDAACC_TRANSITION_H
