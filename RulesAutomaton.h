
#ifndef PROJECT1_STARTER_CODE_RULESAUTOMATON_H
#define PROJECT1_STARTER_CODE_RULESAUTOMATON_H

#include "Automaton.h"

class RulesAutomaton : public Automaton
{
private:
    void u1(const std::string& input);
    void l2(const std::string& input);
    void e3(const std::string& input);
    void s4(const std::string& input);
public:
    RulesAutomaton() : Automaton(TokenType::RULES) {}  // Call the base constructor

    void S0(const std::string& input);

};


#endif //PROJECT1_STARTER_CODE_RULESAUTOMATON_H
