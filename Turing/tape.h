#ifndef TURING_TAPE_H
#define TURING_TAPE_H
#include <string>

class Tape
{
private:
    std::string tape;
    int pointer=1;
public:
    Tape(std::string tape);
    void write(char writeValue);
    char read() const;
    void move(int moveValue);
};


#endif //TURING_TAPE_H
