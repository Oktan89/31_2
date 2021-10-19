#include <iostream>
#include "listgraph.h"
#include "matrixgraph.h"
//
//  ListGraph implementation
//

ListGraph::ListGraph()
{
    std::cout << "constructor ListGraph\n";
}

ListGraph::ListGraph(IGraph* oth)
{
    MatrixGraph* matrix = dynamic_cast<MatrixGraph*>(oth);
    if(matrix)
    {
        std::cout << "Convert matrix to list" << std::endl;
    }
    else
    {
        std::cout << "No convert matrix to list" << std::endl;
    }
}

ListGraph::ListGraph(const ListGraph &list_g)
{
     //create ptr || copy ptr
}

ListGraph& ListGraph::operator=(const ListGraph &list_g)
{
    if(this == &list_g)
            return *this;
        
        //delete ptr
        //create ptr || copy ptr

    return *this;
}

ListGraph::~ListGraph()
{
    std::cout << "destructor ~ListGraph\n";
}

void ListGraph::AddEdge(size_t from, size_t to) 
{
    std::cout << from << " : " << to << std::endl;
}

int ListGraph::VerticesCount() const
{
    return 0;
}

void ListGraph::ShowGraph() const
{

}

void ListGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const
{
    std::cout << "GetNext" << std::endl;
}

void ListGraph::GetPrevVerices(int vertex, std::vector<int> &vertices) const
{
    std::cout << "GetPrev" << std::endl;
}

