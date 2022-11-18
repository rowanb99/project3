//
// Created by vj234 on 9/20/22.
//

#include "PeriodAutomaton.h"
void PeriodAutomaton::S0(const std::string& input) {
    if (input[index] == '.')
    {
        inputRead = 1;
    }
    else
    {
        Serr();
    }
}