
#include "operations.h"
void Operations::a(State state, Tape &tape, bool &accept)
{
    if (state.getIsFinal())
        accept= true;
    else
    {
        for (int i = 0; i <state.getTransitions().size() ; ++i)
        {
            if (state.getTransitions()[i].getRead()==tape.read())
            {
                tape.write(state.getTransitions()[i].getWrite());
                tape.move(state.getTransitions()[i].getMove());
                a(*state.getTransitions()[i].getStates()[1],tape,accept);
                break;
            }


        }
    }
}

bool Operations::turingAccept(Turing turing, std::string input)
{
    bool accept= false;
    Tape tape=Tape(input);
    a(turing.getStartState(),tape,accept);
    return accept;
}