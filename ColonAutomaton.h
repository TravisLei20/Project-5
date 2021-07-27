//
// Created by travi on 6/29/2021.
//

#ifndef PROJECT_1_COLONAUTOMATON_H
#define PROJECT_1_COLONAUTOMATON_H


#include "Automaton.h"

using namespace std;

class ColonAutomaton : public Automaton
{
public:
    ColonAutomaton() : Automaton(TokenType::COLON) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //PROJECT_1_COLONAUTOMATON_H
