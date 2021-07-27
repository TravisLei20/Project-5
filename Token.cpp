//
// Created by travi on 6/28/2021.
//
#include <sstream>
#include "Token.h"

Token::Token(TokenType type, string description, unsigned int line)
{
    tokenType = type;
    currentLine = line;
    descriptionOfItem = description;
}

string Token::getString()
{
    return descriptionOfItem;
}

string Token::typeToString(TokenType type)
{
    switch (type)
    {
        case COMMA: return "COMMA";
        case PERIOD: return "PERIOD";
        case Q_MARK: return "Q_MARK";
        case LEFT_PAREN: return "LEFT_PAREN";
        case RIGHT_PAREN: return "RIGHT_PAREN";
        case COLON: return "COLON";
        case COLON_DASH: return "COLON_DASH";
        case MULTIPLY: return "MULTIPLY";
        case ADD: return "ADD";
        case SCHEMES: return "SCHEMES";
        case FACTS: return "FACTS";
        case RULES: return "RULES";
        case QUERIES: return "QUERIES";
        case ID: return "ID";
        case STRING: return "STRING";
        case COMMENT: return "COMMENT";
        case UNDEFINED: return "UNDEFINED";
        case EOF_TYPE: return "EOF";
        default: return "ERROR";
    }
}

string Token::toString()
{
    stringstream out;
    out << "(" << typeToString(tokenType) << ",\"" << descriptionOfItem << "\"," << to_string(currentLine) << ")";
    return out.str();
}

TokenType Token::getTokenType()
{
    return tokenType;
}
