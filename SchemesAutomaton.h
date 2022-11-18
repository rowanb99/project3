

#ifndef PROJECT1_STARTER_CODE_SCHEMESAUTOMATON_H
#define PROJECT1_STARTER_CODE_SCHEMESAUTOMATON_H

#include "Automaton.h"

class SchemesAutomaton : public Automaton
{
private:
    void c1(const std::string& input);
    void h2(const std::string& input);
    void e3(const std::string& input);
    void m4(const std::string& input);
    void e5(const std::string& input);
    void s6(const std::string& input);


public:
    SchemesAutomaton() : Automaton(TokenType::SCHEMES) {}  // Call the base constructor

    void S0(const std::string& input);

};


#endif //PROJECT1_STARTER_CODE_SCHEMESAUTOMATON_H
