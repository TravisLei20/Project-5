//
// Created by travi on 6/28/2021.
//

#ifndef PROJECT_1_LEXER_H
#define PROJECT_1_LEXER_H
#include <vector>
#include <iostream>
#include <cctype>

#include "Automaton.h"
#include "MatcherAutomaton.h"
#include "Token.h"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"
#include "IDAutomaton.h"
#include "StringAutomaton.h"
#include "CommentAutomaton.h"
#include "BadStringAutomaton.h"
#include "BadBlockCommentAutomaton.h"

using namespace std;

class Lexer
{
private:
    vector<Automaton*> automata;
    vector<Token*> tokens;

    void CreateAutomata();

    // TODO: add any other private methods here (if needed)

public:
    Lexer();
    ~Lexer();

    void Run(string& input);

    // TODO: add other public methods here

    void toString();

    vector<Token*> getToken();
};



#endif //PROJECT_1_LEXER_H
