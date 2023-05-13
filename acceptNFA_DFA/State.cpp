#include "State.h"
std::string State::getName() const
{
    return name;
}

std::vector<Transition > State::getTransitions() const
{
    return this->transitions;
}
void State::setName(std::string name)
{
    this->name=name;
}

void State::setTransitions(std::vector<Transition > transitions)
{
    this->transitions=transitions;
}
bool State::getIsFinal() const {
    return isFinal;
}
bool State::getIsStart() const {
    return isStart;
}
void State::setIsFinal(bool final) {
    isFinal=final;
}
void State::setIsStart(bool start) {
    isStart=start;
}