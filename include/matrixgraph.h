#pragma once
#include <vector>
#include "igraph.h"

class MatrixGraph : public IGraph
{

public:
    MatrixGraph();
    
    MatrixGraph(IGraph* oth);
    
    MatrixGraph(const MatrixGraph &matrix_g);

    MatrixGraph& operator= (const MatrixGraph &matrix_g);
    
    ~MatrixGraph();

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    virtual void GetNextVertices(int vertex, std::vector<int> &vertices) const override;

    virtual void GetPrevVerices(int vertex, std::vector<int> &vertices) const override;
};