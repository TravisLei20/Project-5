//
// Created by travi on 6/29/2021.
//

#ifndef PROJECT_1_COLONDASHAUTOMATON_H
#define PROJECT_1_COLONDASHAUTOMATON_H


#include "Automaton.h"

class ColonDashAutomaton : public Automaton
{
private:
    void S1(const std::string& input);

public:
    ColonDashAutomaton() : Automaton(TokenType::COLON_DASH) {}  // Call the base constructor

    void S0(const string& input);
};

#endif //PROJECT_1_COLONDASHAUTOMATON_H
