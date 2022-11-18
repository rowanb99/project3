
#ifndef PROJECT1_STARTER_CODE_ID_AUTOMATON_H
#define PROJECT1_STARTER_CODE_ID_AUTOMATON_H

#include "Automaton.h"

class ID_Automaton : public Automaton
{
private:
    void S1(const std::string& input);
public:
    ID_Automaton() : Automaton(TokenType::ID) {}  // Call the base constructor

    void S0(const std::string& input);

    bool isNotOtherToken( string basicString, int i);
};


#endif //PROJECT1_STARTER_CODE_ID_AUTOMATON_H
