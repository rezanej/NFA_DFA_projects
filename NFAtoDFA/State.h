#ifndef NFAtoDFA_STATE_H
#define NFAtoDFA_STATE_H

#include <vector>
#include "Transition.h"
#include <string>
class Transition;
class State
{
private:
    std::string name;
    std::vector<Transition > transitions;

public:

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


#endif //NFAtoDFA_STATE_H
