
#include "stack.h"
void Stack::pop(std::string pop0) {
    if (pop0[0]==stack[stack.size()-1])
        stack.pop_back();
}
void Stack::push(std::string push0) {
    if (push0!="%")
    for (int i = push0.size()-1; i >=0 ; i--) {
        stack.push_back(push0[i]);
    }
}
std::string Stack::getTop() const {
    std::string s;
    s.push_back(stack[stack.size()-1]);
    return s;
}
std::string Stack::getAll() const {
    std::string s;
    for (int i = stack.size()-1; i >0; i--) {
        s.push_back(stack[i]);
    }
    return s;
}