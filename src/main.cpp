#include <iostream>
#include <memory>
#include <vector>
#include "listgraph.h"
#include "matrixgraph.h"

int main()
{
    

    std::shared_ptr<IGraph> ptr = std::make_shared<MatrixGraph>();
    
    ptr->AddEdge(1, 2);
   
    ptr->AddEdge(1, 8);
    ptr->AddEdge(2, 3);
    ptr->AddEdge(3, 4);
    ptr->AddEdge(4, 5);
    ptr->AddEdge(5, 6);
    ptr->AddEdge(5, 7);
    ptr->AddEdge(6, 7);
   
    ptr->ShowGraph();
    ptr->AddEdge(8, 12);
    ptr->ShowGraph();
//Найти косяк в изменении размера!!!! (выставить коэй в 0)
   // ptr->AddEdge(12, 8); //Придумать уменьшение если не записал или не увеличивать!!!
   // ptr->ShowGraph();
    return 0;
}