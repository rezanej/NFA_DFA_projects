#include <iostream>
#include "operations.h"
using namespace std;
void show(NPDA npda)
{

    cout<<"NPDA with states : ";
    for (int i = 0; i <npda.getStates().size() ; ++i) {
        cout<<npda.getStates()[i].getName()<<" ";
    }
    cout<<"\nAlphabets : ";
    for (int i = 0; i <npda.getAlphabets().size() ; ++i) {
        cout<<npda.getAlphabets()[i]<<" ";
    }
    cout<<"\nstart state :"<<npda.getStartState().getName();
    cout<<"\nFinal state(s) : ";
    for (int i = 0; i <npda.getStates().size() ; ++i) {
        if (npda.getStates()[i].getIsFinal())
            cout<<npda.getStates()[i].getName()<<" ";
    }
    cout<<"\ntransitions : \n";
    for (int i = 0; i <npda.getTransitions().size() ; ++i) {
        cout<<npda.getTransitions()[i].getStates()[0]->getName()<<"--"<<npda.getTransitions()[i].getAlphabet()
            <<","<<npda.getTransitions()[i].getPop()<<","<<npda.getTransitions()[i].getPush()<<"-->"<<npda.getTransitions()[i].getStates()[1]->getName()<<endl;
    }

}
void sample1()
{
    State s1,s2,s3;
    s1.setName("q1");
    s1.setIsStart(true);
    s2.setName("q2");
    s3.setName("q3");
    s3.setIsFinal(true);
    Transition t1=Transition("a",{&s1,&s1},"%","a");
    Transition t2=Transition("b",{&s1,&s2},"a","%");
    Transition t3=Transition("b",{&s2,&s2},"a","%");
    Transition t4=Transition("%",{&s2,&s3},"$","$");
    s1.setTransitions({t1,t2});
    s2.setTransitions({t3,t4});
    NPDA npda;
    npda.setStates({s1,s2,s3});
    npda.setStartState(s1);
    npda.setTransitions({t1,t2,t3,t4});
    Operations o;

    if(o.NPDAaccept(npda,"aaabbb"))
    {
        show(npda);
        cout<<"\nNPDA accepts the string: "<<"aaabbb";
    } else {
        show(npda);
        cout << "\nNPDA does not accept string: " << "aaabbb";
    }


}
void sample2()
{
    State s1,s2,s3;
    s1.setName("q0");
    s1.setIsStart(true);
    s2.setName("q1");
    s3.setName("q2");
    s3.setIsFinal(true);
    Transition t1=Transition("a",{&s1,&s1},"%","a");
    Transition t2=Transition("b",{&s1,&s1},"%","b");
    Transition t3=Transition("%",{&s1,&s2},"%","%");
    Transition t4=Transition("a",{&s2,&s2},"a","%");
    Transition t5=Transition("b",{&s2,&s2},"b","%");
    Transition t6=Transition("%",{&s2,&s3},"$","$");
    s1.setTransitions({t1,t2,t3});
    s2.setTransitions({t4,t5,t6});
    NPDA npda;
    npda.setStates({s1,s2,s3});
    npda.setStartState(s1);
    npda.setStartState(s1);
    npda.setTransitions({t1,t2,t3,t4,t5,t6});
    Operations o;

    if(o.NPDAaccept(npda,"abbbba"))
    {
        show(npda);
        cout<<"\nNPDA accepts the string: "<<"abbbba";
    } else {
        show(npda);
        cout << "\nNPDA does not accept string: " << "abbbba";
    }


}

void NPDAGetAlphabet(vector<string> &alphabet ,string name)
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
void NPDAGetStates(vector<State> &states,string name0)
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
void NPDAGetTransitions(vector<State> &states)
{
    string name;
    for (int i = 0; i < states.size(); ++i) {
        vector<Transition> transitions;
        cout << "enter how many Transition " << states[i].getName() << " has :";
        int num;
        cin >> num;

        for (int j = 0; j < num; ++j) {
            std::string alphabet;
            std::vector<State *> states0;
            states0.push_back(&states[i]);
            string t;
            cout << "enter transtion " << j << "'s alphabet";
            cin >> alphabet;
            cout << "enter destination State's name : ";
            cin >> name;
            for (int j = 0; j < states.size(); ++j) {
                if (states[j].getName() == name) {
                    states0.push_back(&states[j]);
                    break;
                }
            }
            string popAlpha;
            cout<<"enter transition"<<j<<"'s pop character : ";
            cin>>popAlpha;
            string pushString;
            cout<<"enter transition"<<j<<"'s push string : ";
            cin>>pushString;
            Transition transition=Transition(alphabet,states0,popAlpha,pushString);
            transition.setAlphabet(alphabet);
            transition.setStates(states0);
            transitions.push_back(transition);

        }
        states[i].setTransitions(transitions);

    }

}
void NPDAGetStartState(NPDA npda, vector<State> states)
{
    string name;
    cout << "enter start state's name: ";
    cin >> name;
    for (State s:states)
        if (s.getName() == name)
            npda.setStartState(s);
}
void NPDAGetFinalStates(vector<State> &states,string name0) {
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
void getNPDAstringInput(NPDA npda)
{
    bool p= true;
    while (p)
    {
        string inp;
        cout<<"enter the string that you want to test (for exit enter exit): ";
        cin>>inp;
        if (inp=="exit")
            break;
        Operations o;
        if(o.NPDAaccept(npda,inp))
        {
            show(npda);
            cout<<"\nNPDA accepts the string: "<<inp;
        } else {
            show(npda);
            cout << "\nNPDA does not accept string: " << inp;
        }
    }
}
void getNPDA()
{
    NPDA npda;
    std::vector<State > states;
    std::vector<std::string> alphabet0;
    NPDAGetStates(states,"NPDA");
    NPDAGetAlphabet(alphabet0,"NPDA");
    npda.setAlphabet(alphabet0);
    NPDAGetTransitions(states);
    NPDAGetStartState(npda,states);
    NPDAGetFinalStates(states,"NPDA");
    npda.setStates(states);
    getNPDAstringInput(npda);
}
int main()
{
   cout<<"this progrma will get an npda and a string  and check it that accept or not.";
   cout<<"\nfor samples enter 1,2 and for custom input enter 3 (in the latter inputs for lambda enter %):\n";
   int inp;
   cin>>inp;
    if (inp==1)
        sample1();
    else if (inp==2)
        sample2();
    else if (inp==3)
        getNPDA();
    return 0;
}
