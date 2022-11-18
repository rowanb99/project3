
#ifndef PROJECT1_STARTER_CODE_Q_MARKAUTOMATON_H
#define PROJECT1_STARTER_CODE_Q_MARKAUTOMATON_H

#include "Automaton.h"

class Q_markAutomaton : public Automaton
{
public:
    Q_markAutomaton() : Automaton(TokenType::Q_MARK) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //PROJECT1_STARTER_CODE_Q_MARKAUTOMATON_H
