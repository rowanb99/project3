#ifndef LEXER_H
#define LEXER_H
#include <vector>
#include "Automaton.h"
#include "Token.h"

class Lexer
{
private:
    std::vector<Automaton*> automata;
    std::vector<Token*> tokens;

    void CreateAutomata();
    //void cycleAutomata(string &input, int &lineNum);  // Might not actually use this

    // TODO: add any other private methods here (if needed)

public:
    Lexer();
    ~Lexer();

    void Run(std::string& input);

    void removeWhiteSpace(string& input, int& lineNumber);

    int parallelAlgorithm(string& input, Automaton*& maxAutomaton, int& maxRead);

    void maxAlgorithm(string& input, Automaton*& maxAutomaton, int& lineNumber, int& maxRead);

    string lexerToString();

    vector<Token*> lexerResults();

};

#endif // LEXER_H

