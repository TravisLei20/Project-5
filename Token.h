//
// Created by travi on 6/28/2021.
//

#ifndef PROJECT_1_TOKEN_H
#define PROJECT_1_TOKEN_H

#include <string>

using namespace std;

enum TokenType
        {
            COMMA,
            PERIOD,
            Q_MARK,
            LEFT_PAREN,
            RIGHT_PAREN,
            COLON,
            COLON_DASH,
            MULTIPLY,
            ADD,
            SCHEMES,
            FACTS,
            RULES,
            QUERIES,
            ID,
            STRING,
            COMMENT,
            UNDEFINED,
            EOF_TYPE
        };

class Token
{
    private:
        // TODO: add member variables for information needed by Token
        TokenType tokenType;
        string descriptionOfItem;
        unsigned int currentLine;

    public:
        Token(TokenType type, string description, unsigned int line);
        string typeToString(TokenType type);
        string toString();

        TokenType getTokenType();

        string getString();

};

#endif //PROJECT_1_TOKEN_H
