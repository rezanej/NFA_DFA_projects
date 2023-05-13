#include "NFA.h"
std::vector<std::string> NFA::getAlphabets() const
{
    return alphabet;
}
std::vector<std::vector<State >> NFA::getStates() const
{
    return states;
}
std::vector<Transition> NFA::getTransitions() const
{
    return transitions;
}
void NFA::setAlphabet(std::vector<std::string> alphabet)
{
    this->alphabet=alphabet;
}
void NFA::setStates(std::vector<std::vector<State >> states)
{
    this->states=states;
}
void NFA::setTransitions(std::vector<Transition> transitions)
{
    this->transitions=transitions;
}

void NFA::setStartState(std::vector<State > startState) {
    this->startState=startState;
}
std::vector<State > NFA::getStartState() const {
    return startState;
}
void NFA::setFinaStates(std::vector<std::vector<State >> finalStates)
{
    this->finalStates=finalStates;
}

std::vector<std::vector<State >> NFA::getFinalStates() const{
    return finalStates;
}