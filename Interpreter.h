//
// Created by travi on 7/14/2021.
//

#ifndef PROJECT_3_INTERPRETER_H
#define PROJECT_3_INTERPRETER_H


#include "Database.h"
#include "DatalogProgram.h"
#include "Header.h"
#include "Graph.h"

using namespace std;

class Interpreter
{
private:
    DatalogProgram datalogProgram;
    vector<Predicate> schemes;
    vector<Predicate> facts;
    vector<Predicate> query;
    vector<Rules> rules;
    Database data;
    unsigned int populateCount = 0;

    Graph forwardGraph;
    Graph reverseGraph;


public:
    Interpreter(){}
    Interpreter(DatalogProgram givenDatalogProgram)
    {
        datalogProgram = givenDatalogProgram;
        schemes = datalogProgram.getScheme();
        facts = datalogProgram.getFacts();
        query = datalogProgram.getQueries();
        rules = datalogProgram.getRules();

        for (unsigned int i = 0 ; i < schemes.size() ; i++)
        {
            Header myHeader;
            myHeader.setHeader(schemes.at(i).getVectorOfStrings());
            Relation newRelation(schemes.at(i).getID() , myHeader);
            data.insert(schemes.at(i).getID() , newRelation);
        }

        for (unsigned int i = 0 ; i < facts.size() ; i++)
        {
            Tuple myTuple;
            myTuple.setTuple(facts.at(i).getVectorOfStrings());
            data.addTuple(facts.at(i).getID() , myTuple);
        }

        unsigned int preCount;
        unsigned int postCount;

        forwardDependency(rules);
        reverseDependency();

        reverseGraph.dfsForestReverse(reverseGraph);

        forwardGraph.clearPostOrder();
        forwardGraph.setPostOrder(reverseGraph.getPostOrder());

        forwardGraph.dfsForestForward(forwardGraph);

        cout << "Dependency Graph" << endl;
        for (unsigned int i = 0 ; i < forwardGraph.getNodeMap().size() ; i++)
        {
            forwardGraph.toString(i);
        }

        cout << endl << "Rule Evaluation" << endl;


        for(unsigned int i = 0 ; i < forwardGraph.getSCCs().size() ; i++)
        {
            populateCount = 0;
            cout << "SCC: R" << i << endl;
            unsigned int key = *forwardGraph.getSCCs().at(i).begin();
            if (forwardGraph.getSCCs().at(i).size() == 1 && !forwardGraph.getHasSelfLoop(key))
            {
                cout << rules.at(key).toString() << endl;
                evaluateRule(rules.at(key));
                populateCount++;
            }
            else
            {
                do
                {
                    preCount = data.count();

                    for (unsigned int j : forwardGraph.getSCCs().at(i))
                    {
                        cout << rules.at(j).toString() << endl;
                        evaluateRule(rules.at(j));
                    }

                    postCount = data.count();
                    populateCount++;

                } while (preCount != postCount);
            }
            cout << populateCount << " passes: R" << i << endl;
        }

        cout << endl << "Query Evaluation" << endl;

        evaluateAllPredicates(query);

    }

    void evaluateRule(Rules givenRule)
    {
        Relation relation = evaluatePredicate(givenRule.getPredicateList().at(0));

        for (unsigned int i = 1 ; i < givenRule.getPredicateListSize() ; i++)
        {
            Relation relation2 = evaluatePredicate(givenRule.getPredicateList().at(i));
            relation = relation.naturalJoin(relation2);
        }

        vector<unsigned int> columnsToKeep;
        vector<string> newHeader;

        for (unsigned int i = 0 ; i < givenRule.getHeadPredicate().getSize() ; i++)
        {
            for (unsigned int j = 0 ; j < relation.getHeader().size() ; j++)
            {
                if (relation.getHeader().toString(j) == givenRule.getHeadPredicate().getParameterString(i))
                {
                    columnsToKeep.push_back(j);
                    newHeader.push_back(relation.getHeader().toString(i));
                }
            }
        }

        relation = relation.project(columnsToKeep);
        relation = relation.rename(newHeader);

        data.getRelation(givenRule.getHeadPredicate().getID()).unionFunction(relation);

    }

    Relation evaluatePredicate(Predicate& predicate)
    {
        vector<string> selectedString;
        vector<unsigned int> selectedInt;

        Relation relation1 = data.getRelation(predicate.getID());

        for (unsigned int i = 0 ; i < predicate.getSize() ; i++)
        {
            if (predicate.getParameters().at(i).isConstant())
            {
                relation1 = relation1.select1(predicate.getParameterString(i) , i);
            }
            else
            {
                selectedString.push_back(predicate.getParameterString(i));
                selectedInt.push_back(i);

                for(unsigned int j = 0 ; j < selectedInt.size() - 1 ; j++)
                {
                    if(predicate.getParameterString(i) == selectedString.at(j))
                    {
                        selectedString.pop_back();
                        selectedInt.pop_back();
                        relation1 = relation1.select2(i , j);
                    }
                }
            }
        }

        relation1 = relation1.project(selectedInt);
        relation1 = relation1.rename(selectedString);

        return relation1;
    }

    void evaluateAllPredicates(vector<Predicate> givenVectorOfPredicates) //pass in query of vector
    {
        Relation newRelation;
        for (unsigned int i = 0 ; i < givenVectorOfPredicates.size() ; i++)
        {
            newRelation = evaluatePredicate(givenVectorOfPredicates.at(i));
            cout << givenVectorOfPredicates.at(i).toString() << "? ";
            if (newRelation.getTuples().size() == 0)
            {
                cout << "No";
            }
            else
            {
                cout << "Yes(" << newRelation.getTuples().size() << ")";
            }
            cout << endl;
            newRelation.toString();
        }
    }

    void forwardDependency(vector<Rules>& givenRules)
    {
        for (unsigned int i = 0 ; i < givenRules.size() ; i++)
        {
            set<unsigned int> ruleIdNums;
            for (unsigned int j = 0 ; j < givenRules.at(i).getPredicateListSize() ; j++)
            {
                for (unsigned int k = 0 ; k < givenRules.size() ; k++)
                {
                    if(givenRules.at(i).getPredicateList().at(j).getID() == givenRules.at(k).getHeadPredicate().getID())
                    {
                        ruleIdNums.insert(k);
                    }
                }
            }
            forwardGraph.insert(i , Node(i , ruleIdNums));
            forwardGraph.hasSelfLoop(i);
        }
    }

    void reverseDependency()
    {
        for (unsigned int i = 0 ; i < forwardGraph.getNodeMap().size() ; i++)
        {
            set<unsigned int> empty;
            reverseGraph.insert(i , Node(i , empty));
        }

        for (pair<unsigned int , Node> i : forwardGraph.getNodeMap())
        {
            for (unsigned int k : i.second.getAdjacencyList())
            {
                reverseGraph.insertNum(k , i.first);
            }
        }
    }

};

#endif //PROJECT_3_INTERPRETER_H
