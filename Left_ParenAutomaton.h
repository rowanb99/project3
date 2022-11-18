
#ifndef PROJECT1_STARTER_CODE_LEFT_PARENAUTOMATON_H
#define PROJECT1_STARTER_CODE_LEFT_PARENAUTOMATON_H

#include "Automaton.h"

class Left_ParenAutomaton : public Automaton
{
public:
    Left_ParenAutomaton() : Automaton(TokenType::LEFT_PAREN) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //PROJECT1_STARTER_CODE_LEFT_PARENAUTOMATON_H
