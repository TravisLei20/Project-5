//
// Created by travi on 7/14/2021.
//

#ifndef PROJECT_3_TUPLE_H
#define PROJECT_3_TUPLE_H

#include <vector>
#include <string>

using namespace std;

class Tuple
{
private:
    vector<string> tuple;

public:
    Tuple(){}

    void setTuple(vector<string> givenTuple)
    {
        tuple = givenTuple;
    }

    void push_back(string givenString)
    {
        tuple.push_back(givenString);
    }

    vector<string> getTuples()
    {
        return tuple;
    }

    string at(unsigned int index)
    {
        return tuple.at(index);
    }

    bool operator< (const Tuple& other) const
    {
        return this->tuple < other.tuple;
    }

};

#endif //PROJECT_3_TUPLE_H
