
#include "tape.h"

void Tape::move(int moveValue)
{
    if (pointer+moveValue>=0 &&pointer+moveValue<=tape.size()-1)
            pointer+= moveValue;
    else if (pointer+moveValue<0)
    {
        tape.push_back(tape[tape.size()-1]);
        for (int i = tape.size()-1; i <0 ; ++i)
        {
            tape[i]=tape[i]-1;
        }
        tape[0]='#';
    } else if (pointer+moveValue>tape.size()-1)
    {

        tape.push_back('#');
    }
}
void Tape::write(char writeValue) {
    tape[pointer]=writeValue;
}
char Tape::read() const
{
    return tape[pointer];
}

Tape::Tape(std::string tape0) {
    tape.push_back('#');
    for (int i = 0; i <tape0.size() ; ++i)
    {
     tape.push_back(tape0[i]);
    }
    tape.push_back('#');

}
