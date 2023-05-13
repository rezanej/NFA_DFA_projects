#ifndef acceptNFA_DFA_OPERATIONS_H
#define acceptNFA_DFA_OPERATIONS_H
#include "NFA.h"

using namespace std;
class operations{
    void goToStateAndCheckNFA(State s,std::string &inp,int i,int l,bool &accept);
    void goToStateAndCheckDFA(State s,std::string &inp,int i,int l,bool &accept);

public:
    bool AcceptNFA(std::string input,NFA nfa);
    bool AcceptDFA(std::string input,NFA nfa);
};
#endif //acceptNFA_DFA_OPERATIONS_H
