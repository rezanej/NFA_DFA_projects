
#ifndef TURING_OPERATIONS_H
#define TURING_OPERATIONS_H
#include "turing.h"
#include "tape.h"
class Operations
{
private:
    void a(State state, Tape &tape,bool &accept);
public:
    bool turingAccept(Turing turing,std::string input);
};


#endif //TURING_OPERATIONS_H
