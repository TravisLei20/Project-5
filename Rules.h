//
// Created by travi on 7/7/2021.
//

#ifndef PROJECT_2_RULES_H
#define PROJECT_2_RULES_H

#include <vector>

#include "Predicate.h"

using namespace std;

class Rules {
private:
    Predicate headPredicate;
    vector<Predicate> predicateList;

public:
    Rules(){}

    void clearVector()
    {
        predicateList.clear();
    }

    Predicate getHeadPredicate()
    {
        return headPredicate;
    }

    vector<Predicate> getPredicateList()
    {
        return predicateList;
    }

    unsigned int getPredicateListSize()
    {
        return predicateList.size();
    }

    void setHeadPredicate(Predicate head)
    {
        headPredicate = head;
    }

    void pushbackPredicate(Predicate predi)
    {
        predicateList.push_back(predi);
    }

    string toString()
    {
        stringstream ss;
        ss << headPredicate.toString() << " :- ";
        for (unsigned int i = 0 ; i < predicateList.size() ; i++)
        {
            if (i == predicateList.size() - 1)
            {
                ss << predicateList.at(i).toString() << ".";
            }
            else
            {
                ss << predicateList.at(i).toString() << ",";
            }
        }
        return ss.str();
    }

};


#endif //PROJECT_2_RULES_H
