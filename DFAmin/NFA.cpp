#include "NFA.h"
std::vector<std::string> NFA::getAlphabets() const
{
    return alphabet;
}
std::vector<State > NFA::getStates() const
{
    return states;
}
void NFA::setTransitions(std::vector<Transition> t) {
    transitions=t;
}
std::vector<Transition> NFA::getTransitions() const {
    return transitions;
}
void NFA::setAlphabet(std::vector<std::string> alphabet)
{
    this->alphabet=alphabet;
}
void NFA::setStates(std::vector<State > states)
{
    this->states=states;
}
void NFA::setStartState(State  startState) {
    this->startState=startState;
}
State  NFA::getStartState() const {
    return startState;
}
