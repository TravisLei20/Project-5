//
// Created by travi on 8/2/2021.
//

#ifndef PROJECT_5_NODE_H
#define PROJECT_5_NODE_H

class Node
{
private:
    bool visitedNode;
    bool hasSelfLoop;
    set<unsigned int> adjacencyList;
    unsigned int nodeID;

public:
    Node(){}
    Node(unsigned int givenID , set<unsigned int> givenSet)
    {
        adjacencyList = givenSet;
        nodeID = givenID;
        visitedNode = false;
        hasSelfLoop = false;
    }
    ~Node() = default;

    void insert(unsigned int num)
    {
        adjacencyList.insert(num);
    }

    bool isVisitedNode() const
    {
        return visitedNode;
    }

    void hasSelfLoopFunction()
    {
        for (unsigned int i : adjacencyList)
        {
            if (nodeID == i)
            {
                hasSelfLoop = true;
            }
        }
    }

    bool isHasSelfLoop() const
    {
        return hasSelfLoop;
    }

    void setVisitedNode(bool visitedNode)
    {
        this->visitedNode = visitedNode;
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

    void toString()
    {
        unsigned int count = 0;
        cout << "R" << nodeID << ":";
        for(unsigned int i : adjacencyList)
        {
            if (count == *adjacencyList.end() - 1)
            {
                cout << "R" << i;
            }
            else
            {
                cout << "R" << i << ",";
            }
            count++;
        }
        cout << endl;
    }
};

#endif //PROJECT_5_NODE_H
