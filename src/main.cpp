#include <iostream>
#include <memory>
#include <vector>
#include "listgraph.h"
#include "matrixgraph.h"

int main()
{
    
    

    IGraph* ptr = new MatrixGraph(5);
        
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

    IGraph* list = new ListGraph(ptr);
   /* list->AddEdge(1, 2);
    list->AddEdge(2, 3);
    list->AddEdge(2, 4);
    list->AddEdge(3, 1);
    list->AddEdge(3, 4);*/
    list->ShowGraph();
    
    
    delete list;
    delete ptr;

    return 0;
}