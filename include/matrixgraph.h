#pragma once
#include <vector>
#include "igraph.h"

//
//  MatrixGraph class ориентированный 
//  (строка направление от вершины from колонка направление до вершины to)
//
class MatrixGraph : public IGraph 
{
    const int c_ratio; //коэффициент емкости :)
    int _size_from;
    int _size_to;
    int _capacity_from;
    int _capacity_to;
    bool** _graph;
    void resize(int new_size_from, int new_size_to);

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

// Вывод графа в консоль
    void ShowGraph() const override;

// Для конкретной вершины метод выводит в вектор “вершины” все вершины, в которые можно дойти по ребру из данной
    void GetNextVertices(int vertex, std::vector<int> &vertices) const override;

// Для конкретной вершины метод выводит в вектор “вершины” все вершины, из которых можно дойти по ребру в данную
    void GetPrevVerices(int vertex, std::vector<int> &vertices) const override;

    int SizeMatrix() const {return _size_from + _size_to;}

    int CapacityMatrix() const {return _capacity_from + _capacity_to;}
};