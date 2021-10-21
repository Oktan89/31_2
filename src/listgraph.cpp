#include <iostream>
#include <map>
#include <vector>
#include <climits>
#include "listgraph.h"
#include "matrixgraph.h"
//
//  ListGraph implementation
//

ListGraph::ListGraph()
{
    std::cout << "constructor ListGraph\n";
   // _graph = new std::map<std::size_t, std::vector<std::size_t>>;
}

ListGraph::ListGraph(IGraph *oth)
{
    //Приводим базовый класс к дочернему
    MatrixGraph *matrix = dynamic_cast<MatrixGraph *>(oth);
    //если не матрица то выходим
    if (matrix)
    {
        std::cout << "Convert matrix to list" << std::endl;
        //Полочаем количество вершин в матрице
        std::size_t vertex_count = matrix->VerticesCount();

        for (std::size_t i = 0; i < vertex_count + 1; ++i)
        {
            std::vector<std::size_t> vec;
            matrix->GetNextVertices(i, vec);//Сотрим соседей вершины
            if (vec.size() != 0) //если соседи есть
            {
                for (const auto &n : vec)
                    this->AddEdge(i, n);//добавляем ребра от текушей вершины
            }
            else//если соседей нет
            {
                std::vector<std::size_t> vec;
                matrix->GetPrevVertices(i, vec);//смотрим соседей в другую сторону
                if (vec.size() != 0)//если есть, то добавляем текушую вершину как начальную
                {
                    _graph[i] = std::vector<std::size_t>();//с пустыми исходящими так как в прямом направлении их нет
                }
            }
        }
    }
    else
    {
        std::cout << "No convert matrix to list" << std::endl;
    }
}

/*ListGraph::ListGraph(const ListGraph &list_g)
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
}*/

ListGraph::~ListGraph()
{
    std::cout << "destructor ~ListGraph\n";
}

void ListGraph::AddEdge(size_t from, size_t to)
{
    // провекра на отрицательные
    if(from == ULONG_MAX || to == ULONG_MAX) 
    {
        std::cout << "error input: can't be negative\n";
        return;
    }
    std::vector<std::size_t> vertices_to{to};

    //Вствляем вершины
    auto it = _graph.insert(std::make_pair(from, vertices_to));
    //Если вершина from уже есть, то вставлем соседа
    if (!it.second)
    {
        it.first->second.push_back(to);
    }
    //ищем вершину to в ключах from, если ее нет вставляем пустую
    auto fit = _graph.find(to);
    if (fit == _graph.end())
    {
        _graph[to] = std::vector<std::size_t>();
    }
}

int ListGraph::VerticesCount() const
{
    return _graph.size();
}

void ListGraph::ShowGraph() const
{
    for(auto &it : _graph)
    {
        std::cout << it.first;
        for(auto &verex : it.second)
            std::cout << "->" << verex;

        std::cout<<std::endl; 
    }
}

void ListGraph::GetNextVertices(size_t vertex, std::vector<size_t> &vertices) const
{
    auto it = _graph.find(vertex);

    if(it != _graph.end())
    {
        for(auto &vert : it->second)
            vertices.push_back(vert);
    }
    else
    {
        std::cout<< "Incorect vertex" << std::endl;
    }
}

void ListGraph::GetPrevVertices(size_t vertex, std::vector<size_t> &vertices) const
{
    auto it_g = _graph.find(vertex);

      if(it_g != _graph.end())
    {
       for(auto it = _graph.begin(); it != _graph.end(); ++it)
       {
          for(std::size_t vec = 0; vec < it->second.size(); ++vec)
          {
              if(vertex == it->second[vec])
              {
                  vertices.push_back(it->first);
              }
          }
       }
    }
    else
    {
        std::cout<< "Incorect vertex" << std::endl;
    }
}

void ListGraph::GetNameVertices(std::vector<std::size_t> &name) const
{
    for(auto it = _graph.begin(); it != _graph.end(); ++it)
    {
        name.push_back(it->first);
    }
}
