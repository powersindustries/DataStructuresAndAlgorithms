#pragma once
#include <iostream>
#include <vector>


template <class T>
class DisjointSet
{
public:


    // ----------------------------------------------------------------
    // ----------------------------------------------------------------
    DisjointSet<T>(int setSize)
    {
        m_Root.reserve(setSize);

        // Initialize default values.
        for (int x=0; x < setSize; ++x)
        {
            m_Root.push_back(x);
        }
    }


    // ----------------------------------------------------------------
    // ----------------------------------------------------------------
    ~DisjointSet<T>()
    {
    }


    // ----------------------------------------------------------------
    // ----------------------------------------------------------------
    void AddUnionSet(T inX, T inY)
    {
        int rootX = m_Root[inX];
        int rootY = m_Root[inY];

        if (rootX != rootY)
        {
            for (int x=0; x < m_Root.size(); ++x)
            {
                if (m_Root[x] == rootY)
                {
                    m_Root[x] = rootX;
                }
            }
        }
    }


    // ----------------------------------------------------------------
    // ----------------------------------------------------------------
    bool VertexConnected(T inX, T inY)
    {
        return m_Root[inX] == m_Root[inY];
    }


private:

    std::vector<T> m_Root;

};
