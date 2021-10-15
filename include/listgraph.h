#pragma once
#include <vector>
#include "igraph.h"

//
//  ListGraph class
//
class ListGraph : public IGraph
{

public:
    ListGraph();

    ListGraph(IGraph* oth);
    
    ListGraph(const ListGraph &list_g);

    ListGraph& operator= (const ListGraph &list_g);

    ~ListGraph();

// Метод принимает вершины начала и конца ребра и добавляет ребро
    void AddEdge(int from, int to) override;

// Метод должен считать текущее количество вершин
    int VerticesCount() const override;

// Для конкретной вершины метод выводит в вектор “вершины” все вершины, в которые можно дойти по ребру из данной
    virtual void GetNextVertices(int vertex, std::vector<int> &vertices) const override;

// Для конкретной вершины метод выводит в вектор “вершины” все вершины, из которых можно дойти по ребру в данную
    virtual void GetPrevVerices(int vertex, std::vector<int> &vertices) const override;
};