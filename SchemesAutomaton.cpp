

#include "SchemesAutomaton.h"
void SchemesAutomaton::S0(const std::string& input) {
    if (input[index] == 'S') {
        inputRead++;
        index++;
        c1(input);
    }
    else {
        Serr();
    }
}
void SchemesAutomaton::c1(const std::string& input) {
    if (input[index] == 'c') {
        inputRead++;
        index++;
        h2(input);
    }
    else {
        Serr();
    }
}
void SchemesAutomaton::h2(const std::string& input) {
    if (input[index] == 'h') {
        inputRead++;
        index++;
        e3(input);
    }
    else {
        Serr();
    }
}
void SchemesAutomaton::e3(const std::string& input) {
    if (input[index] == 'e') {
        inputRead++;
        index++;
        m4(input);
    }
    else {
        Serr();
    }
}
void SchemesAutomaton::m4(const std::string& input) {
    if (input[index] == 'm') {
        inputRead++;
        index++;
        e5(input);
    }
    else {
        Serr();
    }
}
void SchemesAutomaton::e5(const std::string& input) {
    if (input[index] == 'e') {
        inputRead++;
        index++;
        s6(input);
    }
    else {
        Serr();
    }
}
void SchemesAutomaton::s6(const std::string& input) {
    if (input[index] == 's'&& !isalpha(input[index+1])) {
        inputRead++;
    }
    else {
        Serr();
    }
}