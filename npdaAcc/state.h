
#ifndef NPDAACC_STATE_H
#define NPDAACC_STATE_H
#include <string>
#include <vector>
#include "transition.h"
class Transition;
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
    bool operator==(State other)
    {
        if(this->name==other.name)
            return true;
        return false;
    }
    std::vector<Transition > getTransitions()const;
    std::string getName()const;
};


#endif //NPDAACC_STATE_H
