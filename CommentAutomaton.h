//
// Created by travi on 6/30/2021.
//

#ifndef PROJECT_1_COMMENTAUTOMATON_H
#define PROJECT_1_COMMENTAUTOMATON_H

#include "Automaton.h"

using namespace std;

class CommentAutomaton : public Automaton
{
public:
    CommentAutomaton() : Automaton(TokenType::COMMENT) {}  // Call the base constructor

    void S0(const string& input)
    {
        if (input.at(index) == '#')
        {
            index++;
            inputRead++;
            if(input.at(index) == '|')
            {
                index++;
                inputRead++;
                S2(input);
            }
            else
            {
                S1(input);
            }
        }
        else
        {
            Serr();
        }
    }

    void S1(const string& input)
    {
        if (input.at(index) != '\n' && index < input.size())
        {
            index++;
            inputRead++;
            S1(input);
        }
        else
        {
            //inputRead--;
            return;
        }
    }

    void S2(const string& input)
    {
        if (index != input.size())
        {
            if (input.at(index) == '\n')
            {
                newLines++;
            }

            if (input.at(index) != '|')
            {
                index++;
                inputRead++;
                S2(input);
            }
            else if (input.at(index) == '|')
            {
                index++;
                inputRead++;
                S3(input);
            }
        }
        else {Serr();}
    }

    void S3(const string& input)
    {
        if (index != input.size())
        {
            if (input.at(index) == '|')
            {
                index++;
                inputRead++;
                S3(input);
            }

            else if (input.at(index) != '#')
            {
                if (input.at(index) == '\n')
                {
                    newLines++;
                }
                index++;
                inputRead++;
                S2(input);
            }

            else if (input.at(index) == '#')
            {
                //index++;
                inputRead++;
                return;
            }
        }
        else {Serr();}
    }
};

#endif //PROJECT_1_COMMENTAUTOMATON_H