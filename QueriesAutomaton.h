//
// Created by vj234 on 9/21/22.
//

#ifndef PROJECT1_STARTER_CODE_QUERIESAUTOMATON_H
#define PROJECT1_STARTER_CODE_QUERIESAUTOMATON_H

#include "Automaton.h"

class QueriesAutomaton : public Automaton
{
private:
    void u1(const std::string& input);
    void e2(const std::string& input);
    void r3(const std::string& input);
    void i4(const std::string& input);
    void e5(const std::string& input);
    void s6(const std::string& input);
public:
    QueriesAutomaton() : Automaton(TokenType::QUERIES) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //PROJECT1_STARTER_CODE_QUERIESAUTOMATON_H
