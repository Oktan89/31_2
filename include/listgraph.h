#pragma once
#include <vector>
#include "igraph.h"

class ListGraph : public IGraph
{

public:
    ListGraph();

    ListGraph(IGraph* oth);
    
    ListGraph(const ListGraph &list_g);

    ListGraph& operator= (const ListGraph &list_g);

    ~ListGraph();

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    virtual void GetNextVertices(int vertex, std::vector<int> &vertices) const override;

    virtual void GetPrevVerices(int vertex, std::vector<int> &vertices) const override;
};