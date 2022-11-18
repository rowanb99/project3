
#include "BlockComment_Automaton.h"
void BlockComment_Automaton::S0(const std::string& input)
{
    if (input[index] == '#')
    {
        inputRead ++;
        index++;
        S1(input);
    }
    else
        {
        Serr();
    }
}
void BlockComment_Automaton::S1(const std::string& input)
{
    if (input[index] == '|')
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

void BlockComment_Automaton::S2(const std::string& input)
{
    long unsigned int longIndex = index;
    if(longIndex >= input.size())
    {
//        Serr();
//        return;
        type= TokenType::UNDEFINED;
        return;
    }
    else if (input[index] == '|')
    {
        if(input[index] == '\n')
        {
            newLines++;
        }
        inputRead ++;
        index++;
        S3(input);
    }
    else if(input[index] != '|')
    {
        if(input[index] == '\n')
        {
            newLines++;
        }
        inputRead ++;
        index++;
        S2(input);
    }
    else
    {
        Serr();
    }
}
void BlockComment_Automaton::S3(const std::string& input)
{
    if (input[index] == '#')
    {
        inputRead++;
    }
    else
    {
        Serr();
    }
}