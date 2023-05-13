#include "transition.h"
std::vector<State *> Transition::getStates() const {
    return states;
}
void Transition::setStates(std::vector<State *> states) {
    this->states=states;

}
std::string Transition::getAlphabet() const
{
    return alphabet;
}
void Transition::setAlphabet(std::string alphabet)
{
    this->alphabet=alphabet;
}
Transition::Transition(std::string alphabet, std::vector<State *> states, std::string pop,
                       std::string push) :alphabet{alphabet},states{states},pop{pop},push{push}{}
std::string Transition::getPop() const {
    return pop;
}
std::string Transition::getPush() const {
    return push;
}
