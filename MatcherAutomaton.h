//
// Created by travi on 6/29/2021.
//

#ifndef PROJECT_1_MATCHERAUTOMATON_H
#define PROJECT_1_MATCHERAUTOMATON_H

#include "Token.h"
#include "Automaton.h"

using namespace std;

class MatcherAutomaton : public Automaton
{
private:
    string toMatch;

public:
    MatcherAutomaton(string toMatch, TokenType tokenType);
    void S0(const string& input);
};



#endif //PROJECT_1_MATCHERAUTOMATON_H
