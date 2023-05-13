#ifndef DFAMIN_STATE_H
#define DFAMIN_STATE_H
#include <string>
#include <vector>
#include "Transition.h"
class Transition;
class State
{
private:
    std::string name;
    std::vector<Transition > transitions;
    bool isFinal=false;
    bool isStart=false;
    int group;
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
    void setGroup(int n);
    int getGroup() const;
};


#endif //DFAMIN_STATE_H
