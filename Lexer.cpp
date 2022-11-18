#include "Lexer.h"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"
#include "CommAutomaton.h"
#include "BlockComment_Automaton.h"
#include "EOF_Automaton.h"
#include "FactsAutomaton.h"
#include "ID_Automaton.h"
#include "Left_ParenAutomaton.h"
#include "MultiplyAutomaton.h"
#include "PeriodAutomaton.h"
#include "Automaton.h"
#include "RulesAutomaton.h"
#include "SchemesAutomaton.h"
#include "StringAutomaton.h"
#include "Right_ParenAutomaton.h"
#include "AddAutomaton.h"
#include "Q_markAutomaton.h"
#include "QueriesAutomaton.h"
#include "LineCommentAutomaton.h"
#include <iostream>
#include <vector>

using namespace std;

Lexer::Lexer() {
    CreateAutomata();
}

Lexer::~Lexer() {
    // TODO: need to clean up the memory in `automata` and `tokens`
}

void Lexer::CreateAutomata() {
    automata.push_back(new ColonAutomaton());
    automata.push_back(new ColonDashAutomaton());
    automata.push_back(new CommAutomaton());
    automata.push_back(new BlockComment_Automaton());
    automata.push_back(new EOF_Automaton());
    automata.push_back(new FactsAutomaton());
    automata.push_back(new RulesAutomaton());
    automata.push_back(new QueriesAutomaton());
    automata.push_back(new LineCommentAutomaton());
    automata.push_back(new Left_ParenAutomaton());
    automata.push_back(new Right_ParenAutomaton());
    automata.push_back(new MultiplyAutomaton());
    automata.push_back(new AddAutomaton());
    automata.push_back(new PeriodAutomaton());
    automata.push_back(new SchemesAutomaton());
    automata.push_back(new StringAutomaton());
    automata.push_back(new Q_markAutomaton());
    automata.push_back(new ID_Automaton());         // Should this be after all Automata

    // TODO: Add the other needed automata here
}

void Lexer::Run(std::string& input) {
    // TODO: convert this pseudo-code with the algorithm into actual C++ code
    // set lineNumber to 1
    int lineNumber = 1;                                                         // If there are issues with line numbers, it could come from this not being put into a runAutomata function...
    while (!input.empty()) {
        int maxRead = 0;
        Automaton* maxAutomaton = automata[0];
        removeWhiteSpace(input, lineNumber);
        parallelAlgorithm(input, maxAutomaton, maxRead);
        maxAlgorithm(input, maxAutomaton, lineNumber, maxRead);

        string newInput;
        for (unsigned int i = maxRead; i < input.size(); ++i) {
            newInput += input[i];
        }
        input = newInput;

    }
    // Add end of file token to all tokens
    Token* eofToken = new Token(TokenType::EOF_TOKEN, "", lineNumber);         // Once the string ends create an End Of File token
    tokens.push_back(eofToken);
}

void Lexer::removeWhiteSpace(string& input, int& lineNumber) {                                     // TODO: you need to handle whitespace inbetween tokens
    while (isspace(input[0])) {
        if (input[0] == '\n') {
            lineNumber++;
        }
        input = input.substr(1);
    }
}

// Here is the "Parallel" part of the algorithm
int Lexer::parallelAlgorithm(string& input, Automaton*& maxAutomaton, int& maxRead) {
    int inputRead;
    for (unsigned int i = 0; i < automata.size(); ++i)
    {
        inputRead = automata[i]->Start(input);

        if (inputRead > maxRead)
        {
            maxRead = inputRead;
            maxAutomaton = automata[i];
        }
    }
    return inputRead;
}

// Here is the "Max" part of the algorithm
void Lexer::maxAlgorithm(string& input, Automaton*& maxAutomaton, int& lineNumber, int& maxRead) {
    if (maxRead > 0)
    {
        Token* newToken = maxAutomaton->CreateToken(input.substr(0, maxRead), lineNumber);
        lineNumber += maxAutomaton->NewLinesRead();
        tokens.push_back(newToken);
    }
        // No automaton accepted input
        // Create single character undefined token
    else if(!input.empty())
    {
        maxRead = 1;
        Token* maxzToken = new Token(TokenType::UNDEFINED, input.substr(0, maxRead), lineNumber);
        tokens.push_back(maxzToken);
    }
    else
    {
        return;
    }


}

string Lexer::lexerToString()
{
    string output;
    for(unsigned int i = 0; i < tokens.size(); ++i)
    {
        output += tokens[i]->toString() + '\n';
    }
    output += "Total Tokens = " + to_string(tokens.size());
    return output;
}

vector<Token*> Lexer::lexerResults() {
    return tokens;
}