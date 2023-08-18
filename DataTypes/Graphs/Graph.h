#pragma once
#include <iostream>
#include <vector>


class Graph
{
public:
    Graph();
    ~Graph();

    void PrintGraph(std::vector<int> edges[], int vertices);
    void AddEdge(std::vector<int> edges[], int source, int destination);

};

