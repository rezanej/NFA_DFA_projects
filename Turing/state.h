
#ifndef TURING_STATE_H
#define TURING_STATE_H
#include "transition.h"
#include <string>
#include <vector>
class  Transition;
class State
{
private:
    std::string name;
    std::vector<Transition > transitions;
    bool isFinal=false;
    bool isStart=false;
public:
    bool getIsFinal()const;
    bool getIsStart()const;
    void setIsFinal(bool );
    void setIsStart(bool);
    void setTransitions(std::vector<Transition >);
    void setName(std::string);
    std::vector<Transition > getTransitions()const;
    std::string getName()const;

};


#endif //TURING_STATE_H
