#pragma once
#include <vector>
#include "igraph.h"

//
//  MatrixGraph class
//
class MatrixGraph : public IGraph
{

public:
    MatrixGraph();
    
    MatrixGraph(IGraph *oth);
    
    MatrixGraph(const MatrixGraph &matrix_g);

    MatrixGraph& operator= (const MatrixGraph &matrix_g);
    
    ~MatrixGraph();

// Метод принимает вершины начала и конца ребра и добавляет ребро
    void AddEdge(int from, int to) override;

// Метод должен считать текущее количество вершин
    int VerticesCount() const override;

// Для конкретной вершины метод выводит в вектор “вершины” все вершины, в которые можно дойти по ребру из данной
    virtual void GetNextVertices(int vertex, std::vector<int> &vertices) const override;

// Для конкретной вершины метод выводит в вектор “вершины” все вершины, из которых можно дойти по ребру в данную
    virtual void GetPrevVerices(int vertex, std::vector<int> &vertices) const override;
};