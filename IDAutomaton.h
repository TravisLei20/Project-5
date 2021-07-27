//
// Created by travi on 6/30/2021.
//

#ifndef PROJECT_1_IDAUTOMATON_H
#define PROJECT_1_IDAUTOMATON_H

#include "Automaton.h"


using namespace std;

class IDAutomaton : public Automaton
{
public:
    IDAutomaton() : Automaton(TokenType::ID) {}  // Call the base constructor

    void S0(const string& input)
    {
        if(isalpha(input.at(index)))
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
        if (index != input.size())
        {
            if(isalpha(input.at(index)) || isdigit(input.at(index)))
            {
                index++;
                inputRead++;
                S1(input);
            }
            else
            {
                return;
            }
        }

        else {return;}
    }


};

#endif //PROJECT_1_IDAUTOMATON_H
