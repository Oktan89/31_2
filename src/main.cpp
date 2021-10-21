#include <iostream>
#include <memory>
#include <vector>
#include "listgraph.h"
#include "matrixgraph.h"

int main()
{
    
    std::shared_ptr<IGraph> ptr = std::make_shared<MatrixGraph>();
    ptr->AddEdge(1, 8);
    ptr->AddEdge(1, 2);
    ptr->AddEdge(2, 3);
    ptr->AddEdge(3, 4);
    ptr->AddEdge(4, 5);
    ptr->AddEdge(5, 6);
    ptr->AddEdge(5, 7);
    ptr->AddEdge(6, 7);
    ptr->AddEdge(7, 6);
    ptr->ShowGraph();

    std::shared_ptr<IGraph> ptr_list = std::make_shared<ListGraph>(ptr.get());

    ptr_list->ShowGraph();

    std::shared_ptr<IGraph> ptr_list2 = std::make_shared<ListGraph>();

    ptr_list2 = ptr_list;

    ptr_list2->ShowGraph();

    std::shared_ptr<IGraph> ptr2 = std::make_shared<MatrixGraph>(ptr_list2.get());
    ptr2->ShowGraph();
    
    return 0;
}