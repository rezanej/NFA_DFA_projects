#include "Transition.h"
std::vector<std::vector<State *>> Transition::getStates() const {
    return states;
}
void Transition::setStates(std::vector<std::vector<State *>> states) {
    this->states=states;

}
std::vector<std::string> Transition::getAlphabets() const
{
    return alphabets;
}
void Transition::setAlphabets(std::vector<std::string> alphabets)
{
    this->alphabets=alphabets;
}