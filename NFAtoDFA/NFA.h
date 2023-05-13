#ifndef NFAtoDFA_NFA_H
#define NFAtoDFA_NFA_H
#include "State.h"
class NFA
{
private:
    std::vector<std::vector<State >> states;
    std::vector<Transition> transitions;
    std::vector<std::string> alphabet;
    std::vector<State > startState;
    std::vector<std::vector<State >> finalStates;
public:

    void setStates(std::vector<std::vector<State >>);
    void setTransitions(std::vector<Transition>);
    void setAlphabet(std::vector<std::string>);
    void setStartState(std::vector<State > startState);
    void setFinaStates(std::vector<std::vector<State >> finalStates);

    std::vector<std::vector<State >> getStates() const;
    std::vector<State > getStartState() const;
    std::vector<std::vector<State >> getFinalStates() const;
    std::vector<Transition> getTransitions()const;
    std::vector<std::string> getAlphabets()const;

};


#endif //NFAtoDFA_NFA_H
