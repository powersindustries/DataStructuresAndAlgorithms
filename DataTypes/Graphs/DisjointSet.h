#pragma once
#include <iostream>
#include <vector>


class DisjointSet
{
public:

    DisjointSet(int setSize);
    ~DisjointSet();

    void AddUnionSet(int inX, int inY);
    bool VertexConnected(int inX, int inY);


private:

    std::vector<int> m_Root;

};
