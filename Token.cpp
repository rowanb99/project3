#include "Token.h"
#include <iostream>
using namespace std;

Token::Token(TokenType type, string description, int line) {
    // Initialize all member variables
    tokenType = type;
    tokenDescription = description;
    tokenLine = line;
}
string Token::toString() {
    string returnString;
    //cout << "(" << stringifyToken(this->tokenType) << ",\"" << this->tokenDescription << "\"," << this->tokenLine << ")" << endl;
    string lineNum = to_string(this->tokenLine);
    returnString = "(" + stringifyToken(this->tokenType) + ",\"" + this->tokenDescription + "\"," + lineNum + ")";
    return returnString;
}
TokenType Token::getType() {
    return tokenType;
}
string Token::getDescription() {
    return tokenDescription;
}
int Token::getLine() {
    return tokenLine;
}

string Token::stringifyToken(TokenType type) {
    switch(type) {
        case TokenType::COLON: return "COLON";
        case TokenType::COLON_DASH: return "COLON_DASH";
        case TokenType::COMMA: return "COMMA";
        case TokenType::PERIOD: return "PERIOD";
        case TokenType::Q_MARK: return "Q_MARK";
        case TokenType::LEFT_PAREN: return "LEFT_PAREN";
        case TokenType::RIGHT_PAREN: return "RIGHT_PAREN";
        case TokenType::MULTIPLY: return "MULTIPLY";
        case TokenType::ADD: return "ADD";
        case TokenType::SCHEMES: return "SCHEMES";
        case TokenType::FACTS: return "FACTS";
        case TokenType::RULES: return "RULES";
        case TokenType::QUERIES: return "QUERIES";
        case TokenType::ID: return "ID";
        case TokenType::STRING: return "STRING";
        case TokenType::COMMENT: return "COMMENT";
        case TokenType::EOF_TOKEN: return "EOF";            //Changed this to "EOF" so hopefully that fixes it...
        case TokenType::UNDEFINED: return "UNDEFINED";

    } return "INVALID";
}