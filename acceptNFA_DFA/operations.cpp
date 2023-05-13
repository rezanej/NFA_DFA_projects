
#include "operations.h"
template <class t>
bool find(std::vector<t> a,t b) {
    for (int i = 0; i < a.size(); ++i) {
        if (a[i]== b) {
            return true;
        }
    }
    return false;
}
void operations:: goToStateAndCheckNFA(State s,std::string &inp,int i,int l,bool &accept) {
    std::string p;
    p.push_back(inp[i]);
    if (i == l && s.getIsFinal()) {
        accept = true;
    } else {
        for (int j = 0; j < s.getTransitions().size(); ++j) {
            if (find<std::string>(s.getTransitions()[j].getAlphabets(), p)) {
                if (i < l)
                    goToStateAndCheckNFA(*s.getTransitions()[j].getStates()[1], inp, i + 1, l, accept);
                else
                    accept = false;
            } else if (find<std::string>(s.getTransitions()[j].getAlphabets(), "$"))
                goToStateAndCheckNFA(*s.getTransitions()[j].getStates()[1], inp, i, l, accept);
        }
    }
}
void operations:: goToStateAndCheckDFA(State s,std::string &inp,int i,int l,bool &accept)
{
    std::string p;
    p.push_back(inp[i]);
    if (i==l &&s.getIsFinal()) {
        accept= true;
    }else {
        for (int j = 0; j < s.getTransitions().size(); ++j) {
            if (find<std::string>(s.getTransitions()[j].getAlphabets(), p)) {
                if (i < l)
                    goToStateAndCheckDFA(*s.getTransitions()[j].getStates()[1], inp, i + 1, l,accept);
                else
                    accept= false;
            }
        }
    }
}

bool  operations::AcceptNFA(std::string input,NFA nfa)
{
    int L=input.size();
    int i=0;
    bool accept= false;
    goToStateAndCheckNFA(nfa.getStartState(),input,0,L,accept);
    return accept;
}
bool operations::AcceptDFA(std::string input, NFA nfa)
{
    int L=input.size();
    int i=0;
    bool accept= false;
    goToStateAndCheckDFA(nfa.getStartState(),input,0,L,accept);
    return accept;
}