
#ifndef PROJECT1_STARTER_CODE_COMMAUTOMATON_H
#define PROJECT1_STARTER_CODE_COMMAUTOMATON_H

#include "Automaton.h"

class CommAutomaton : public Automaton
{
public:
    CommAutomaton() : Automaton(TokenType::COMMA) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //PROJECT1_STARTER_CODE_COMMAUTOMATON_H
