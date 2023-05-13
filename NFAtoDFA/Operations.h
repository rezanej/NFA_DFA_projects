#ifndef NFAtoDFA_OPERATIONS_H
#define NFAtoDFA_OPERATIONS_H

#include "NFA.h"
class Operations
{
public:
     void convertToDFA(NFA &nfa);

private:
    template <class t>
    bool find(std::vector<t> a,t b);
    template <class t>
    bool find2(std::vector<std::vector<t>> a,std::vector<t> b);
    template <class t>
    bool find3(std::vector<std::vector<t>> a,std::vector<t> b,int &n);
    void buildTransition(std::vector<Transition> &transitions,std::vector<State > &state0,std::vector<State > &state1,std::string alpha);
    void addLambdaState(std::vector<std::vector<State >> &temp,std::vector<State > s);
    std::vector<State > findStartState(std::vector<State>  NFAStartState );
    void readLambda(std::vector<std::vector<State >> &temp,std::string alpha,std::vector<State > s);
    void newStates(std::vector<std::string> alpha,std::vector<std::vector<State >> &states ,std::vector<Transition> &transitions,int num);
    void findFinalStates(std::vector<std::vector<State >> &states,std::vector<std::vector<State >> NFAfinalStates,std::vector<std::vector<State >> &finalStates0);
};

#endif //NFAtoDFA_OPERATIONS_H
