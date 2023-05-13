#ifndef acceptNFA_DFA_TRANSITION_H
#define acceptNFA_DFA_TRANSITION_H

#include <vector>
#include "State.h"
#include <string>
class State;
class Transition
{
private:
    std::vector<std::string> alphabets;
    // zero for start position of transition and 1 for end;
    std::vector<State *>states;
public:
    void setStates(std::vector<State *>);
    std::vector<State *> getStates()const;
    void setAlphabets(std::vector<std::string>);
    std::vector<std::string> getAlphabets()const;

};


#endif //acceptNFA_DFA_TRANSITION_H
