#include "operations.h"
using namespace std;
template <class t>
bool find(std::vector<t> a,t b) {
    for (int i = 0; i < a.size(); ++i)
    {
        if (a[i]== b) {
            return true;
        }
    }
    return false;
}
bool Operations::sameGroup(NFA dfa,State s0,State s1)
{
    int n=0;
    for (int i = 0; i <dfa.getAlphabets().size() ; ++i)
    {
        for (int j = 0; j <s0.getTransitions().size() ; ++j)
        {
            for (int k = 0; k <s1.getTransitions().size() ; ++k)
            {
                if (find<string>(s0.getTransitions()[j].getAlphabets(),dfa.getAlphabets()[i])
                        &&find<string>(s1.getTransitions()[k].getAlphabets(),dfa.getAlphabets()[i]))
                    if (s0.getTransitions()[j].getStates()[1]->getGroup()==s1.getTransitions()[k].getStates()[1]->getGroup())
                        n++;
            }
        }
    }
    if (n==dfa.getAlphabets().size())
        return true;
    else
        return false;
}
void Operations::goToStateAndCheck(State s, vector<State> &p)
{
    for (int i = 0; i < s.getTransitions().size(); ++i)
    {
        if (!find<State>(p,*s.getTransitions()[i].getStates()[1]))
        {
            p.push_back(*s.getTransitions()[i].getStates()[1]);
            goToStateAndCheck(*s.getTransitions()[i].getStates()[1],p);
        }
    }
}
void Operations::deleteUnreachables(std::vector<State> &s)
{
    vector<State> p;
    p.push_back(s[0]);
    goToStateAndCheck(s[0],p);
    s=p;

}
void Operations::initGroups(std::vector<std::vector<State>> &groups,std::vector<State> &states)
{
    for (int i = 0; i <states.size() ; ++i)
    {
        if (!states[i].getIsFinal())
        {

            states[i].setGroup(0);
            states[i].getTransitions()[0].getStates()[0]->setGroup(0);
            groups[0].push_back(states[i]);
        }
        else
        {
            states[i].setGroup(1);
            states[i].getTransitions()[0].getStates()[0]->setGroup(1);
            groups[1].push_back(states[i]);
        }

    }
}
void Operations::processGroups(std::vector<std::vector<State>> &groups,NFA dfa)
{
    // har state ra yek bar ba hameye state haye goroh baresi kon aghar ba hichkodam dar yek goroh nabood
    // goroh jadid besaz
    for (int i = 0; i <groups.size() ; ++i)
    {
        if (groups[i].size()>1)
        {
            for (int j = 0; j < groups[i].size(); ++j)
            {
                int n = 0;
                State t = groups[i][j];
                for (int k = 0; k < groups[i].size(); ++k)
                {
                    if (k != j)
                        if (sameGroup(dfa, t, groups[i][k]))
                            n++;
                }
                if (n == 0)
                {
                    groups[i].erase(groups[i].begin() + j);
                    t.setGroup(groups.size());
                    groups.push_back({t});
                    processGroups(groups, dfa);
                }
            }
        }
    }
}
void Operations::combineGroups(std::vector<std::vector<State>> &groups,std::vector<State> &states)
{
    for (int i = 0; i <groups.size(); ++i)
    {
        if (groups[i].size()>1)
        {
            State s;
            string name="";

            for (int j = 0; j < groups[i].size(); ++j)
            {
                for(char a:groups[i][j].getName())
                    name.push_back(a);
            }
            for (int j = 0; j < groups[i].size(); ++j) {

                // taghiire esme state dar transition ha chon pointere pas dar hame ja avaz mikonad
                groups[i][j].getTransitions()[0].getStates()[0]->setName(name);

            }
            s.setName(name);
            // chon har chand ta state dakhel goroh barabar hastans pas transition haye avaly
            // barabar ba transition haye kol goroh hast
            s.setTransitions(groups[i][0].getTransitions());
            s.setIsFinal(groups[i][0].getIsFinal());
            s.setIsStart(groups[i][0].getIsStart());
            states.push_back(s);
        } else if (groups[i].size()==1) {
               states.push_back(groups[i][0]);

        }
    }

}
NFA Operations::DFAmin(NFA dfa)
{
    vector<vector<State>> groups{{},{}};
    vector<State> p=dfa.getStates();
    vector<State> states;
    deleteUnreachables(p);
    initGroups(groups,p);
    processGroups(groups,dfa);
    combineGroups(groups,states);

    dfa.setStates(states);
    return dfa;
}