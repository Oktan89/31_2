#include "matrixgraph.h"
//
//  MatrixGraph implementation
//

MatrixGraph::MatrixGraph()
{
    std::cout << "constructor MatrixGraph\n";
}

MatrixGraph::MatrixGraph(IGraph* oth)
{

}

MatrixGraph::MatrixGraph(const MatrixGraph &list_g)
{
     //create ptr || copy ptr
}

MatrixGraph& MatrixGraph::operator=(const MatrixGraph &list_g)
{
    if(this == &list_g)
            return *this;
        
        //delete ptr
        //create ptr || copy ptr

    return *this;
}

MatrixGraph::~MatrixGraph()
{
    std::cout << "destructor ~MatrixGraph\n";
}

void MatrixGraph::AddEdge(int from, int to) 
{
    std::cout << from << " : " << to << std::endl;
}

int MatrixGraph::VerticesCount() const
{
    return 10;
}

void MatrixGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const
{
    std::cout << "GetNext" << std::endl;
}

void MatrixGraph::GetPrevVerices(int vertex, std::vector<int> &vertices) const
{
    std::cout << "GetPrev" << std::endl;
}