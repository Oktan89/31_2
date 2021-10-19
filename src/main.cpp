#include <iostream>
#include <memory>
#include <vector>
#include "listgraph.h"
#include "matrixgraph.h"

int main()
{
    

    MatrixGraph* ptr = new MatrixGraph(5);
        
    ptr->AddEdge(1, 8);
    ptr->AddEdge(1, 2);
    ptr->AddEdge(2, 3);
    ptr->AddEdge(3, 4);
    ptr->AddEdge(4, 5);
    ptr->AddEdge(5, 6);
    ptr->AddEdge(5, 7);
    ptr->AddEdge(6, 7);
    ptr->AddEdge(7, 6);
    ptr->AddEdge(9, 9);
    std::cout<< ptr->SizeMatrix() << std::endl;
    std::cout<< ptr->CapacityMatrix() << std::endl;
    ptr->ShowGraph();
    std::cout<< ptr->VerticesCount() <<std::endl;

    std::vector<size_t> vec;

    ptr->GetPrevVertices(7, vec);

    for(auto &v : vec)
        std::cout<< v << std::endl;

    delete ptr;

    return 0;
}