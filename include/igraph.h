#pragma once
#include <iostream>
#include <vector>

class IGraph
{
public:

    virtual ~IGraph() {};

    virtual void AddEdge(size_t from, size_t to) = 0;

    virtual int VerticesCount() const = 0;

    virtual void ShowGraph() const = 0;

    virtual void GetNextVertices(int vertex, std::vector<int> &vertices) const = 0;

    virtual void GetPrevVerices(int vertex, std::vector<int> &vertices) const = 0;

};



