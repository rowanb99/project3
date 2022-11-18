
#ifndef PROJECT1_STARTER_CODE_BLOCKCOMMENT_AUTOMATON_H
#define PROJECT1_STARTER_CODE_BLOCKCOMMENT_AUTOMATON_H

#include "Automaton.h"

class BlockComment_Automaton : public Automaton
{
private:
    void S1(const std::string& input);
    void S2(const std::string& input);
    void S3(const std::string& input);
    void S4(const std::string& input);
public:
    BlockComment_Automaton() : Automaton(TokenType::COMMENT) {}  // Call the base constructor

    void S0(const std::string& input);

};


#endif //PROJECT1_STARTER_CODE_BLOCKCOMMENT_AUTOMATON_H
