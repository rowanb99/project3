#include "Parser.h"
#include "DatalogProgram.h"
#include <utility>


Parser::Parser(vector<struct Token *> lexerTokens) {
    tokensForParser = std::move(lexerTokens);
    RemoveCommentTokens(tokensForParser);
    Parse();
}


void Parser::Parse() {
    try {
        ParseDatalogProgram();
        program.PrintDatalog();
    }
    catch (Token *wrongToken) {
        cout << "Failure!" << endl;
        cout << "  " << wrongToken->toString() << endl;
        return;
    }
}


DatalogProgram Parser::ParseDatalogProgram() {

    //Checks that first token is scheme token. If not, throws exception
    if (MatchFunction(TokenType::SCHEMES))
        DeleteCurrentToken();
    else
        throw tokensForParser[0];

    //Checks that next token is colon token. If not, throws exception
    if (MatchFunction(TokenType::COLON))
        DeleteCurrentToken();
    else
        throw tokensForParser[0];

    //Checks for tokens that match a scheme grammar. (If no such grammar, throws exception)
    ParseScheme();

    //Checks for tokens that match a schemeList grammar. (If no such grammar, throws exception)
    ParseSchemeList();

    //Checks that next token is fact token. If not, throws exception
    if (MatchFunction(TokenType::FACTS))
        DeleteCurrentToken();
    else
        throw tokensForParser[0];

    //Checks that next token is colon token. If not, throws exception
    if (MatchFunction(TokenType::COLON))
        DeleteCurrentToken();
    else
        throw tokensForParser[0];

    //Checks for tokens that match a factList grammar. (If no such grammar, throws exception)
    ParseFactList();

    //Checks that next token is rules token. If not, throws exception
    if (MatchFunction(TokenType::RULES))
        DeleteCurrentToken();
    else
        throw tokensForParser[0];

    //Checks that next token is colon token. If not, throws exception
    if (MatchFunction(TokenType::COLON))
        DeleteCurrentToken();
    else
        throw tokensForParser[0];

    //Checks for tokens that match a ruleList grammar. (If no such grammar, throws exception)
    ParseRuleList();

    //Checks that next token is query token. If not, throws exception
    if (MatchFunction(TokenType::QUERIES))
        DeleteCurrentToken();
    else
        throw tokensForParser[0];

    //Checks that next token is colon token. If not, throws exception
    if (MatchFunction(TokenType::COLON))
        DeleteCurrentToken();
    else
        throw tokensForParser[0];

    //Checks for tokens that match a queries grammar. (If no such grammar, throws exception)
    ParseQuery();

    //Checks for tokens that match a queryList grammar. (If no such grammar, throws exception)
    ParseQueryList();

    //Checks that next token is EndOfFile token. If not, throws exception
    if (MatchFunction(TokenType::EOF_TOKEN))
        DeleteCurrentToken();
    else
        throw tokensForParser[0];

    //Returns the parser member datalog object
    return program;
}


void Parser::ParseScheme() {
    line = "";

    //Checks that next token is ID token. If not, throws exception
    if (MatchFunction(TokenType::ID)) {
        line += tokensForParser[0]->getDescription();
        DeleteCurrentToken();
    } else
        throw tokensForParser[0];

    //Checks that next token is LeftParen token. If not, throws exception
    if (MatchFunction(TokenType::LEFT_PAREN)) {
        line += tokensForParser[0]->getDescription();
        DeleteCurrentToken();
    } else
        throw tokensForParser[0];

    //Checks that next token is ID token. If not, throws exception
    if (MatchFunction(TokenType::ID)) {
        line += tokensForParser[0]->getDescription();
        DeleteCurrentToken();
    } else
        throw tokensForParser[0];

    //Checks for tokens that match an IdList grammar. (If no such grammar, throws exception)
    ParseIdList();

    //Checks that next token is RightParen token. If not, throws exception
    if (MatchFunction(TokenType::RIGHT_PAREN)) {
        line += tokensForParser[0]->getDescription();
        DeleteCurrentToken();
    } else
        throw tokensForParser[0];

    //Appends line to schemeVector
    program.schemesVector.push_back(line);
}


void Parser::ParseIdList() {
    // Base Case: Checks for lambda
    if (MatchFunction(TokenType::RIGHT_PAREN)) {
        return;
    }

    //Checks that next token is Comma token. If not, throws exception
    if (MatchFunction(TokenType::COMMA)) {
        line += tokensForParser[0]->getDescription();
        DeleteCurrentToken();
    } else
        throw tokensForParser[0];

    //Checks that next token is ID token. If not, throws exception
    if (MatchFunction(TokenType::ID)) {
        line += tokensForParser[0]->getDescription();
        DeleteCurrentToken();
    } else
        throw tokensForParser[0];

    //Checks for tokens that match another IdList grammar. (If no such grammar, throws exception)
    ParseIdList();

}


