#ifndef NPDAACC_NPDA_H
#define NPDAACC_NPDA_H
#include <vector>
#include <string>
#include "state.h"
#include "transition.h"

class NPDA
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

#endif //NPDAACC_NPDA_H
