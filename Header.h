//
// Created by travi on 7/14/2021.
//

#ifndef PROJECT_3_HEADER_H
#define PROJECT_3_HEADER_H

#include <vector>
#include <string>

using namespace std;

class Header
{
private:
    vector<string> header;

public:
    Header(){}

    void setHeader(vector<string> givenHeader)
    {
        header = givenHeader;
    }

    unsigned int size()
    {
        return header.size();
    }

    vector<string> getHeader()
    {
        return header;
    }

    string toString(unsigned int index)
    {
        return header.at(index);
    }

};

#endif //PROJECT_3_HEADER_H
