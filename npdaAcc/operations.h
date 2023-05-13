
#ifndef NPDAACC_OPERATIONS_H
#define NPDAACC_OPERATIONS_H
#include "NPDA.h"
#include "stack.h"
class Operations
{
private:
    void a(State s,Stack stack,std::string &inp,int i,int l,bool &accept);
public:
    bool NPDAaccept(NPDA npda,std::string input);
};


#endif //NPDAACC_OPERATIONS_H
