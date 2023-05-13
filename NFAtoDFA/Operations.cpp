#include "Operations.h"
#include <iostream>
using namespace std;
template <class t>
bool Operations::find(std::vector<t> a,t b) {
    for (int i = 0; i < a.size(); ++i) {
        if (a[i]== b) {
            return true;
        }
    }
    return false;
}
template <class t>
bool Operations::find2(std::vector<vector<t>> a,vector<t> b) {
    // dar vector a har vector ra barresi mikonim

    for (int i = 0; i <a.size() ; ++i) {
        if (b.size()>=a[i].size()){
        // yek bar har halat onsor haye b ra baressi mikonim
        int n=b.size();
        for (int j = 0; j < a[i].size(); ++j) {
            for (int k = 0; k <b.size() ; ++k) {
                if (a[i][j]==b[k])
                    n--;
            }
        }
        if (n==0)
            return true;
        else
            n=b.size();
    }
    }
    return false;
}
vector<State> rr(vector<State*> a)
{
    vector<State> h;
    for (int i = 0; i <a.size() ; ++i) {

    h.push_back(*a[i]);
    }
    return h;
}template <class t>
bool Operations::find3(std::vector<vector<t>> a,vector<t> b,int &n) {
    // dar vector a har vector ra barresi mikonim

    for (int i = 0; i <a.size() ; ++i) {
        if (b.size()>=a[i].size()){
        // yek bar har halat onsor haye b ra baressi mikonim
        int p=b.size();
        for (int j = 0; j < a[i].size(); ++j) {
            for (int k = 0; k <b.size() ; ++k) {
                if (a[i][j]==b[k])
                    p--;
            }
        }
        if (p==0) {
            n=i;
            return true;
        }
        else
            p=b.size();
    }
    }
    return false;
}
void Operations::buildTransition(vector<Transition> &transitions,vector<State > &state0,vector<State > &state1,string alpha)
{
    Transition transition10;
    transition10.setAlphabets({alpha});
    vector<State*> a,b;
    for (int i = 0; i <state0.size() ; ++i) {
        a.push_back(&state0[i]);
    }
    for (int i = 0; i <state1.size() ; ++i) {
        b.push_back(&state1[i]);
    }
    std::vector<std::vector<State *>> states1j = {a, b};
    transition10.setStates(states1j);
    transitions.push_back(transition10);
}
void Operations::addLambdaState(vector<vector<State >> &temp,vector<State > s) {
    //baraye har state s
    for (int q = 0; q <s.size() ; ++q)
    // baraye har ghozar s
    for (int i = 0; i < s[q].getTransitions().size(); ++i)
    {
        // aghar daraye lambda bood
        if (find<string>(s[q].getTransitions()[i].getAlphabets(), "$")) {

            // agha r dar temp nabood ghozar ro be temp azafe kon
            if (!find2<State >(temp,rr(s[q].getTransitions()[i].getStates()[1]))) {
                temp.push_back(rr(s[q].getTransitions()[i].getStates()[1]));

            }
            // va sepas hamin karro baye ghozar ezafe shode anjam bede
            for (int j = 0; j <s[q].getTransitions()[i].getStates()[1].size() ; ++j) {
                for (int k = 0; k < s[q].getTransitions()[i].getStates()[1][j]->getTransitions().size(); ++k) {
                    if (find<string>(s[q].getTransitions()[i].getStates()[1][j]->getTransitions()[k].getAlphabets(),"$"))
                        addLambdaState(temp,rr(s[q].getTransitions()[i].getStates()[1]));
                }
            }
        }
    }
}
vector<State > Operations::findStartState(vector<State>  NFAStartState )
{
    vector<string> alpha;
    vector<State > start;
    vector<vector<State >> startStates={NFAStartState};
    // dar state hayye ke state shoroee nfa be anha ghozar darad donbal alphaye $ beghard
    // va aghar bood be state shoro ezafe kon
    for (int i = 0; i < NFAStartState[0].getTransitions().size(); ++i) {
        alpha=NFAStartState[0].getTransitions()[i].getAlphabets();
        if (find<string>(alpha,"$"))
            startStates.push_back(rr(NFAStartState[0].getTransitions()[i].getStates()[1]));
            addLambdaState(startStates, rr(NFAStartState[0].getTransitions()[i].getStates()[1]));
    }
    // state haye state haye(ghalat emlayee nist toziheshe ) shoro ro be ye state tabdil kon
    for (int i = 0; i <startStates.size() ; ++i) {
        for (int j = 0; j <startStates[i].size() ; ++j) {
            start.push_back(startStates[i][j]);
        }
    }
    return start;
}
void Operations::readLambda(vector<vector<State >> &temp,string alpha,vector<State > s)
{
    // baraye har ozve s

    for (int q = 0; q < s.size(); ++q)
    {
        for (int i = 0; i < s[q].getTransitions().size(); ++i)
        {
            if (find<string>(s[q].getTransitions()[i].getAlphabets(), alpha))
            {
                // aghar dar temp nabood
                if (!find2<State>(temp, rr(s[q].getTransitions()[i].getStates()[1])))
                    temp.push_back(rr(s[q].getTransitions()[i].getStates()[1]));
                // dobare bareye state peyda shode donbal lambda beghard
                addLambdaState(temp, rr(s[q].getTransitions()[i].getStates()[1]));
            }

        }
        //aghar dobare lambda khond
        for (int i = 0; i < s[q].getTransitions().size(); ++i)
        {
            if (find<string>(s[q].getTransitions()[i].getAlphabets(), "$"))
            {
                readLambda(temp, alpha, rr(s[q].getTransitions()[i].getStates()[1]));
            }
        }
    }
}
void Operations::newStates(vector<string> alpha,vector<vector<State >> &states ,vector<Transition> &transitions,int num)
{
    // baraye har alphba
    for (int i = 0; i < alpha.size(); ++i){
        vector<State > stat;
        // state hai dakhel state num ro barresi mikonim
        vector<vector<State >> temp = {};
        for (int j = 0; j < states[num].size(); ++j)
        {

            // hameie ghozar hara barresi karde
            for (int k = 0; k < states[num][j].getTransitions().size(); ++k)
            {
                // aghar alphbaye ghozar barabar baalphbaye i bashad
                if (find<string>(states[num][j].getTransitions()[k].getAlphabets(), alpha[i]))
                {
                    // aghar alphba dar ghozar bood va dar temp nabood state magsad ra be temp ezafe mikonim
                    if (!find2<State >(temp, rr(states[num][j].getTransitions()[k].getStates()[1])))
                        temp.push_back(rr(states[num][j].getTransitions()[k].getStates()[1]));
                    // sepas state hayee ka ba lambda az in state rah darand ra ezafe mikonim
                    addLambdaState(temp, rr(states[num][j].getTransitions()[k].getStates()[1]));

                }
                //aghar state ghozar lambda dasht
                if (find<string>(states[num][j].getTransitions()[k].getAlphabets(), "$"))
                {
                    // boro be state mazkor
                    readLambda(temp, alpha[i], rr(states[num][j].getTransitions()[k].getStates()[1]));
                }

            }

        }
        // tabdil temp be stat
            for (int i = 0; i < temp.size(); ++i)
            {
                for (int j = 0; j < temp[i].size(); ++j)
                {
                    if (!find<State >(stat, temp[i][j]))
                        stat.push_back(temp[i][j]);
                }
            }
            // aghar be hichkodam az state ha naraft
            if (stat.size() == 0)
            {

                State empty;
                empty.setName("empty");
                vector<State> ss={empty};
                int n;
                if (find3<State>(states,ss,n)) {
                    buildTransition(transitions,states[num],states[n],alpha[i]);
                }
                else {
                    states.push_back(ss);
                    buildTransition(transitions, states[num], states[states.size() - 1], alpha[i]);
                }

            // be state raft valy state taze bood va dar states nabod
            }
            else if (!find2<State >(states, stat))
            {
                states.push_back(stat);
                buildTransition(transitions,states[num],states[states.size()-1],alpha[i]);

            //aghar stat dar states ast
            }
            else if (find2<State >(states, stat))
            {
                int n;
                find3<State>(states,stat,n);
                buildTransition(transitions,states[num],states[n],alpha[i]);

            }

        }
        // aghar state ezafe shod baraye an ham dobare transition ha ro moshakhas kon
        if (states.size() > num + 1)
        {
            newStates(alpha, states, transitions, num + 1);
        }


}
void Operations::findFinalStates(std::vector<std::vector<State >> &states,std::vector<std::vector<State >> NFAfinalStates,vector<vector<State >> &finalStates0)
{
    for (int i = 0; i <NFAfinalStates.size() ; ++i)
        for (int j = 0; j < states.size(); ++j)
            for (int k = 0; k < states[j].size(); ++k)
        if (find<State >(NFAfinalStates[i],states[j][k]))
            finalStates0.push_back(states[j]);

}
void Operations::convertToDFA(NFA &nfa)
{

    vector<vector<State >> finalStates;
    vector<vector<State >> states0;
    vector<vector<State >> finalStates0;
    vector<Transition> transitions;
    states0.push_back(findStartState(nfa.getStartState()));
    newStates(nfa.getAlphabets(),states0,transitions,0);
    findFinalStates(states0,nfa.getFinalStates(),finalStates0);
    nfa.setStartState(states0[0]);
    nfa.setStates(states0);
    nfa.setTransitions(transitions);
    nfa.setFinaStates(finalStates0);


    cout << "\n/////////////////////////////////////////\nAfter Convert:\nStart state: {";
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
    vector<Transition> tr=nfa.getTransitions();
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
        cout << "}" << " ";
    }
    cout << "\n";

}