//
// Created by travi on 7/1/2021.
//

#ifndef PROJECT_1_BADSTRINGAUTOMATON_H
#define PROJECT_1_BADSTRINGAUTOMATON_H

#include "Automaton.h"

using namespace std;

class BadStringAutomaton : public Automaton
{
public:
    BadStringAutomaton() : Automaton(TokenType::UNDEFINED) {}  // Call the base constructor

    void S0(const string& input)
    {
        if(input.at(index) == '\'')
        {
            index++;
            inputRead++;
            S1(input);
        }
        else
        {
            Serr();
        }
    }

    void S1(const string& input)
    {
        if (index == input.size())
        {
            return;
        }

        else if (input.at(index) == '\n')
        {
            newLines++;
            index++;
            inputRead++;
            S1(input);
        }

        else if (input.at(index) == '\'')
        {
            index++;
            inputRead++;
            S2(input);
        }

        else
        {
            index++;
            inputRead++;
            S1(input);
        }
    }

    void S2(const string& input)
    {
        if (index == input.size())
        {
            Serr();
        }


        else if(input.at(index) == '\'')
        {
            index++;
            inputRead++;
            S1(input);
        }

        else
        {
            Serr();
        }
    }
};

#endif //PROJECT_1_BADSTRINGAUTOMATON_H
