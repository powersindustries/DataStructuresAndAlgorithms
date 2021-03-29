#pragma once
#include <list>


class Searching
{
public:
    Searching();
    
    int BinarySearch(int array[], int size, int value);

};


class BFSGraph
{
public:
    BFSGraph(int vertices);

    void AddEdge(int start, int end);

    void BreadthFirstSearch(int value);

public:
    std::list<int> *m_Nodes;
    int m_VerticeCount;

};


class DFSGraph
{
public:
    DFSGraph(int vertices);

    void DepthFirstSearch(int graph[4][4], int search);
    
private:
    void DFSUtil(int graph[4][4], bool visited[], int search);

public:
    int m_VerticeCount;

};

