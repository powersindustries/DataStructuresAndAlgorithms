#include "Searching.h"
#include <iostream>
#include <algorithm>


// ----------------------------------------------------------------
// ----------------------------------------------------------------
Searching::Searching()
{
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
int Searching::BinarySearch(int array[], int size, int value)
{
    int lowValue = 0;
    int highValue = size - 1;

    // sort array
    std::sort(array, array + size);

    while (lowValue <= highValue)
    {
        int midIndex = lowValue + (highValue - lowValue) / 2;

        if (array[midIndex] == value)
        {
            return midIndex;
        }
        
        if (array[midIndex] < value)
        {
            lowValue = midIndex + 1;
        }
        else
        {
            highValue = midIndex - 1;
        }
    }
    return -1; // Value wasnt found
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
BFSGraph::BFSGraph(int vertices)
{
    m_VerticeCount = vertices;
    m_Nodes = new std::list<int>[m_VerticeCount];
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
BFSGraph::~BFSGraph()
{
    delete[] m_Nodes;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void BFSGraph::AddEdge(int start, int end)
{
    m_Nodes[start].push_back(end);
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void BFSGraph::BreadthFirstSearch(int value)
{
    // Creating visited array so we can prevent looping, keep track of where weve been
    bool* visited = new bool[m_VerticeCount];

    // Sett initial visited to false
    for (int x = 0; x < m_VerticeCount; ++x)
    {
        visited[x] = false;
    }

    std::list<int> checkVector;
    visited[value] = true;
    checkVector.push_back(value);

    std::list<int>::iterator x;

    while (checkVector.empty() == false)
    {
        value = checkVector.front();

        std::cout << value << ", ";
        checkVector.pop_front();

        for (x = m_Nodes[value].begin(); x != m_Nodes[value].end(); ++x)
        {
            if (!visited[*x])
            {
                checkVector.push_back(*x);
                visited[*x] = true;
            }
        }
    }
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
DFSGraph::DFSGraph(int vertices)
{
    m_VerticeCount = vertices;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
DFSGraph::~DFSGraph()
{
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void DFSGraph::DepthFirstSearch(int graph[4][4], int search)
{
    bool* visited = new bool[m_VerticeCount];

    for (int x = 0; x < m_VerticeCount; ++x)
    {
        visited[x] = false;
    }

    DFSUtil(graph, visited, search);
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void DFSGraph::DFSUtil(int graph[4][4], bool visited[], int search)
{
    visited[search] = true;
    std::cout << search << ", ";

    for (int x = 0; x < m_VerticeCount; ++x)
    {
        if (graph[search][x] == 1 && visited[x] == false)
        {
            DFSUtil(graph, visited, x);
        }
    }
}
