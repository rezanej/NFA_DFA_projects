
#include "turing.h"
std::vector<std::string> Turing::getAlphabets() const
{
    return alphabet;
}
std::vector<State > Turing::getStates() const
{
    return states;
}
void Turing::setTransitions(std::vector<Transition> t) {
    transitions=t;
}
std::vector<Transition> Turing::getTransitions() const {
    return transitions;
}
void Turing::setAlphabet(std::vector<std::string> alphabet)
{
    this->alphabet=alphabet;
}
void Turing::setStates(std::vector<State > states)
{
    this->states=states;
}
void Turing::setStartState(State  startState) {
    this->startState=startState;
}
State  Turing::getStartState() const {
    return startState;
}