void Parser::ParseSchemeList() {
    // Base Case: Checks for lambda
    if (MatchFunction(TokenType::FACTS)) {
        return;
    }

    //Checks for tokens that match a scheme grammar. (If no such grammar, throws exception)
    ParseScheme();

    //Checks for tokens that match a schemeList grammar. (If no such grammar, throws exception)
    ParseSchemeList();
}


void Parser::ParseFactList() {
    // Base Case: Checks for lambda
    if (MatchFunction(TokenType::RULES)) {
        return;
    }

    // Checks for tokens that match a Fact grammar. (If no such grammar, throws exception)
    ParseFact();

    // Checks for tokens that match another factList grammar. (If no such grammar, throws exception)
    ParseFactList();
}


void Parser::ParseFact() {
    //Resets the line
    line = "";

    //Checks that next token is ID token. If not, throws exception
    if (MatchFunction(TokenType::ID)) {
        line += tokensForParser[0]->getDescription();
        DeleteCurrentToken();
    } else
        throw tokensForParser[0];

    //Checks that next token is leftParen token. If not, throws exception
    if (MatchFunction(TokenType::LEFT_PAREN)) {
        line += tokensForParser[0]->getDescription();
        DeleteCurrentToken();
    } else
        throw tokensForParser[0];

    //Checks that next token is String token. If not, throws exception
    if (MatchFunction(TokenType::STRING)) {
        line += tokensForParser[0]->getDescription();
        program.domainVector.push_back(tokensForParser[0]->getDescription());
        DeleteCurrentToken();
    } else
        throw tokensForParser[0];

    // Checks for tokens that match a stringList grammar. (If no such grammar, throws exception)
    ParseStringList();

    //Checks that next token is rightParen token. If not, throws exception
    if (MatchFunction(TokenType::RIGHT_PAREN)) {
        line += tokensForParser[0]->getDescription();
        DeleteCurrentToken();
    } else
        throw tokensForParser[0];

    //Checks that next token is period token. If not, throws exception
    if (MatchFunction(TokenType::PERIOD)) {
        line += tokensForParser[0]->getDescription();
        DeleteCurrentToken();
    } else
        throw tokensForParser[0];

    //Appends line to factsVector
    program.factsVector.push_back(line);
}


void Parser::ParseStringList() {
    // Base Case: Checks for lambda
    if (MatchFunction(TokenType::RIGHT_PAREN)) {
        return;
    }

    //Checks that next token is comma token. If not, throws exception
    if (MatchFunction(TokenType::COMMA)) {
        line += tokensForParser[0]->getDescription();
        DeleteCurrentToken();
    } else
        throw tokensForParser[0];

    //Checks that next token is string token. If not, throws exception
    if (MatchFunction(TokenType::STRING)) {
        line += tokensForParser[0]->getDescription();
        program.domainVector.push_back(tokensForParser[0]->getDescription());
        DeleteCurrentToken();
    } else
        throw tokensForParser[0];

    // Checks for tokens that match a stringList grammar. (If no such grammar, throws exception)
    ParseStringList();
}


void Parser::ParseRuleList() {
    // Base Case: Checks for lambda
    if (MatchFunction(TokenType::QUERIES)) {
        return;
    }

    // Checks for tokens that match a rule grammar. (If no such grammar, throws exception)
    ParseRule();

    // Checks for tokens that match a ruleList grammar. (If no such grammar, throws exception)
    ParseRuleList();
}


void Parser::ParseRule() {
    //Resets the line
    line = "";

    // Checks for tokens that match a headPredicate grammar. (If no such grammar, throws exception)
    ParseHeadPredicate();

    //Checks that next token is colonDash token. If not, throws exception
    if (MatchFunction(TokenType::COLON_DASH)) {
        line += tokensForParser[0]->getDescription();
        DeleteCurrentToken();
    } else
        throw tokensForParser[0];

    // Checks for tokens that match a predicate grammar. (If no such grammar, throws exception)
    ParsePredicate();

    // Checks for tokens that match a predicateList grammar. (If no such grammar, throws exception)
    ParsePredicateList();

    //Checks that next token is period token. If not, throws exception
    if (MatchFunction(TokenType::PERIOD)) {
        line += tokensForParser[0]->getDescription();
        DeleteCurrentToken();
    } else
        throw tokensForParser[0];

    //Appends line to rulesVector
    program.rulesVector.push_back(line);
}


