//
// Created by travi on 7/7/2021.
//

#ifndef PROJECT_2_PREDICATE_H
#define PROJECT_2_PREDICATE_H

#include <string>
#include <vector>

#include <iostream>
#include <sstream>

#include "Parameter.h"

using namespace std;

class Predicate {
private:
    string ID;
    vector<Parameter> parameters;
public:
    Predicate() {}

    Predicate(string predi, vector<Parameter> param)
    {
        ID = predi;
        parameters = param;
    }

    void setID(string headPredi)
    {
        ID = headPredi;
    }

    void setParameter(vector<Parameter> para)
    {
        parameters = para;
    }

    unsigned int getSize()
    {
        return parameters.size();
    }

    vector<Parameter> getParameters()
    {
        return parameters;
    }

    string getParameterString(unsigned int j)
    {
        return parameters.at(j).toString();
    }

    vector<string> getVectorOfStrings()
    {
        vector<string> myVector;
        for (unsigned int i = 0 ; i < parameters.size() ; i++)
        {
            myVector.push_back(parameters.at(i).toString());
        }
        return myVector;
    }

    string getID()
    {
        return ID;
    }

    string toString()
    {
        stringstream ss;
        ss << ID << "(";
        for (unsigned int i = 0; i < parameters.size(); i++)
        {
            if (i == parameters.size() - 1)
            {
                ss << parameters.at(i).toString();
            }
            else
            {
                ss << parameters.at(i).toString() << ",";
            }
        }
        ss << ")";

        return ss.str();
    }
};


#endif //PROJECT_2_PREDICATE_H
