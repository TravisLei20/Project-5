//
// Created by travi on 6/28/2021.
//


#include "Lexer.h"

using namespace std;

Lexer::Lexer()
{
    CreateAutomata();
}

Lexer::~Lexer()
{
    for (unsigned int i = 0 ; i < automata.size() ; i++)
    {
        delete[] automata.at(i);
    }

    for (unsigned int i = 0 ; i < tokens.size() ; i++)
    {
        delete tokens.at(i);
    }
}

void Lexer::CreateAutomata()
{
    automata.push_back(new ColonAutomaton());
    automata.push_back(new ColonDashAutomaton());
    automata.push_back(new MatcherAutomaton("," , TokenType::COMMA));
    automata.push_back(new MatcherAutomaton("." , TokenType::PERIOD));
    automata.push_back(new MatcherAutomaton("?" , TokenType::Q_MARK));
    automata.push_back(new MatcherAutomaton("(" , TokenType::LEFT_PAREN));
    automata.push_back(new MatcherAutomaton(")" , TokenType::RIGHT_PAREN));
    automata.push_back(new MatcherAutomaton("*" , TokenType::MULTIPLY));
    automata.push_back(new MatcherAutomaton("+" , TokenType::ADD));
    automata.push_back(new MatcherAutomaton("Schemes" , TokenType::SCHEMES));
    automata.push_back(new MatcherAutomaton("Facts" , TokenType::FACTS));
    automata.push_back(new MatcherAutomaton("Rules" , TokenType::RULES));
    automata.push_back(new MatcherAutomaton("Queries" , TokenType::QUERIES));
    automata.push_back(new IDAutomaton());
    automata.push_back(new StringAutomaton());
    automata.push_back(new CommentAutomaton());
    automata.push_back(new BadStringAutomaton());
    automata.push_back(new BadBlockCommentAutomaton());

    // TODO: Add the other needed automata here
    //EOF
    //Undefined
    //total tokens

}

void Lexer::Run(string& input)
{
    // TODO: convert this pseudo-code with the algorithm into actual C++ code
    unsigned int lineNumber = 1;
    // While there are more characters to tokenize
    while (input.size() > 0)
    {
        unsigned int maxRead = 0;
        //set maxAutomaton to the first automaton in automata
        Automaton* maxAutomaton;
        maxAutomaton = automata.at(0);

        // TODO: you need to handle whitespace inbetween tokens

        while (input.size() >= 1 && isspace(input.at(0)))
        {
            if (input.at(0) == '\n')
            {
                lineNumber++;
            }
            input.erase(0 ,1);
        }

        if (input.size() == 0){break;}



        // Here is the "Parallel" part of the algorithm
        //   Each automaton runs with the same input
        //foreach automaton in automata

        for (unsigned int i = 0 ; i < automata.size() ; i++)
        {
            unsigned int inputRead = automata.at(i) -> Start(input);

            if (inputRead > maxRead)
            {
                maxRead = inputRead;
                maxAutomaton = automata.at(i);
            }
        }
        // Here is the "Max" part of the algorithm
        Token* newToken;
        if (maxRead > 0)
        {
            newToken = maxAutomaton -> CreateToken(input.substr(0,maxRead),lineNumber);
            lineNumber += maxAutomaton -> NewLinesRead();
            if (newToken->getTokenType() != TokenType::COMMENT)
            {
                tokens.push_back(newToken);
            }
        }

        // No automaton accepted input
        // Create single character undefined token

        else
        {
            maxRead = 1;
            tokens.push_back(new Token(TokenType::UNDEFINED , input.substr(0,1),lineNumber));
        }
        input = input.substr(maxRead);
        //input.erase(0 , maxRead);
    }
    tokens.push_back(new Token(TokenType::EOF_TYPE , "" , lineNumber));
}

vector<Token*> Lexer::getToken()
{
    return tokens;
}

void Lexer::toString()
{
    for(unsigned int i = 0 ; i < tokens.size() ; i++)
    {
        cout << tokens.at(i) -> toString() << endl;
    }
    cout << "Total Tokens = " << tokens.size();
}