#ifndef DFAMIN_OPERATIONS_H
#define DFAMIN_OPERATIONS_H
#include "NFA.h"

class Operations {
private:
    void deleteUnreachables(std::vector<State> &s);
    void goToStateAndCheck(State s,std::vector<State> &p);
    void initGroups(std::vector<std::vector<State>> &groups,std::vector<State> &states);
    bool sameGroup(NFA dfa,State s0,State s1);
    void processGroups(std::vector<std::vector<State>> &groups,NFA dfa);
    void combineGroups(std::vector<std::vector<State>> &groups,std::vector<State> &states);
public:
    NFA DFAmin(NFA dfa);

};


#endif //DFAMIN_OPERATIONS_H
