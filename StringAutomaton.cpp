
#include "StringAutomaton.h"
void StringAutomaton::S0(const std::string& input) {
    if (input[index] == '\'') {
        inputRead ++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void StringAutomaton::S1(const std::string& input)
{
//    int aCounter = 0;
    long unsigned int longIndex = index;
    if(longIndex >= input.size())
    {
//        Serr();
//        return;
        type= TokenType::UNDEFINED;
        return;
    }
    else if(input[index] != '\'' && longIndex < input.size())
    {
        if(input[index] == '\n')
        {
            newLines++;
        }
        inputRead ++;
        index++;

//        aCounter++;
        S1(input);
    }
    else if(input[index] == '\''&& longIndex < input.size())
    {
        inputRead ++;
        index++;
        S2(input);
    }
    else
    {
        Serr();
    }

}
void StringAutomaton::S2(const std::string& input)
{
    if(input[index] == '\'')
    {
        inputRead ++;
        index++;
        S1(input);
    }
//    else
//    {
//        Serr();
//    }
}