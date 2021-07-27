//
// Created by travi on 7/7/2021.
//

#ifndef PROJECT_2_PARAMETER_H
#define PROJECT_2_PARAMETER_H

#include <string>

using namespace std;

class Parameter {
private:
    string parameter;
public:
    Parameter(){}
    Parameter(string param)
    {
        parameter = param;
    }

    bool isConstant()
    {
        if (parameter.at(0) == '\'')
        {
            return true;
        }
        else {return false;}
    }

    string toString()
    {
        return parameter;
    }
};


#endif //PROJECT_2_PARAMETER_H
