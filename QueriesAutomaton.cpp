
#include "QueriesAutomaton.h"
void QueriesAutomaton::S0(const std::string& input) {
    if (input[index] == 'Q') {
        inputRead++;
        index++;
        u1(input);
    }
    else {
        Serr();
    }
}
void QueriesAutomaton::u1(const std::string& input) {
    if (input[index] == 'u') {
        inputRead++;
        index++;
        e2(input);
    }
    else {
        Serr();
    }
}
void QueriesAutomaton::e2(const std::string& input) {
    if (input[index] == 'e') {
        inputRead++;
        index++;
        r3(input);
    }
    else {
        Serr();
    }
}
void QueriesAutomaton::r3(const std::string& input) {
    if (input[index] == 'r') {
        inputRead++;
        index++;
        i4(input);
    }
    else {
        Serr();
    }
}
void QueriesAutomaton::i4(const std::string& input) {
    if (input[index] == 'i') {
        inputRead++;
        index++;
        e5(input);
    }
    else {
        Serr();
    }
}
void QueriesAutomaton::e5(const std::string& input) {
    if (input[index] == 'e') {
        inputRead++;
        index++;
        s6(input);
    }
    else {
        Serr();
    }
}
void QueriesAutomaton::s6(const std::string& input) {
    if (input[index] == 's'&& !isalpha(input[index+1])) {
        inputRead++;
    }
    else {
        Serr();
    }
}