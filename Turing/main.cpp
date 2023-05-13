#include <iostream>
#include "turing.h"
#include "operations.h"
using namespace std;
void show(Turing turing,string name)
{

    cout<<name<<" with states : ";
    for (int i = 0; i <turing.getStates().size() ; ++i) {
        cout<<turing.getStates()[i].getName()<<" ";
    }
    cout<<"\nAlphabets : ";
    for (int i = 0; i <turing.getAlphabets().size() ; ++i) {
        cout<<turing.getAlphabets()[i]<<" ";
    }
    cout<<"\nstart state :"<<turing.getStartState().getName();
    cout<<"\nFinal state(s) : ";
    for (int i = 0; i <turing.getStates().size() ; ++i) {
        if (turing.getStates()[i].getIsFinal())
            cout<<turing.getStates()[i].getName()<<" ";
    }
    cout<<"\ntransitions : \n";
    for (int i = 0; i <turing.getTransitions().size() ; ++i) {
        cout<<turing.getTransitions()[i].getStates()[0]->getName()<<"--"<<turing.getTransitions()[i].getRead()<<","
        <<turing.getTransitions()[i].getWrite()<<","<<((turing.getTransitions()[i].getMove()==1)?"R":"L")<<"-->"<<turing.getTransitions()[i].getStates()[1]->getName()<<endl;
    }

}

void TuringGetAlphabet(vector<string> &alphabet)
{
    string t;
    cout << "enter Turing's alphabets separate with (,) :";
    cin >> t;
    for (int k = 0; k < t.size(); ++k) {
        if (t[k] != ',') {
            string temp;
            temp.push_back(t[k]);
            alphabet.push_back(temp);
        }
    }
}
void TuringGetStates(vector<State> &states)
{
    int n;
    cout << "enter how many states Turing has : ";
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
void TuringGetTransitions(vector<Transition> &transitionsA,vector<State> &states)
{
    string name;
    for (int i = 0; i < states.size(); ++i) {
        vector<Transition> transitions;
        cout << "enter how many Transition " << states[i].getName() << " has :";
        int num;
        cin >> num;

        for (int j = 0; j < num; ++j) {
            char read;
            char write;
            char move;
            int moveValue;
            std::vector<State *> states0;
            states0.push_back(&states[i]);
            string t;
            cout << "\nenter transtion " << j << "'s read :";
            cin >> read;
            cout << "enter transtion " << j << "'s write :";
            cin >> write;
            cout << "enter transtion " << j << "'s move direction : for Right R and for left L : ";
            cin >> move;
            if (move=='R')
                moveValue=1;
            else if(move=='L')
                moveValue=-1;

            cout << "\nenter destination State's name : ";
            cin >> name;
            for (int j = 0; j < states.size(); ++j) {
                if (states[j].getName() == name) {
                    states0.push_back(&states[j]);
                    break;
                }
            }
            Transition transition=Transition(states0,read,write,moveValue);
            transitions.push_back(transition);
            transitionsA.push_back(transition);
        }
        states[i].setTransitions(transitions);

    }

}
void TuringGetStartState(Turing &turing, vector<State> states)
{
    string name;
    cout << "enter start state's name: ";
    cin >> name;
    for (State s:states)
        if (s.getName() == name)
            turing.setStartState(s);
}
void TuringGetFinalStates(vector<State> &states,string name0) {
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
void getTuringstringInput(Turing turing)
{
    bool p= true;
    while (p)
    {
        string inp;
        cout<<"\nenter the string that you want to test (for exit enter exit): ";
        cin>>inp;
        if (inp=="exit")
            break;
        Operations o;
        if(o.turingAccept(turing,inp))
        {
            show(turing,"Turing");
            cout<<"\nTuring accepts the string: "<<inp;
        } else {
            show(turing,"Turing");
            cout << "\nTuring does not accept string: " << inp;
        }
    }
}
void sample1() {
    Turing turing;
    State s0, s1;
    s0.setName("q0");
    s1.setName("q1");
    s1.setIsFinal(true);
    s0.setIsStart(true);
    Transition t0=Transition({&s0,&s0},'a','a',1);
    Transition t1=Transition({&s0,&s1},'#','#',-1);
    s0.setTransitions({t0,t1});
    turing.setStates({s0,s1});
    turing.setStartState(s0);
    turing.setTransitions({t0,t1});
    Operations o;
    show(turing,"Turing");
    std::cout<<((o.turingAccept(turing,"aaab")==0)?"does not ":"")<<"accepts "<<"aaab";

}
void sample2() {
    Turing turing;
    State s0, s1,s2,s3,s4;
    s0.setName("q0");
    s1.setName("q1");
    s2.setName("q2");
    s3.setName("q3");
    s4.setName("q4");
    s4.setIsFinal(true);
    s0.setIsStart(true);
    Transition t0=Transition({&s0,&s1},'a','x',1);
    Transition t1=Transition({&s0,&s3},'y','y',1);
    Transition t2=Transition({&s1,&s1},'y','y',1);
    Transition t3=Transition({&s1,&s1},'a','a',1);
    Transition t4=Transition({&s1,&s2},'b','y',-1);
    Transition t5=Transition({&s2,&s2},'y','y',-1);
    Transition t6=Transition({&s2,&s2},'a','a',-1);
    Transition t7=Transition({&s2,&s0},'x','x',1);
    Transition t8=Transition({&s3,&s3},'y','y',1);
    Transition t9=Transition({&s3,&s4},'#','#',-1);
    s0.setTransitions({t0,t1});
    s1.setTransitions({t2,t3,t4});
    s2.setTransitions({t5,t6,t7});
    s3.setTransitions({t8,t9});
    turing.setStates({s0,s1,s2,s3,s4});
    turing.setStartState(s0);
    turing.setTransitions({t0,t1,t2,t3,t4,t5,t6,t7,t8,t9});
    Operations o;
    show(turing,"Turing");
    std::cout<<((o.turingAccept(turing,"aabb")==0)?"does not ":"")<<"accepts "<<"aabb";
}
void getTuring()
{
    Turing turing;
    vector<Transition> transitions;
    std::vector<State > states;
    std::vector<std::string> alphabet0;
    TuringGetStates(states);
    TuringGetAlphabet(alphabet0);
    turing.setAlphabet(alphabet0);
    TuringGetTransitions(transitions,states);
    TuringGetStartState(turing,states);
    TuringGetFinalStates(states,"Turing");
    turing.setStates(states);
    turing.setTransitions(transitions);
    getTuringstringInput(turing);
}
int main()
{
    int input;
    cout<<"for sample 1,2 enter 1 or 2 and for custom input enter 3 : (in the latter inputs for empty enter #)";
    cin>>input;
    if (input==1)
        sample1();
    else if (input==2)
        sample2();
    else if (input==3)
        getTuring();

    return 0;
}
