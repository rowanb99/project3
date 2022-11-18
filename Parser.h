#ifndef CS236_PROJECT_2_PARSER_H
#define CS236_PROJECT_2_PARSER_H

#include <vector>
#include "Token.h"
#include "DatalogProgram.h"

class Parser {
public:
    //Constructor
    explicit Parser(vector<struct Token *> tokensVector);

    //Destructor
    // TODO

    //Makes sure the given token has the correct tokenType
    bool MatchFunction(TokenType correctTokenType);

    //Deletes the first token in the tokensForParser vector
    //After the token is accepted by the grammar, the token is deleted
    void DeleteCurrentToken();

    //Helper function to Parser that does that actual parsing to the sanitized tokens
    void Parse();

    // Returns a datalog object of the whole function, or failure if it doesn't work
    DatalogProgram ParseDatalogProgram();

    // Checks for tokens that match a scheme grammar
    void ParseScheme();

    // Checks for tokens that match an idList grammar
    void ParseIdList();

    // Checks for tokens that match a schemeList grammar
    void ParseSchemeList();

    // Checks for tokens that match a factList grammar
    void ParseFactList();

    // Checks for tokens that match a fact grammar
    void ParseFact();

    // Checks for tokens that match a stringList grammar
    void ParseStringList();

    // Checks for tokens that match a ruleList grammar
    void ParseRuleList();

    // Checks for tokens that match a rule grammar
    void ParseRule();

    // Checks for tokens that match a headPredicate grammar
    void ParseHeadPredicate();

    // Checks for tokens that match a predicate grammar
    void ParsePredicate();

    // Checks for tokens that match a parameter grammar
    void ParseParameter();

    // Checks for tokens that match a predicateList grammar
    void ParsePredicateList();

    // Checks for tokens that match a parameterList grammar
    void ParseParameterList();

    // Checks for tokens that match a queries grammar
    void ParseQuery();

    // Checks for tokens that match a queryList grammar
    void ParseQueryList();

    //Sanitizes the token vector, removing all tokens that have tokenType of comment
    void RemoveCommentTokens(vector <Token*> &myVector);

    //Test function to print tokens to make sure sanitizing works properly
    void PrintParserTokens();

private:
    //The datalog produced after parsing
    DatalogProgram program;

    //Sanitized token vector
    vector<Token*> tokensForParser;

    //The concatenated Scheme,Fact,Rule,or Query string. (Becomes one line of parsed output)
    string line;
};


#endif //CS236_PROJECT_2_PARSER_H
