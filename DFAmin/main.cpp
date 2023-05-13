#include <iostream>
#include "NFA.h"
#include "operations.h"
using namespace std;
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
    cout<<"\nstart state : ";
    for (int i = 0; i <DNFA.getStates().size() ; ++i) {
        if (DNFA.getStates()[i].getIsStart())
            cout<<DNFA.getStates()[i].getName()<<" ";
    }
    cout<<"\nFinal state(s) : ";
    for (int i = 0; i <DNFA.getStates().size() ; ++i) {
        if (DNFA.getStates()[i].getIsFinal())
            cout<<DNFA.getStates()[i].getName()<<" ";
    }
    cout<<"\ntransitions : \n";
    for (int i = 0; i <DNFA.getStates().size() ; ++i) {
        for (int j = 0; j < DNFA.getStates()[i].getTransitions().size(); ++j)
        {
            cout << DNFA.getStates()[i].getTransitions()[j].getStates()[0]->getName() << "--" << DNFA.getStates()[i].getTransitions()[j].getAlphabets()[0]
                 << "-->" <<DNFA.getStates()[i].getTransitions()[j].getStates()[1]->getName() << endl;
        }
    }

}
void sample1()
{
    NFA dfa;
    State s0,s1,s2,s3,s4,s5,s6,s7;
    s0.setName("q0");
    s0.setIsStart(true);
    s0.setIsFinal(true);
    s1.setName("q1");
    s2.setName("q2");
    s3.setName("q3");
    s3.setIsFinal(true);
    s4.setName("q4");
    s4.setIsFinal(true);
    s5.setName("q5");
    s6.setName("q6");
    s7.setName("q7");
    s7.setIsFinal(true);
    Transition t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15;
    t0.setAlphabets({"a"});t0.setStates({&s0,&s1});
    t1.setAlphabets({"b"});t1.setStates({&s0,&s5});
    t2.setAlphabets({"a"});t2.setStates({&s1,&s6});
    t3.setAlphabets({"b"});t3.setStates({&s1,&s4});
    t4.setAlphabets({"a"});t4.setStates({&s2,&s1});
    t5.setAlphabets({"b"});t5.setStates({&s2,&s3});
    t6.setAlphabets({"a"});t6.setStates({&s3,&s7});
    t7.setAlphabets({"b"});t7.setStates({&s3,&s6});
    t8.setAlphabets({"a"});t8.setStates({&s4,&s0});
    t9.setAlphabets({"b"});t9.setStates({&s4,&s5});
    t10.setAlphabets({"a"});t10.setStates({&s5,&s6});
    t11.setAlphabets({"b"});t11.setStates({&s5,&s4});
    t12.setAlphabets({"a"});t12.setStates({&s6,&s5});
    t13.setAlphabets({"b"});t13.setStates({&s6,&s5});
    t14.setAlphabets({"a"});t14.setStates({&s7,&s6});
    t15.setAlphabets({"b"});t15.setStates({&s7,&s3});
    vector<Transition>T0{t0,t1};
    vector<Transition>T1{t2,t3};
    vector<Transition>T2{t4,t5};
    vector<Transition>T3{t6,t7};
    vector<Transition>T4{t8,t9};
    vector<Transition>T5{t10,t11};
    vector<Transition>T6{t12,t13};
    vector<Transition>T7{t14,t15};
    s0.setTransitions(T0);
    s1.setTransitions(T1);
    s2.setTransitions(T2);
    s3.setTransitions(T3);
    s4.setTransitions(T4);
    s5.setTransitions(T5);
    s6.setTransitions(T6);
    s7.setTransitions(T7);
    dfa.setStates({s0,s1,s2,s3,s4,s5,s6,s7});
    dfa.setAlphabet({"a","b"});
    dfa.setTransitions({t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15});
    dfa.setStartState(s0);

    cout<<"DFA before minimization: \n";
    show(dfa,"DFA");
    Operations o;
    NFA a=o.DFAmin(dfa);
    cout<<"\n////////////////////////////////////////////////\n";
    cout<<"DFA after minimization :\n";
    show(a,"DFA");

}
void sample2()
{
    NFA dfa;
    State s0,s1,s2,s3,s4,s5;
    s0.setName("q0");
    s0.setIsStart(true);
    s1.setName("q1");
    s2.setName("q2");
    s3.setName("q3");
    s4.setName("q4");
    s5.setIsFinal(true);
    s5.setName("q5");

    Transition t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23;
    t0.setAlphabets({"a"});t0.setStates({&s0,&s1});
    t1.setAlphabets({"b"});t1.setStates({&s0,&s2});
    t2.setAlphabets({"c"});t2.setStates({&s0,&s3});
    t3.setAlphabets({"d"});t3.setStates({&s0,&s4});
    t4.setAlphabets({"a"});t4.setStates({&s1,&s5});
    t5.setAlphabets({"b"});t5.setStates({&s1,&s5});
    t6.setAlphabets({"c"});t6.setStates({&s1,&s5});
    t7.setAlphabets({"d"});t7.setStates({&s1,&s5});
    t8.setAlphabets({"a"});t8.setStates({&s2,&s5});
    t9.setAlphabets({"b"});t9.setStates({&s2,&s5});
    t10.setAlphabets({"c"});t10.setStates({&s2,&s5});
    t11.setAlphabets({"d"});t11.setStates({&s2,&s5});
    t12.setAlphabets({"a"});t12.setStates({&s3,&s5});
    t13.setAlphabets({"b"});t13.setStates({&s3,&s5});
    t14.setAlphabets({"c"});t14.setStates({&s3,&s5});
    t15.setAlphabets({"d"});t15.setStates({&s3,&s5});
    t16.setAlphabets({"a"});t16.setStates({&s4,&s5});
    t17.setAlphabets({"b"});t17.setStates({&s4,&s5});
    t18.setAlphabets({"c"});t18.setStates({&s4,&s5});
    t19.setAlphabets({"d"});t19.setStates({&s4,&s5});
    t20.setAlphabets({"a"});t20.setStates({&s5,&s5});
    t21.setAlphabets({"b"});t21.setStates({&s5,&s5});
    t22.setAlphabets({"c"});t22.setStates({&s5,&s5});
    t23.setAlphabets({"d"});t23.setStates({&s5,&s5});

    vector<Transition>T0{t0,t1,t2,t3};
    vector<Transition>T1{t4,t5,t6,t7};
    vector<Transition>T2{t8,t9,t10,t11};
    vector<Transition>T3{t12,t13,t14,t15};
    vector<Transition>T4{t16,t17,t18,t19};
    vector<Transition>T5{t20,t21,t22,t23};

    s0.setTransitions(T0);
    s1.setTransitions(T1);
    s2.setTransitions(T2);
    s3.setTransitions(T3);
    s4.setTransitions(T4);
    s5.setTransitions(T5);

    dfa.setStates({s0,s1,s2,s3,s4,s5});
    dfa.setAlphabet({"a","b","c","d"});
    dfa.setTransitions({t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23});
    dfa.setStartState(s0);

    cout<<"DFA before minimization: \n";
    show(dfa,"DFA");
    Operations o;
    NFA a=o.DFAmin(dfa);
    cout<<"\n////////////////////////////////////////////////\n";
    cout<<"DFA after minimization :\n";
    show(a,"DFA");

}
void sample3()
{
    NFA dfa;
    State s0,s1,s2,s3;
    s0.setName("q0");
    s0.setIsStart(true);
    s1.setName("q1");
    s2.setName("q2");
    s3.setName("q3");
    s3.setIsFinal(true);

    Transition t0,t1,t2,t3,t4,t5,t6,t7;
    t0.setAlphabets({"a"});t0.setStates({&s0,&s1});
    t1.setAlphabets({"b"});t1.setStates({&s0,&s2});
    t2.setAlphabets({"a"});t2.setStates({&s1,&s3});
    t3.setAlphabets({"b"});t3.setStates({&s1,&s3});
    t4.setAlphabets({"a"});t4.setStates({&s2,&s3});
    t5.setAlphabets({"b"});t5.setStates({&s2,&s3});
    t6.setAlphabets({"a"});t6.setStates({&s3,&s3});
    t7.setAlphabets({"b"});t7.setStates({&s3,&s3});

    vector<Transition>T0{t0,t1};
    vector<Transition>T1{t2,t3};
    vector<Transition>T2{t4,t5};
    vector<Transition>T3{t6,t7};

    s0.setTransitions(T0);
    s1.setTransitions(T1);
    s2.setTransitions(T2);
    s3.setTransitions(T3);

    dfa.setStates({s0,s1,s2,s3});
    dfa.setAlphabet({"a","b"});
    dfa.setTransitions({t0,t1,t2,t3,t4,t5,t6,t7});
    dfa.setStartState(s0);

    cout<<"DFA before minimization: \n";
    show(dfa,"DFA");
    Operations o;
    NFA a=o.DFAmin(dfa);
    cout<<"\n////////////////////////////////////////////////\n";
    cout<<"DFA after minimization :\n";
    show(a,"DFA");

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
void DFAGetTransitions(vector<State> &states,vector<string> alphabets)
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
void NFAGetStartState(NFA nfa, vector<State> &states)
{
    string name;
    cout << "enter start state's name: ";
    cin >> name;
    for (int i = 0; i <states.size() ; ++i) {
        if (states[i].getName()==name)
            states[i].setIsStart(true);
    }
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
    cout<<"DFA before minimization: \n";
    show(dfa,"DFA");
    Operations o;
    dfa=o.DFAmin(dfa);
    cout<<"\n////////////////////////////////////////////////\n";
    cout<<"DFA after minimization :\n";
    show(dfa,"DFA");
}
int main()
{
    int input;
    cout<<"this program will minimize the DFA for sample enter 1,2,3 ,for custom input enter 4 :";
    cin>>input;
    if (input==1)
        sample1();
    else if (input==2)
        sample2();
    else if (input==3)
        sample3();
    else if (input==4)
    {
        getDFA();
    }
    return 0;
}
