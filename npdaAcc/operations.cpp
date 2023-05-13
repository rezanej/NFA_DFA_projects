#include "operations.h"
void Operations::a(State s, Stack stack, std::string &inp, int i, int l, bool &accept)
{
    if (stack.getAll()=="ab")
        int o;
    std::string p;
    p.push_back(inp[i]);
    if (i == l && s.getIsFinal()) {
        accept = true;
    }
     else {
        for (int j = 0; j < s.getTransitions().size(); ++j) {

                if (s.getTransitions()[j].getAlphabet() == p && s.getTransitions()[j].getPop() == stack.getTop()) {
                    Stack st;
                    st.push(stack.getAll());
                    st.pop(s.getTransitions()[j].getPop());
                    st.push(s.getTransitions()[j].getPush());
                    a(*s.getTransitions()[j].getStates()[1], st, inp, i + 1, l, accept);

                }
                 else if (s.getTransitions()[j].getAlphabet() == p && s.getTransitions()[j].getPop() == "%") {
                    Stack st;
                    st.push(stack.getAll());
                    st.push(s.getTransitions()[j].getPush());
                    a(*s.getTransitions()[j].getStates()[1], st, inp, i + 1, l, accept);

                }
                 else if (s.getTransitions()[j].getAlphabet() == "%" && s.getTransitions()[j].getPop() == "%") {
                    Stack st;
                    st.push(stack.getAll());
                    st.push(s.getTransitions()[j].getPush());
                    a(*s.getTransitions()[j].getStates()[1], st, inp, i, l, accept);

                }
                 else if (s.getTransitions()[j].getAlphabet() == "%" && s.getTransitions()[j].getPop() == stack.getTop()) {
                    Stack st;
                    st.push(stack.getAll());
                    st.pop(s.getTransitions()[j].getPop());
                    st.push(s.getTransitions()[j].getPush());
                    a(*s.getTransitions()[j].getStates()[1], st, inp, i, l, accept);

                }

        }
    }
}
bool Operations::NPDAaccept(NPDA npda, std::string input)
{

    int L=input.size();
    int i=0;
    Stack stack;
    bool accept= false;
    a(npda.getStartState(),stack,input,0,L,accept);
    return accept;
}
