#include "Operations.h"
#include <iostream>
using namespace std;
NFA nfa;
int main() {

    int input;
    cout << "this program will convert NFA to DFA\n";
    cout << "for sample enter 1 and for input enter 2 : (in the latter inputs for lambda enter $)";
    cin >> input;
    if (input == 1) {
        State s1;
        s1.setName("q0");

        State s2;
        s2.setName("q1");
        State s3;
        s3.setName("q2");
        State s4;
        s4.setName("q3");
        State s5;
        s5.setName("q4");

        std::vector<std::string> alphabetA{"a"};
        std::vector<std::string> alphabets{"a", "b"};
        std::vector<std::string> alphabetB{"b"};
        std::vector<std::string> alphabet1{"$"};

        Transition t1;
        Transition t2;
        Transition t3;
        Transition t4;
        Transition t5;
        Transition t6;
        Transition t7;
        Transition t8;
        Transition t9;


        std::vector<std::vector<State *>> states1 = {{&s1},{&s2}};
        std::vector<std::vector<State *>> states2 = {{&s2},{&s1}};
        std::vector<std::vector<State *>> states3 = {{&s1},{&s3}};
        std::vector<std::vector<State *>> states4 = {{&s2},{&s3}};
        std::vector<std::vector<State *>> states5 = {{&s2},{&s4}};
        std::vector<std::vector<State *>> states6 = {{&s2},{&s5}};
        std::vector<std::vector<State *>> states7 = {{&s4},{&s5}};
        std::vector<std::vector<State *>> states8 = {{&s5},{&s4}};
        std::vector<std::vector<State *>> states9 = {{&s3},{&s5}};

        t1.setStates(states1);
        t2.setStates(states2);
        t3.setStates(states3);
        t4.setStates(states4);
        t5.setStates(states5);
        t6.setStates(states6);
        t7.setStates(states7);
        t8.setStates(states8);
        t9.setStates(states9);

        t1.setAlphabets(alphabet1);
        t2.setAlphabets(alphabetA);
        t3.setAlphabets(alphabetB);
        t4.setAlphabets(alphabet1);
        t5.setAlphabets(alphabet1);
        t6.setAlphabets(alphabetA);
        t7.setAlphabets(alphabetA);
        t8.setAlphabets(alphabet1);
        t9.setAlphabets(alphabetB);

        std::vector<Transition> transitions;
        std::vector<Transition> transitions1 = {t1,t3};
        std::vector<Transition> transitions2 = {t2,t4,t5,t6};
        std::vector<Transition> transitions3 = {t9};
        std::vector<Transition> transitions4 = {t7};
        std::vector<Transition> transitions5 = {t8};

        s1.setTransitions(transitions1);
        s2.setTransitions(transitions2);
        s3.setTransitions(transitions3);
        s4.setTransitions(transitions4);
        s5.setTransitions(transitions5);

        std::vector<std::vector<State >> states;
        states.push_back({s1});
        states.push_back({s2});
        states.push_back({s3});
        states.push_back({s4});
        states.push_back({s5});

        transitions.push_back(t1);
        transitions.push_back(t2);
        transitions.push_back(t3);
        transitions.push_back(t4);
        transitions.push_back(t5);
        transitions.push_back(t6);
        transitions.push_back(t7);
        transitions.push_back(t8);
        transitions.push_back(t9);

        nfa.setStates(states);
        nfa.setStartState({s1});
        nfa.setTransitions(transitions);
        nfa.setAlphabet(alphabets);
        nfa.getStates();
        nfa.setFinaStates({{s5}});
        cout << "before convert : \n";
        cout << "Start state: {";
        for (int i = 0; i < nfa.getStartState().size(); ++i) {
            if (i == nfa.getStartState().size() - 1)
                cout << nfa.getStartState()[i].getName();
            else
                cout << nfa.getStartState()[i].getName() << ",";
        }
        cout << "}" << "  ";
        cout << "\nAll States :\n";
        for (int i = 0; i < nfa.getStates().size(); ++i) {
            cout << "{";
            for (int j = 0; j < nfa.getStates()[i].size(); ++j) {
                if (j == nfa.getStates()[i].size() - 1)
                    cout << nfa.getStates()[i][j].getName();
                else
                    cout << nfa.getStates()[i][j].getName() << ",";
            }
            if (i != nfa.getStates().size() - 1)
                cout << "}" << ",";

            else
                cout << "}";
        }
        cout << "\nTransitions: " << endl;
        for (int i = 0; i < nfa.getTransitions().size(); ++i) {
            Transition temp = nfa.getTransitions()[i];
            vector<State *> tempS0{temp.getStates()[0]};
            vector<State *> tempS1{temp.getStates()[1]};
            cout << "{";
            for (int j = 0; j < tempS0.size(); ++j) {
                if (j == tempS0.size() - 1)
                    cout << tempS0[j]->getName();
                else
                    cout << tempS0[j]->getName() << ",";
            }
            cout << "}" << " with (" << temp.getAlphabets()[0] << ") To: ";
            cout << "{";
            for (int j = 0; j < tempS1.size(); ++j) {
                if (j == tempS1.size() - 1)
                    cout << tempS1[j]->getName();
                else
                    cout << tempS1[j]->getName() << ",";
            }
            cout << "}" << endl;
        }
        cout << "Final States :";
        for (int i = 0; i < nfa.getFinalStates().size(); ++i) {
            cout << "{";
            for (int j = 0; j < nfa.getFinalStates()[i].size(); ++j) {
                if (j == nfa.getFinalStates()[i].size() - 1)
                    cout << nfa.getFinalStates()[i][j].getName();
                else
                    cout << nfa.getFinalStates()[i][j].getName() << ",";
            }
            cout << "}" << "";

        }


        Operations operations;
        operations.convertToDFA(nfa);

    } else if (input == 2) {
        int numStates;

        std::vector<vector<State>> states;
        string name;
        vector<State >startState;
        cout << "how many states NFA has?(including start state) :";
        cin >> numStates;
        string temp;
        cout<<"enter NFA's alphabets (if is more than one separate with , between) :";
        cin>>temp;
        vector<string> alphabets;
        string t;
        for (int j = 0; j <temp.size() ; ++j) {
            if (temp[j]!=',') {
                t.push_back(temp[j]);
                alphabets.push_back(t);
            }
        }
        nfa.setAlphabet(alphabets);
        for (int i = 0; i < numStates; ++i) {
            cout << "\nenter state " << i + 1 << "'s name: ";
            cin >> name;
            State s;
            s.setName(name);
            states.push_back({s});
        }
        for (int i = 0; i < states.size(); ++i) {
            int numTransitions;
            vector<Transition > trans;
            cout << "\nenter number of transitions "<<states[i][0].getName()<<" has:  ";
            cin >> numTransitions;
            for (int i = 0; i < numTransitions; ++i) {
                Transition transition;
                vector<vector<State *>> states0;
                states0.push_back({&states[i][0]});
                vector<string> alphabets;
                string temp;
                cout << "enter Transition " << i + 1 << "'s alphabets (if is more than one separate with , between) :";
                cin >> temp;
                string t;
                for (int j = 0; j <temp.size() ; ++j) {
                    if (temp[j]!=',') {
                        t.push_back(temp[j]);
                        alphabets.push_back(t);
                    }
                }
                for (int j = 0; j < states.size(); ++j) {
                    if (states[j][0].getName() == name)
                        states0.push_back({&states[j][0]});
                }
                cout << "enter Transition " << i + 1 << "'s Destination State's name: ";
                cin >> name;
                for (int j = 0; j < states.size(); ++j) {
                    if (states[j][0].getName() == name)
                        states0.push_back({&states[j][0]});
                }
                transition.setStates(states0);
                transition.setAlphabets(alphabets);
                trans.push_back(transition);
            }
            states[i][0].setTransitions(trans);
        }
        cout<<"enter start state 's name: ";
        string startName;
        cin>>startName;
        for (int i = 0; i <states.size() ; ++i) {
            if (states[i][0].getName()==startName)
                startState=states[i];
        }
        nfa.setStartState(startState);
        int n;
        vector<vector<State >> finalStates;
        cout<<"how many final state NFA has: ";
        cin>>n;
        for (int i = 0; i <n ; ++i) {
            string name1;
            cout<<"enter final state "<<i+1<<" 's name: ";
            cin >>name1;
            for (int j = 0; j <states.size() ; ++j) {
                if (states[i][0].getName()==name1)
                    finalStates.push_back(states[i]);
            }
        }
        nfa.setFinaStates(finalStates);
        cout << "before convert : \n";
        cout << "Start state: {";
        for (int i = 0; i < nfa.getStartState().size(); ++i) {
            if (i == nfa.getStartState().size() - 1)
                cout << nfa.getStartState()[i].getName();
            else
                cout << nfa.getStartState()[i].getName() << ",";
        }
        cout << "}" << "  ";
        cout << "\nAll States :\n";
        for (int i = 0; i < nfa.getStates().size(); ++i) {
            cout << "{";
            for (int j = 0; j < nfa.getStates()[i].size(); ++j) {
                if (j == nfa.getStates()[i].size() - 1)
                    cout << nfa.getStates()[i][j].getName();
                else
                    cout << nfa.getStates()[i][j].getName() << ",";
            }
            if (i != nfa.getStates().size() - 1)
                cout << "}" << ",";

            else
                cout << "}";
        }
        cout << "\nTransitions: " << endl;
        for (int i = 0; i < nfa.getTransitions().size(); ++i) {
            Transition temp = nfa.getTransitions()[i];
            vector<State *> tempS0{temp.getStates()[0]};
            vector<State *> tempS1{temp.getStates()[1]};
            cout << "{";
            for (int j = 0; j < tempS0.size(); ++j) {
                if (j == tempS0.size() - 1)
                    cout << tempS0[j]->getName();
                else
                    cout << tempS0[j]->getName() << ",";
            }
            cout << "}" << " with (" << temp.getAlphabets()[0] << ") To: ";
            cout << "{";
            for (int j = 0; j < tempS1.size(); ++j) {
                if (j == tempS1.size() - 1)
                    cout << tempS1[j]->getName();
                else
                    cout << tempS1[j]->getName() << ",";
            }
            cout << "}" << endl;
        }
        cout << "Final States :";
        for (int i = 0; i < nfa.getFinalStates().size(); ++i) {
            cout << "{";
            for (int j = 0; j < nfa.getFinalStates()[i].size(); ++j) {
                if (j == nfa.getFinalStates()[i].size() - 1)
                    cout << nfa.getFinalStates()[i][j].getName();
                else
                    cout << nfa.getFinalStates()[i][j].getName() << ",";
            }
            cout << "}" << "";
        }

        Operations operations;
        operations.convertToDFA(nfa);
    }
}