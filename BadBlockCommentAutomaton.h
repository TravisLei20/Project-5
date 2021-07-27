//
// Created by travi on 7/1/2021.
//

#ifndef PROJECT_1_BADBLOCKCOMMENTAUTOMATON_H
#define PROJECT_1_BADBLOCKCOMMENTAUTOMATON_H

#include "Automaton.h"

using namespace std;

class BadBlockCommentAutomaton : public Automaton {
public:
    BadBlockCommentAutomaton() : Automaton(TokenType::UNDEFINED) {}  // Call the base constructor

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
                S1(input);
            }
            else
            {
                Serr();
            }
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
            if (input.at(index) == '\n')
            {
                newLines++;
                index++;
                inputRead++;
                S1(input);
            }

            else if (input.at(index) != '|')
            {
                index++;
                inputRead++;
                S1(input);
            }
            else if (input.at(index) == '|')
            {
                index++;
                inputRead++;
                S3(input);
            }
        }
        else {return;}
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
                S1(input);
            }

            else if (input.at(index) == '#')
            {
                //index++;
                //inputRead++;
                Serr();
            }
        }
        else {Serr();}
    }
};

#endif //PROJECT_1_BADBLOCKCOMMENTAUTOMATON_H
