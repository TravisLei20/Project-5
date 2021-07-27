//
// Created by travi on 7/6/2021.
//

#ifndef PROJECT_2_PARSER_H
#define PROJECT_2_PARSER_H

#include <iostream>
#include <set>
#include <vector>
#include "Token.h"

#include "DatalogProgram.h"
#include "Predicate.h"
#include "Parameter.h"
#include "Rules.h"

using namespace std;

class Parser
{
public:
    Parser()
    {
        index = 0;
    }
    /*
    ~Parser()
    {
        for (unsigned int i = 0 ; i < tokens.size() ; i++)
        {
            delete[] tokens.at(i);
        }
    }
    */
    void setTokens(vector<Token*> tokens)
    {
        this -> tokens = tokens;
    }

    void parse();

    void datalogProgram();

    void schemeList();
    void factList();
    void ruleList();
    void queryList();

    void scheme();
    void fact();
    void rule();
    void query();

    void headPredicate();
    Predicate predicate();

    void predicateList();
    void parameterList();
    void stringList();
    void idList();
    void parameter();

    DatalogProgram getDatalogProgram()
    {
        return datalogProgram1;
    }


private:
    vector<Token*> tokens;
    unsigned int index;
    vector<Parameter> vectorOfParameters;
    DatalogProgram datalogProgram1;
    Predicate nameOfHeadPredicate;
    Rules rules;
    set<string> setDomain;
};

#endif //PROJECT_2_PARSER_H