void Parser::ParseHeadPredicate() {
    //Checks that next token is ID token. If not, throws exception
    if (MatchFunction(TokenType::ID)) {
        line += tokensForParser[0]->getDescription();
        DeleteCurrentToken();
    } else
        throw tokensForParser[0];

    //Checks that next token is leftParen token. If not, throws exception
    if (MatchFunction(TokenType::LEFT_PAREN)) {
        line += tokensForParser[0]->getDescription();
        DeleteCurrentToken();
    } else
        throw tokensForParser[0];

    //Checks that next token is ID token. If not, throws exception
    if (MatchFunction(TokenType::ID)) {
        line += tokensForParser[0]->getDescription();
        DeleteCurrentToken();
    } else
        throw tokensForParser[0];

    // Checks for tokens that match an idList grammar. (If no such grammar, throws exception)
    ParseIdList();

    //Checks that next token is RightParen token. If not, throws exception
    if (MatchFunction(TokenType::RIGHT_PAREN)) {
        line += tokensForParser[0]->getDescription();
        DeleteCurrentToken();
    } else
        throw tokensForParser[0];
}


void Parser::ParsePredicate() {
    //Checks that next token is ID token. If not, throws exception
    if (MatchFunction(TokenType::ID)) {
        line += tokensForParser[0]->getDescription();
        DeleteCurrentToken();
    } else
        throw tokensForParser[0];

    //Checks that next token is LeftParen token. If not, throws exception
    if (MatchFunction(TokenType::LEFT_PAREN)) {
        line += tokensForParser[0]->getDescription();
        DeleteCurrentToken();
    } else
        throw tokensForParser[0];

    // Checks for tokens that match a parameter grammar. (If no such grammar, throws exception)
    ParseParameter();

    // Checks for tokens that match a parameterList grammar. (If no such grammar, throws exception)
    ParseParameterList();

    //Checks that next token is RightParen token. If not, throws exception
    if (MatchFunction(TokenType::RIGHT_PAREN)) {
        line += tokensForParser[0]->getDescription();
        DeleteCurrentToken();
    } else
        throw tokensForParser[0];
}


void Parser::ParseParameter() {
    //Checks that next token is string OR ID token. If not, throws exception
    if ((MatchFunction(TokenType::STRING)) | (MatchFunction(TokenType::ID))) {
        line += tokensForParser[0]->getDescription();
        DeleteCurrentToken();
    } else
        throw tokensForParser[0];
}


void Parser::ParsePredicateList() {
    // Base Case: Checks for lambda
    if (MatchFunction(TokenType::PERIOD)) {
        return;
    }

    //Checks that next token is comma token. If not, throws exception
    if (MatchFunction(TokenType::COMMA)) {
        line += tokensForParser[0]->getDescription();
        DeleteCurrentToken();
    } else
        throw tokensForParser[0];

    // Checks for tokens that match a predicate grammar. (If no such grammar, throws exception)
    ParsePredicate();

    // Checks for tokens that match a predicateList grammar. (If no such grammar, throws exception)
    ParsePredicateList();
}


void Parser::ParseParameterList() {
    // Base Case: Checks for lambda
    if (MatchFunction(TokenType::RIGHT_PAREN)) {
        return;
    }

    //Checks that next token is comma token. If not, throws exception
    if (MatchFunction(TokenType::COMMA)) {
        line += tokensForParser[0]->getDescription();
        DeleteCurrentToken();
    } else
        throw tokensForParser[0];

    // Checks for tokens that match a parameter grammar. (If no such grammar, throws exception)
    ParseParameter();

    // Checks for tokens that match a parameterList grammar. (If no such grammar, throws exception)
    ParseParameterList();
}


void Parser::ParseQuery() {
    //Resets line
    line = "";

    // Checks for tokens that match a predicate grammar. (If no such grammar, throws exception)
    ParsePredicate();

    //Checks that next token is Q-Mark token. If not, throws exception
    if (MatchFunction(TokenType::Q_MARK)) {
        line += tokensForParser[0]->getDescription();
        DeleteCurrentToken();
    } else
        throw tokensForParser[0];

    //Appends line to queriesVector
    program.queriesVector.push_back(line);
}


void Parser::ParseQueryList() {
    // Base Case: Checks for lambda
    if (MatchFunction(TokenType::EOF_TOKEN)) {
        return;
    }

    // Checks for tokens that match a query grammar. (If no such grammar, throws exception)
    ParseQuery();

    // Checks for tokens that match a queryList grammar. (If no such grammar, throws exception)
    ParseQueryList();
}


bool Parser::MatchFunction(TokenType correctTokenType) {
    Token *currentToken = tokensForParser[0];
    if (correctTokenType == currentToken->getType()) {
        return true;
    } else {
        return false;
    }
}


void Parser::DeleteCurrentToken() {
    tokensForParser.erase(tokensForParser.begin());
}


void Parser::RemoveCommentTokens(vector<Token *> &myVector) {
    for (int i = myVector.size() - 1; i >= 0; i--) {
        Token *token = myVector[i];
        if (token->getType() == TokenType::COMMENT) {
            myVector.erase(myVector.begin() + i);
        }
    }
}


void Parser::PrintParserTokens() {
    for (auto tokenInVector: tokensForParser) {
        cout << tokenInVector->Token::toString() << endl;
    }
    cout << "Total Tokens = " << tokensForParser.size();
}