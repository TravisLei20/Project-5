//
// Created by travi on 8/2/2021.
//

#ifndef PROJECT_5_GRAPH_H
#define PROJECT_5_GRAPH_H

#include <stack>

#include "Node.h"

class Graph
{
private:

    map<unsigned int , Node> nodeMap;

    stack<unsigned int> postOrder;
    set<unsigned int> SCC;
    vector<set<unsigned int>> SCCs;

public:
    Graph(){}
    ~Graph(){}

    void insert(unsigned int nodeId , Node node)
    {
        nodeMap.insert(pair<unsigned int , Node> (nodeId, node));
    }

    void insertNum(unsigned int id , unsigned int num)
    {
        nodeMap.at(id).insert(num);
    }

    map<unsigned int, Node> getNodeMap() const
    {
        return nodeMap;
    }


    void setPostOrder(stack<unsigned int> givenStack)
    {
        postOrder = givenStack;
    }

    stack<unsigned int> getPostOrder()
    {
        return postOrder;
    }

    vector<set<unsigned int>> getSCCs()
    {
        return SCCs;
    }

    void dfsForest(Graph& givenGraph)
    {

    }

    void dfs(Node& givenNode , Graph& givenGraph)
    {

    }


};


#endif //PROJECT_5_GRAPH_H
