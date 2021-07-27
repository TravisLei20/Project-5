//
// Created by travi on 7/7/2021.
//

#ifndef PROJECT_2_DATALOGPROGRAM_H
#define PROJECT_2_DATALOGPROGRAM_H

#include <vector>
#include <sstream>
#include <set>
#include "Predicate.h"
#include "Parameter.h"
#include "Rules.h"

using namespace std;


class DatalogProgram {
private:
    vector<Predicate> schemes;
    vector<Predicate> facts;
    vector<Rules> rules;
    vector<Predicate> queries;
    set<string> domain;

public:
    vector<Predicate> getScheme()
    {
        return schemes;
    }

    vector<Predicate> getFacts()
    {
        return facts;
    }

    vector<Predicate> getQueries()
    {
        return queries;
    }

    vector<Rules> getRules()
    {
        return rules;
    }

    void setScheme(Predicate predicate)
    {
        schemes.push_back(predicate);
    }

    void setFacts(Predicate predicate)
    {
        facts.push_back(predicate);
    }

    void setQueries(Predicate predicate)
    {
        queries.push_back(predicate);
    }

    void setRule(Rules rules1)
    {
        rules.push_back(rules1);
    }

    void toString()
    {
        cout << "Schemes(" << to_string(schemes.size()) << "):" << endl;
        for (unsigned int i = 0 ; i < schemes.size() ; i++)
        {
            cout << "  " << schemes.at(i).toString() << endl;
        }

        cout << "Facts(" << to_string(facts.size()) << "):" << endl;
        for (unsigned int i = 0 ; i < facts.size() ; i++)
        {
            cout << "  " << facts.at(i).toString() << "." << endl;
            for (unsigned j = 0 ; j < facts.at(i).getSize() ; j++)
            {
                domain.insert(facts.at(i).getParameterString(j));
            }
        }

        cout << "Rules(" << to_string(rules.size()) << "):" << endl;
        for (unsigned int i = 0 ; i < rules.size() ; i++)
        {
            cout << "  " << rules.at(i).toString() << "." << endl;
        }

        cout << "Queries(" << to_string(queries.size()) << "):" << endl;
        for (unsigned int i = 0 ; i < queries.size() ; i++)
        {
            cout << "  " << queries.at(i).toString() << "?" << endl;
        }

        cout << "Domain(" << to_string(domain.size()) << "):" << endl;
        for (string s : domain)
        {
            cout << "  " << s << endl;
        }
    }

};


#endif //PROJECT_2_DATALOGPROGRAM_H
