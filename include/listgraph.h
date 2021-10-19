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
    void AddEdge(size_t from, size_t to) override;

// Метод должен считать текущее количество вершин
    int VerticesCount() const override;

// Вывод графа в консоль 
    void ShowGraph() const override;

// Для конкретной вершины метод выводит в вектор “вершины” все вершины, в которые можно дойти по ребру из данной
    void GetNextVertices(size_t vertex, std::vector<size_t> &vertices) const override;

// Для конкретной вершины метод выводит в вектор “вершины” все вершины, из которых можно дойти по ребру в данную
    void GetPrevVertices(size_t vertex, std::vector<size_t> &vertices) const override;
};