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

    vector<unsigned int> postOrder;
    set<unsigned int> SCC;
    vector<set<unsigned int>> SCCs;

public:
    Graph(){}
    ~Graph(){}

    void dfsForestReverse(Graph& givenGraph)
    {
        for (unsigned int i = 0 ; i < givenGraph.nodeMap.size() ; i++)
        {
            if (!givenGraph.nodeMap.at(i).isVisitedNode())
            {
                dfs(givenGraph.nodeMap.at(i) , givenGraph);
            }
        }
    }

    void dfsForestForward(Graph& givenGraph)
    {
        SCC.clear();
        vector<unsigned int> tempPostOrder = postOrder;
        for (unsigned int i = postOrder.size()-1 ; i < postOrder.size() ; i--) //start at top and go down
        {
            if (!givenGraph.nodeMap.at(postOrder.at(i)).isVisitedNode())
            {
                dfs(givenGraph.nodeMap.at(postOrder.at(i)) , givenGraph);
                SCCs.push_back(SCC);
                SCC.clear();
            }
        }
        postOrder.clear();
        postOrder = tempPostOrder;
    }

    void dfs(Node& givenNode , Graph& givenGraph)
    {
        givenGraph.nodeMap.at(givenNode.getNodeId()).setVisitedNode(true);

        for (unsigned int j : givenNode.getAdjacencyList())
        {
            if (!givenGraph.nodeMap.at(j).isVisitedNode())
            {
                dfs(givenGraph.nodeMap.at(j) , givenGraph);
            }
        }
        postOrder.push_back(givenNode.getNodeId());
        SCC.insert(givenNode.getNodeId());
    }

    void insert(unsigned int nodeId , Node node)
    {
        nodeMap.insert(pair<unsigned int , Node> (nodeId, node));
    }

    void insertNum(unsigned int id , unsigned int num)
    {
        nodeMap.at(id).insert(num);
    }

    void hasSelfLoop(unsigned int id)
    {
        nodeMap.at(id).hasSelfLoopFunction();
    }

    bool getHasSelfLoop(unsigned int id)
    {
        return nodeMap.at(id).isHasSelfLoop();
    }

    map<unsigned int, Node> getNodeMap() const
    {
        return nodeMap;
    }


    void setPostOrder(vector<unsigned int> givenStack)
    {
        postOrder = givenStack;
    }

    vector<unsigned int> getPostOrder()
    {
        return postOrder;
    }

    void clearPostOrder()
    {
        postOrder.clear();
    }

    vector<set<unsigned int>> &getSCCs()
    {
        return SCCs;
    }

    Node at(unsigned int key)
    {
        return nodeMap.at(key);
    }

    void toString(unsigned int key)
    {
        nodeMap.at(key).toString();
    }

};


#endif //PROJECT_5_GRAPH_H
