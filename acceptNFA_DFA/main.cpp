#include <iostream>
using namespace std;
#include "operations.h"
void show(NFA DNFA,string name)
{

    cout<<name<<" with states : ";
    for (int i = 0; i <DNFA.getStates().size() ; ++i) {
        cout<<DNFA.getStates()[i].getName()<<" ";
    }
    cout<<"\nAlphabets : ";
    for (int i = 0; i <DNFA.getAlphabets().size() ; ++i) {
        cout<<DNFA.getAlphabets()[i]<<" ";
    }
    cout<<"\nstart state :"<<DNFA.getStartState().getName();
    cout<<"\nFinal state(s) : ";
    for (int i = 0; i <DNFA.getStates().size() ; ++i) {
        if (DNFA.getStates()[i].getIsFinal())
            cout<<DNFA.getStates()[i].getName()<<" ";
    }
    cout<<"\ntransitions : \n";
    for (int i = 0; i <DNFA.getTransitions().size() ; ++i) {
        cout<<DNFA.getTransitions()[i].getStates()[0]->getName()<<"--"<<DNFA.getTransitions()[i].getAlphabets()[0]
            <<"-->"<<DNFA.getTransitions()[i].getStates()[1]->getName()<<endl;
    }

}
void sample()
{
    NFA nfa;
    State s1;
    s1.setName("q1");

    State s2;
    s2.setName("q2");
    State s3;
    s3.setName("q3");
    s3.setIsFinal(true);
    s1.setIsFinal(false);
    s2.setIsFinal(false);
    std::vector<std::string> alphabetA{"a"};
    std::vector<std::string> alphabets{"a", "b"};
    std::vector<std::string> alphabetB{"b"};
    std::vector<std::string> alphabet1{"$"};

    Transition t1;
    Transition t2;
    Transition t3;
    Transition t4;

    std::vector<State *> states1 = {&s1,&s2};
    std::vector<State *> states2 = {&s2,&s2};
    std::vector<State *> states3 = {&s2,&s3};
    std::vector<State *> states4 = {&s3,&s1};

    t1.setStates(states1);
    t2.setStates(states2);
    t3.setStates(states3);
    t4.setStates(states4);

    t1.setAlphabets(alphabetB);
    t2.setAlphabets(alphabetA);
    t3.setAlphabets(alphabetB);
    t4.setAlphabets(alphabet1);

    vector<Transition> transitions;
    std::vector<Transition > transitions1 = {t1};
    std::vector<Transition > transitions2 = {t2, t3};
    std::vector<Transition > transitions3 = {t4};
    s1.setTransitions(transitions1);
    s2.setTransitions(transitions2);
    s3.setTransitions(transitions3);

    transitions.push_back(t1);
    transitions.push_back(t2);
    transitions.push_back(t3);
    transitions.push_back(t4);

    std::vector<State > states;
    states.push_back(s1);
    states.push_back(s2);
    states.push_back(s3);

    nfa.setStates(states);
    nfa.setTransitions(transitions);
    nfa.setStartState(s1);
    nfa.setAlphabet(alphabets);
    operations o;
    show(nfa,"NFA");
    if(o.AcceptNFA("baaaaaaaabbaaaaaaaaaaaaaaaaaab",nfa))
    {
        cout<<"\nNFA accepts the string: "<<"baaaaaaaabbaaaaaaaaaaaaaaaaaab";
    } else
        cout<<"\nNFA does not accept string.";

}
void sample1()
{
    NFA nfa;
    State s1;
    s1.setName("q1");

    State s2;
    s2.setName("q2");
    State s3;
    s3.setName("q3");
    s3.setIsFinal(true);
    s1.setIsFinal(false);
    s2.setIsFinal(false);
    std::vector<std::string> alphabetA{"a"};
    std::vector<std::string> alphabets{"a", "b"};
    std::vector<std::string> alphabetB{"b"};
    std::vector<std::string> alphabet1{"$"};

    Transition t1;
    Transition t2;
    Transition t3;
    Transition t4;

    std::vector<State *> states1 = {&s1,&s2};
    std::vector<State *> states2 = {&s2,&s2};
    std::vector<State *> states3 = {&s2,&s3};
    std::vector<State *> states4 = {&s3,&s1};

    t1.setStates(states1);
    t2.setStates(states2);
    t3.setStates(states3);
    t4.setStates(states4);

    t1.setAlphabets(alphabetB);
    t2.setAlphabets(alphabetA);
    t3.setAlphabets(alphabetB);
    t4.setAlphabets(alphabetA);


    std::vector<Transition > transitions1 = {t1};
    std::vector<Transition > transitions2 = {t2, t3};
    std::vector<Transition > transitions3 = {t4};
    s1.setTransitions(transitions1);
    s2.setTransitions(transitions2);
    s3.setTransitions(transitions3);

    std::vector<State > states;
    states.push_back(s1);
    states.push_back(s2);
    states.push_back(s3);

    vector<Transition> transitions;
    s1.setTransitions(transitions1);
    s2.setTransitions(transitions2);
    s3.setTransitions(transitions3);

    transitions.push_back(t1);
    transitions.push_back(t2);
    transitions.push_back(t3);
    transitions.push_back(t4);

    nfa.setStates(states);
    nfa.setStartState(s1);
    nfa.setTransitions(transitions);
    nfa.setAlphabet(alphabets);
    operations o;
    show(nfa,"DFA");
    if(o.AcceptDFA("baaaaaaaab",nfa))
    {
        cout<<"\nDFA accepts the string: "<<"baaaaaaaab";
    } else
        cout<<"\nDFA does not accept string: "<<"baaaaaaaab";

}

