//
// Created by travi on 8/2/2021.
//

#ifndef PROJECT_5_NODE_H
#define PROJECT_5_NODE_H

class Node
{
private:
    bool visitedNode = false;
    set<unsigned int> adjacencyList;
    unsigned int nodeID;

public:
    Node(){}
    Node(unsigned int givenID , set<unsigned int> givenSet)
    {
        adjacencyList = givenSet;
        nodeID = givenID;
    }
    ~Node() = default;

    bool isVisitedNode() const
    {
        return visitedNode;
    }

    void setVisitedNode(bool visitedNode)
    {
        Node::visitedNode = visitedNode;
    }

    set<unsigned int> getAdjacencyList() const
    {
        return adjacencyList;
    }

    void setAdjacencyList(const set<unsigned int> &adjacencyList)
    {
        Node::adjacencyList = adjacencyList;
    }

    unsigned int getNodeId() const
    {
        return nodeID;
    }

    void setNodeId(unsigned int nodeId)
    {
        nodeID = nodeId;
    }
};

#endif //PROJECT_5_NODE_H
