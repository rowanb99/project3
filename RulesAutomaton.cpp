
#include "RulesAutomaton.h"

void RulesAutomaton::S0(const std::string& input) {
    if (input[index] == 'R') {
        inputRead++;
        index++;
        u1(input);
    }
    else {
        Serr();
    }
}

void RulesAutomaton::u1(const std::string& input) {
    if (input[index] == 'u') {
        inputRead++;
        index++;
        l2(input);
    }
    else {
        Serr();
    }
}
void RulesAutomaton::l2(const std::string& input) {
    if (input[index] == 'l') {
        inputRead++;
        index++;
        e3(input);
    }
    else {
        Serr();
    }
}
void RulesAutomaton::e3(const std::string& input) {
    if (input[index] == 'e') {
        inputRead++;
        index++;
        s4(input);
    }
    else {
        Serr();
    }
}
void RulesAutomaton::s4(const std::string& input) {
    if (input[index] == 's' && !isalpha(input[index+1])) {
        inputRead++;
    }
    else {
        Serr();
    }
}


