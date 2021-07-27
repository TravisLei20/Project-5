//
// Created by travi on 6/29/2021.
//

#include "MatcherAutomaton.h"

MatcherAutomaton::MatcherAutomaton(string toMatch, TokenType tokenType)
{
    this -> toMatch = toMatch;
    type = tokenType;
}

void MatcherAutomaton::S0(const string& input)
{
    bool isMatch = true;
    inputRead = 0; // member variable inherited from Automaton class
    for (int i = 0; i < (int)toMatch.size() && isMatch; i++)
    {
        if (input[i] != toMatch[i])
        {
            isMatch = false;
        }
    }
    if (isMatch)
    {
        inputRead = toMatch.size();
    }
    //return inputRead;
}