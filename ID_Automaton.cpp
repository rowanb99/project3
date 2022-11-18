
#include "ID_Automaton.h"

void ID_Automaton::S0(const std::string& input) {
    if (isalpha(input[index])) {
//        inputRead ++;
//        index++;
        S1(input);
    }
    else {
        Serr();
    }
}
void ID_Automaton::S1(const std::string& input)
{
    long unsigned int longIndex = index;

    if(longIndex < input.size())
    {
        if (isalpha(input[index]) || isdigit(input[index]) || input[index] == '_') {
            inputRead++;
            index++;
            S1(input);
        }

    }
}

bool ID_Automaton::isNotOtherToken(string input, int index)
{
    string queriesCheck = input.substr(index, 7);
    string rulesCheck = input.substr(index, 5);
    string factsCheck = input.substr(index, 5);
    string schemesCheck = input.substr(index, 7);
    if(queriesCheck == "Queries")
    {
        return false;
    }
    else if(rulesCheck == "Rules")
    {
        return false;
    }
    else if(factsCheck == "Facts")
    {
        return false;
    }
    else if(schemesCheck == "Schemes")
    {
        return false;
    }
    else
    {
        return true;
    }
}
