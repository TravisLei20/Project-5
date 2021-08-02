//
// Created by travi on 8/2/2021.
//

#ifndef PROJECT_5_GRAPH_H
#define PROJECT_5_GRAPH_H

#include <stack>

class Graph
{
private:
    struct Node
    {
        Node(){}
        ~Node() = default;
        bool visitedNode = false;
        set<unsigned int> adjacencyList;
        unsigned int ruleID;
    };

    stack<unsigned int> postOrder;
    set<unsigned int> SCC;
    vector<set<unsigned int>> SCCs;

public:
    Graph(){}
    ~Graph(){}

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
