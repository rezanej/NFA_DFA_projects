#include "NPDA.h"
std::vector<std::string> NPDA::getAlphabets() const
{
    return alphabet;
}
std::vector<State > NPDA::getStates() const
{
    return states;
}
void NPDA::setTransitions(std::vector<Transition> t) {
    transitions=t;
}
std::vector<Transition> NPDA::getTransitions() const {
    return transitions;
}
void NPDA::setAlphabet(std::vector<std::string> alphabet)
{
    this->alphabet=alphabet;
}
void NPDA::setStates(std::vector<State > states)
{
    this->states=states;
}
void NPDA::setStartState(State  startState) {
    this->startState=startState;
}
State  NPDA::getStartState() const {
    return startState;
}