void NFAGetAlphabet(vector<string> &alphabet ,string name)
{
    string t;
    cout << "enter "<<name<<"'s alphabets separate with (,) :";
    cin >> t;
    for (int k = 0; k < t.size(); ++k) {
        if (t[k] != ',') {
            string temp;
            temp.push_back(t[k]);
            alphabet.push_back(temp);
        }
    }
}
void NFAGetStates(vector<State> &states,string name0)
{
    int n;
    cout << "enter how many states "<<name0<<" has : ";
    cin >> n;
    string name;
    for (int i = 0; i < n; ++i) {
        cout << "enter state " << i << "'s name :";
        cin >> name;
        State s;
        s.setName(name);
        states.push_back(s);
    }
}
void NFAGetTransitions(vector<State> &states)
{
    string name;
    for (int i = 0; i < states.size(); ++i) {
        vector<Transition> transitions;
        cout << "enter how many Transition " << states[i].getName() << " has :";
        int num;
        cin >> num;

        for (int j = 0; j < num; ++j) {
            std::vector<std::string> alphabet;
            std::vector<State *> states0;
            states0.push_back(&states[i]);
            string t;
            cout << "enter transtion " << j << "'s alphabets separate with (,) :";
            cin >> t;
            for (int k = 0; k < t.size(); ++k) {
                if (t[k] != ',') {
                    string temp;
                    temp.push_back(t[k]);
                    alphabet.push_back(temp);
                }
            }
            cout << "enter destination State's name : ";
            cin >> name;
            for (int j = 0; j < states.size(); ++j) {
                if (states[j].getName() == name) {
                    states0.push_back(&states[j]);
                    break;
                }
            }
            Transition transition;
            transition.setAlphabets(alphabet);
            transition.setStates(states0);
            transitions.push_back(transition);

        }
        states[i].setTransitions(transitions);

    }

}void DFAGetTransitions(vector<State> &states,vector<string> alphabets)
{
    string name;
    for (int i = 0; i < states.size(); ++i) {
        vector<Transition> transitions;
        for (int j = 0; j <alphabets.size() ; ++j) {
            std::vector<State *> states0;
            states0.push_back(&states[i]);
            cout<<"enter state "<<states[i].getName()<<" 's destination State's name with alphabet "<<alphabets[j]<<" :";
            cin >> name;
            for (int j = 0; j < states.size(); ++j) {
                if (states[j].getName() == name) {
                    states0.push_back(&states[j]);
                    break;
                }
            }
            Transition transition;
            transition.setAlphabets({alphabets[j]});
            transition.setStates(states0);
            transitions.push_back(transition);

        }
        states[i].setTransitions(transitions);

    }

}
void NFAGetStartState(NFA &nfa, vector<State> states)
{
    string name;
    cout << "enter start state's name: ";
    cin >> name;
    for (State s:states)
        if (s.getName() == name)
            nfa.setStartState(s);
}
void NFAGetFinalStates(vector<State> &states,string name0) {
    string name;
    int y;
    cout << "how many final state "<<name0<<" has: ";
    cin >> y;
    for (int i = 0; i < y; ++i) {
        cout << "enter final state " << i << " s name: ";
        cin >> name;
        for (int i = 0; i < states.size(); i++)
            if (states[i].getName() == name)
                states[i].setIsFinal(true);
    }
}
void getNFAstringInput(NFA nfa)
{
    bool p= true;
    while (p)
    {
        string inp;
        cout<<"enter the string that you want to test (for exit enter exit): ";
        cin>>inp;
        if (inp=="exit")
            break;
        operations o;
        if(o.AcceptNFA(inp,nfa))
        {
            show(nfa,"NFA");
            cout<<"\nNFA accepts the string: "<<inp;
        } else {
            show(nfa,"NFA");
            cout << "\nNFA does not accept string: " << inp;
        }
    }
}
void getDFAstringInput(NFA dfa)
{
    bool p= true;
    while (p)
    {
        string inp;
        cout<<"enter the string that you want to test (for exit enter exit): ";
        cin>>inp;
        if (inp=="exit")
            break;
        operations o;
        if(o.AcceptDFA(inp,dfa))
        {
            show(dfa,"DFA");
            cout<<"\nDFA accepts the string: "<<inp;
        } else {
            show(dfa,"DFA");
            cout << "\nDFA does not accept string: " << inp;
        }


    }
}
void getNFA()
{
    NFA nfa;
    std::vector<State > states;
    std::vector<std::string> alphabet0;
    NFAGetStates(states,"NFA");
    NFAGetAlphabet(alphabet0,"NFA");
    nfa.setAlphabet(alphabet0);
    NFAGetTransitions(states);
    NFAGetStartState(nfa,states);
    NFAGetFinalStates(states,"NFA");
    nfa.setStates(states);
    getNFAstringInput(nfa);
}
void getDFA()
{
    NFA dfa;
    std::vector<State > states;
    std::vector<std::string> alphabet0;
    NFAGetStates(states,"DFA");
    NFAGetAlphabet(alphabet0,"DFA");
    dfa.setAlphabet(alphabet0);
    DFAGetTransitions(states,dfa.getAlphabets());
    NFAGetStartState(dfa,states);
    NFAGetFinalStates(states,"DFA");
    dfa.setStates(states);
    getDFAstringInput(dfa);
}
int main() {
    int input;
    cout<<"for NFA sample enter 1 ,for DFA sample enter 2 \nand for custom NFA enter 3 for custom DFA enter 4 :(in the latter inputs for lambda enter $) ";
    cin>>input;
    if (input==1)
        sample();
    else if(input==2)
        sample1();
    else if (input ==3)
        getNFA();
    else if (input ==4)
        getDFA();

    return 0;
}
