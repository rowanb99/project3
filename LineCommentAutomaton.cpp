
#include "LineCommentAutomaton.h"
void LineCommentAutomaton::S0(const std::string& input)
{
    if (input[index] == '#') {
//        inputRead ++;
//        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void LineCommentAutomaton::S1(const std::string& input)
{

    if((input[index] == EOF || input[index] == '\n') && input[index] != '|' )
    {
        S2(input);
    }
    else if((input[index] != EOF || input[index] != '\n')) //&& input[index] != '|'
    {
        inputRead ++;
        index++;
        S1(input);
    }
    else if(input[index] == ' ')
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

void LineCommentAutomaton::S2(const std::string& input)
{
    if(input[index] == EOF || input[index] == '\n')
    {
  //      inputRead++;
    }
    else
    {
        Serr();
    }
}