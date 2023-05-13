#ifndef acceptNFA_DFA_NFA_H
#define acceptNFA_DFA_NFA_H
#include "State.h"

class State;
class NFA
{
private:
    std::vector<State > states;
    std::vector<std::string> alphabet;
    State  startState;
    std::vector<Transition>transitions;
public:

    void setStates(std::vector<State >);
    void setTransitions(std::vector<Transition>);
    void setAlphabet(std::vector<std::string>);
    void setStartState(State  startState);


    std::vector<State > getStates() const;
    std::vector<Transition > getTransitions() const;
    State  getStartState() const;
    std::vector<std::string> getAlphabets()const;

};



#endif //acceptNFA_DFA_NFA_H
