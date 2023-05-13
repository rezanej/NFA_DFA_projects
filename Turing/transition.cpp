
#include "transition.h"
std::vector<State *> Transition::getStates() const {
    return states;
}
void Transition::setStates(std::vector<State *> states) {
    this->states=states;

}
Transition::Transition( std::vector<State *> states, char read,
                       char write,int move) :states{states},read{read},write{write},move{move}{}
char Transition::getRead() const {
    return read;
}
char Transition::getWrite() const {
    return write;
}
int Transition::getMove() const {
    return move;
}
void Transition::setMove(int move) {
    this->move=move;
}