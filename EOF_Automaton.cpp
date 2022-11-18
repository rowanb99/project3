
#include "EOF_Automaton.h"
void EOF_Automaton::S0(const std::string& input) {
    if (input[index] == EOF) {
        inputRead = 1;
    }
    else {
        Serr();
    }
}