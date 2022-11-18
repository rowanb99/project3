#ifndef TOKEN_H
#define TOKEN_H
#include <string>
using namespace std;

enum class TokenType {
    COLON,
    COLON_DASH,
    COMMA,
    PERIOD,
    Q_MARK,
    LEFT_PAREN,
    RIGHT_PAREN,
    MULTIPLY,
    ADD,
    SCHEMES,
    FACTS,
    RULES,
    QUERIES,
    ID,
    STRING,
    COMMENT,
    EOF_TOKEN,
    UNDEFINED
};

class Token
{
private:
    // Information needed by Token
    TokenType tokenType;
    string tokenDescription;
    int tokenLine;

public:
    Token(TokenType type, std::string description, int line);
    string toString();
    TokenType getType();
    string getDescription();
    int getLine();
    string stringifyToken(TokenType);
    
    // TODO: add other needed methods
};

#endif // TOKEN_H

