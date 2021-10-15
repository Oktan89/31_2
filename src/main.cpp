#include <iostream>
#include <memory>
#include "listgraph.h"
#include "matrixgraph.h"

int main()
{
    

    std::shared_ptr<IGraph> ptr = std::make_shared<ListGraph>();
    
    std::shared_ptr<IGraph> ptr2 = std::make_shared<MatrixGraph>(ptr.get());
    
    std::cout << ptr->VerticesCount() << std::endl;
    std::cout << ptr2->VerticesCount() << std::endl;

    return 0;
}