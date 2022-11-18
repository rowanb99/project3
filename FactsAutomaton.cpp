
#include "FactsAutomaton.h"

void FactsAutomaton::S0(const std::string &input)
{
    if (input[index] == 'F') {
        inputRead++;
        index++;
        a1(input);
    }
    else {
        Serr();
    }
}
void FactsAutomaton::a1(const std::string &input)
{
    if (input[index] == 'a') {
        inputRead++;
        index++;
        c2(input);
    }
    else {
        Serr();
    }
}
void FactsAutomaton::c2(const std::string &input)
{
    if (input[index] == 'c') {
        inputRead++;
        index++;
        t3(input);
    }
    else {
        Serr();
    }
}
void FactsAutomaton::t3(const std::string &input)
{
    if (input[index] == 't') {
        inputRead++;
        index++;
        s4(input);
    }
    else {
        Serr();
    }
}
void FactsAutomaton::s4(const std::string &input)
{
    if (input[index] == 's'&& !isalpha(input[index+1])) {
        inputRead++;
    }
    else {
        Serr();
    }
}