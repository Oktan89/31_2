#include "listgraph.h"
#include <iostream>

//
//  ListGraph implementation
//

ListGraph::ListGraph()
{
    std::cout << "constructor ListGraph\n";
}

ListGraph::ListGraph(IGraph* oth)
{

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

void ListGraph::AddEdge(int from, int to) 
{
    std::cout << from << " : " << to << std::endl;
}

int ListGraph::VerticesCount() const
{
    return 0;
}

void ListGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const
{
    std::cout << "GetNext" << std::endl;
}

void ListGraph::GetPrevVerices(int vertex, std::vector<int> &vertices) const
{
    std::cout << "GetPrev" << std::endl;
}

