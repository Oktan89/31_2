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
    size_t _size;
    size_t _capacity;
    bool** _graph;

    struct Quantity_cache
    {
        mutable bool status;
        mutable size_t vertices;
    } cache;

    void resize(size_t new_size);

public:
    //Устанавливает емкость матрицы
    MatrixGraph(int capacity = 5);
    
    MatrixGraph(IGraph *oth);
    
    MatrixGraph(const MatrixGraph &matrix_g);

    MatrixGraph& operator= (const MatrixGraph &matrix_g);
    
    ~MatrixGraph();

// Метод принимает вершины начала и конца ребра и добавляет ребро
    void AddEdge(size_t from, size_t to) override;

// Метод должен считать текущее количество вершин
    int VerticesCount() const override;

// [experimental] Вывод графа в консоль 
    void ShowGraph() const override;

// Для конкретной вершины метод выводит в вектор “вершины” все вершины, в которые можно дойти по ребру из данной
    void GetNextVertices(size_t vertex, std::vector<size_t> &vertices) const override;

// Для конкретной вершины метод выводит в вектор “вершины” все вершины, из которых можно дойти по ребру в данную
    void GetPrevVertices(size_t vertex, std::vector<size_t> &vertices) const override;

    int SizeMatrix() const {return _size;}

    int CapacityMatrix() const {return _capacity;}
};