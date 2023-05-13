
#ifndef NPDAACC_STACK_H
#define NPDAACC_STACK_H
#include <string>

class Stack
{
private:
    std::string stack="$";
public:
    void push(std::string push0);
    void pop(std::string pop0);
    std::string getTop()const;
    std::string getAll()const;
};


#endif //NPDAACC_STACK_H
