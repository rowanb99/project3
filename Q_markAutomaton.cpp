//
// Created by vj234 on 9/21/22.
//

#include "Q_markAutomaton.h"

void Q_markAutomaton::S0(const std::string& input)
{
    if (input[index] == '?') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}