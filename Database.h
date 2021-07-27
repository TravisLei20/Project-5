//
// Created by travi on 7/14/2021.
//

#ifndef PROJECT_3_DATABASE_H
#define PROJECT_3_DATABASE_H

#include <map>
#include <string>

#include "Relation.h"

using namespace std;

class Database
{
private:
    map<string, Relation> data;

public:
    Database(){}

    map<string, Relation> getData()
    {
        return data;
    }

    void insert(string giveName , Relation relation)
    {
        data.insert(pair<string, Relation>(giveName,relation));
    }

    Relation& getRelation(string givenName)
    {
        return data.at(givenName);
    }

    void addTuple(string name , Tuple givenTuple)
    {
        data.at(name).addTuples(givenTuple);
    }

    unsigned int count()
    {
        unsigned int num = 0;

        for (map<string, Relation>::iterator it = data.begin() ; it != data.end() ; it++)
        {
            num += it->second.getTuples().size();
        }

        return num;
    }

};

#endif //PROJECT_3_DATABASE_H
