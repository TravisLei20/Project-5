//
// Created by travi on 7/14/2021.
//

#ifndef PROJECT_3_RELATION_H
#define PROJECT_3_RELATION_H

#include <set>

#include "Header.h"
#include "Tuple.h"

using namespace std;

class Relation
{
private:
    set<Tuple> tuples;
    string name;
    Header header;
    vector<unsigned int> matchIndexForHeader1;
    vector<unsigned int> matchIndexForHeader2;

public:
    Relation(){}
    Relation(string givenName , Header givenHeader)
    {
        name = givenName;
        header = givenHeader;
    }

    set<Tuple> getTuples()
    {
        return tuples;
    }

    Header getHeader()
    {
        return header;
    }

    string getName()
    {
        return name;
    }

    void addTuples(Tuple givenTuple)
    {
        tuples.insert(givenTuple);
    }

    void setName(string givenString)
    {
        name = givenString;
    }

    void setHeader(Header header1)
    {
        header = header1;
    }

    void unionFunction(Relation givenRelation)
    {
        for (Tuple t : givenRelation.getTuples())
        {
            unsigned int preCount = this->getTuples().size();
            this->addTuples(t);
            //Tuple tuple = t;
            //cout << givenRelation.getTuples().size();
            if (this->getTuples().size() != preCount)
            {
                cout << " ";
                for (unsigned int i = 0 ; i < this->getHeader().size() ; i++)
                {
                    if (this->getHeader().size() != '\'')
                    {
                        cout << this->getHeader().getHeader().at(i) << "=" << t.at(i);
                        if (i < (this->getHeader().size() - 1))
                        {
                            cout << ", ";
                        }
                    }
                }
                cout << endl;
            }
        }
    }

    Relation naturalJoin(Relation relation2)
    {
        Relation result;
        Header newHeader;
        Tuple newTuple;
        newHeader = combineHeaders(this->header, relation2.getHeader());
        result.setHeader(newHeader);
        for (Tuple t : this->tuples)
        {
            for (Tuple t2 : relation2.tuples)
            {
                if(isJoinable(t , t2))
                {
                    newTuple = combineTuples(t , t2);
                    result.addTuples(newTuple);
                }
            }
        }

        return result;
    }

    Header combineHeaders(Header header1 , Header header2)
    {
        Header header;
        vector<string> newHeader = header1.getHeader();

        matchIndexForHeader1.clear();
        matchIndexForHeader2.clear();

        for (unsigned int i = 0 ; i < header2.getHeader().size() ; i++)
        {
            bool isFound = false;
            for (unsigned int j = 0 ; j < header1.getHeader().size() ; j++)
            {
                if (header1.getHeader().at(j) == header2.getHeader().at(i))
                {
                    matchIndexForHeader1.push_back(j);
                    matchIndexForHeader2.push_back(i);
                    isFound = true;
                }
            }
            if (!isFound)
            {
                newHeader.push_back(header2.getHeader().at(i));
            }
        }

        header.setHeader(newHeader);

        return header;
    }

    bool isJoinable(Tuple tuple1 , Tuple tuple2)
    {
        for (unsigned int i = 0 ; i < matchIndexForHeader1.size() ; i++)
        {
            if (tuple1.at(matchIndexForHeader1.at(i)) != tuple2.at(matchIndexForHeader2.at(i)))
            {
                return false;
            }
        }
        return true;
    }

    Tuple combineTuples(Tuple tuple1 , Tuple tuple2)
    {
        Tuple tuple = tuple1;

        for (unsigned int i = 0 ; i < tuple2.getTuples().size() ; i++)
        {
            bool ifMatch = false;
            for (unsigned j = 0 ; j < matchIndexForHeader2.size() ; j++)
            {
                if (i == matchIndexForHeader2.at(j))
                {
                    ifMatch = true;
                }
            }
            if (!ifMatch)
            {
                tuple.push_back(tuple2.at(i));
            }
        }

        return tuple;
    }

    Relation select1 (string givenString , const unsigned int index)
    {
        Relation relation;
        relation.setName(name);
        relation.setHeader(header);

        for (Tuple t : tuples)
        {
            if(t.at(index) == givenString)
            {
                relation.addTuples(t);
            }
        }

        return relation;
    }

    Relation select2 (const unsigned int index1 , const unsigned int index2)
    {
        Relation out;
        out.setName(name);
        out.setHeader(header);

        for (Tuple t : tuples)
        {
            if(t.at(index1) == t.at(index2))
            {
                out.addTuples(t);
            }
        }

        return out;
    }

    Relation project(vector<unsigned int> columnsToKeep)
    {
        Relation out;
        out.setName(name);
        Header newHeader;
        vector<string> newVectorOfHeaders;
        for (unsigned int i = 0 ; i < columnsToKeep.size() ; i++)
        {
            for (unsigned int j = 0 ; j < this->header.getHeader().size() ; j++)
            {
               if(columnsToKeep.at(i) == j)
               {
                   newVectorOfHeaders.push_back(header.getHeader().at(j));
               }
            }
        }
        newHeader.setHeader(newVectorOfHeaders);
        out.setHeader(newHeader);

        for (Tuple t : tuples)
        {
            Tuple newTuple;
            vector<string> newVectorOfTuples;
            for (unsigned int i = 0 ; i < columnsToKeep.size() ; i++)
            {
                for (unsigned int j = 0 ; j < t.getTuples().size() ; j++)
                {
                    if(columnsToKeep.at(i) == j)
                    {
                        newVectorOfTuples.push_back(t.getTuples().at(j));
                    }
                }
            }
            newTuple.setTuple(newVectorOfTuples);
            out.addTuples(newTuple);
        }

        return out;
    }

    Relation rename(vector<string> newHeaderNames)
    {
        Relation out;
        out.setName(name);
        Header newHeader;

        newHeader.setHeader(newHeaderNames);
        out.tuples = this->tuples;

        out.setHeader(newHeader);

        return out;
    }


    void toString()
    {
        unsigned int size = this->header.getHeader().size();
        for (Tuple t : tuples)
        {
            for (unsigned j = 0 ; j < size ; j++)
            {
                if (j == size - 1)
                {
                    cout << "  " << header.toString(j) << "=" << t.at(j) << endl;
                }
                else
                {
                    cout << "  " << header.toString(j) << "=" << t.at(j) << ", ";
                }
            }
        }
    }

};

#endif //PROJECT_3_RELATION_H
