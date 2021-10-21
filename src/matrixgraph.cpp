#include <iostream>
#include <set>
#include <cassert>
#include <climits>
#include "matrixgraph.h"
#include "listgraph.h"
//
//  MatrixGraph implementation
//

MatrixGraph::MatrixGraph(int capacity) : c_ratio(capacity)
{
    _size = 0;
    _capacity = 0;
    _graph = nullptr;
    cache.status = false;
    cache.vertices = 0;
}

void MatrixGraph::resize(size_t new_size)
{
    
    bool **new_graph = nullptr;
    
    //копируем старый массив во временный если он есть
    if (_graph != nullptr)
    {
        //Создаем временный массив с новым размером
        new_graph = new bool *[new_size];
        for (size_t count_row = 0; count_row < new_size; ++count_row)
        {
            new_graph[count_row] = new bool[new_size];
            //Заполняем строку массива
            for (size_t j = 0; j < new_size; ++j)
            {
                new_graph[count_row][j] = false;
            }
        }
        //копируем старый массив во временный
        for (size_t i = 0; i < new_size; ++i)
        {
            for (size_t j = 0; j < new_size; ++j)
            {
                if (i < _size)
                {
                   new_graph[i][j] = _graph[i][j];
                }
            }
        }
        //Удаляем старый массив из пямяти
        for (size_t count_col = 0; count_col < _capacity; ++count_col)
        {
            delete[] _graph[count_col];
        }
        delete[] _graph;
        _graph = nullptr;
    }
    //Сохраняем новый размер
    _size = new_size;
    
    //увеличиваем емскость
    _capacity = new_size + c_ratio; 
    
    //Выделяем новый размер массива из пямяти c увеличенной емкостью
    _graph = new bool *[_capacity];
    for (size_t count_row = 0; count_row < _capacity; ++count_row)
    {
        _graph[count_row] = new bool[_capacity];
        for (size_t j = 0; j < new_size; ++j)
        {
            _graph[count_row][j] = false;
        }
    }
    //Копируем массив из временного в постоянный
    if (new_graph != nullptr)
    {
        for (size_t i = 0; i < new_size; ++i)
        {
            for (size_t j = 0; j < new_size; ++j)
            {
                _graph[i][j] = new_graph[i][j];
            }
        }
        //Удаляем временный массив
        for (size_t count_col = 0; count_col < new_size; ++count_col)
        {
            delete[] new_graph[count_col];
        }
        delete[] new_graph;
        new_graph = nullptr;
    }
}

MatrixGraph::MatrixGraph(IGraph *oth) : MatrixGraph()
{
    ListGraph* list = dynamic_cast<ListGraph*>(oth);
    if(list)
    {
        std::cout << "Convert List to Matrix" << std::endl;
        std::size_t vertex_count = list->VerticesCount();
        std::vector<std::size_t> name_vertex;
        list->GetNameVertices(name_vertex);
        if(name_vertex.size() != vertex_count)
            return;

        for(std::size_t i_count = 0; i_count < vertex_count; ++i_count)
        {
            std::vector<std::size_t> vertex;
            list->GetNextVertices(name_vertex[i_count], vertex);
            for(auto &v : vertex)
                this->AddEdge(name_vertex[i_count], v);
        }
        
    }
    else
    {
        std::cout << "No convert List to Matrix" << std::endl;
    }
} 
    

MatrixGraph::MatrixGraph(const MatrixGraph &list_g) : MatrixGraph()
{
     std::cout << "Create copy Matrix" << std::endl;
     //Выделяем новый размер массива из пямяти
    _graph = new bool *[list_g._capacity];
    for(size_t count_row = 0; count_row < list_g._capacity; ++count_row)
    {
        _graph[count_row] = new bool[list_g._capacity];
        //Заполняем строку массива
        for (size_t j = 0; j < list_g._capacity; ++j)
        {
            _graph[count_row][j] = false;
        }
    }
    //Копируем массив 
     for(size_t i = 0; i < list_g._size; ++i)
    {
        for(size_t j = 0; j < list_g._size; ++j)
        {
            _graph[i][j] = list_g._graph[i][j];
        }
    }
    _size = list_g._size;
    _capacity = list_g._capacity;
}

MatrixGraph& MatrixGraph::operator=(const MatrixGraph &list_g)
{
    std::cout << "Create copy= Matrix" << std::endl;
    if(this == &list_g)
        return *this;

    if (_graph != nullptr)
    {
        for (size_t count_col = 0; count_col < _capacity; ++count_col)
        {
            delete[] _graph[count_col];
        }
        delete[] _graph;
    }

    _graph = new bool *[list_g._capacity];
    for(size_t count_row = 0; count_row < list_g._capacity; ++count_row)
    {
        _graph[count_row] = new bool[list_g._capacity];
        //Заполняем строку массива
        for (size_t j = 0; j < list_g._capacity; ++j)
        {
            _graph[count_row][j] = false;
        }
    }
    //Копируем массив 
     for(size_t i = 0; i < list_g._size; ++i)
    {
        for(size_t j = 0; j < list_g._size; ++j)
        {
            _graph[i][j] = list_g._graph[i][j];
        }
    }
    _size = list_g._size;
    _capacity = list_g._capacity;
   
    return *this;
}

MatrixGraph::~MatrixGraph()
{
    std::cout << "destructor ~MatrixGraph\n";
    for(size_t count_col = 0; count_col < _capacity; ++count_col)
    {
        delete[] _graph[count_col];
    }
    delete[] _graph;
}

void MatrixGraph::AddEdge(size_t from, size_t to) 
{
    // провекра на отрицательные
    if(from == ULONG_MAX || to == ULONG_MAX) 
    {
        std::cout << "error input: can't be negative\n";
        return;
    }
    //Проверка на длину ребра и если мало увеличиваем массив и емкость
    if(from >= _capacity || to >= _capacity) 
    {
        //Увеличиваем размер на 1 из за принимаемых параметров от 0
        std::size_t max_from = std::max(_capacity, from+1);
        std::size_t max_to = std::max(_capacity, to+1);
        resize(std::max(max_from, max_to)); 
    }
    //Проверка на длину ребра и если мало увеличиваем рабочий размер массива
    if(from >= _size || to >= _size) 
    {
        std::size_t max_from = std::max(_size, from+1);
        std::size_t max_to = std::max(_size, to+1);
        _size = std::max(max_from, max_to);
    }

    //Соединяем вершины от from до to 
    //(индекс строки массива - номер вершины хвоста)
    //(индекс колонки массива - номер вершины головы) 
    // Например from->to
    _graph[from][to] = true; 
    cache.status = true;
}

int MatrixGraph::VerticesCount() const
{
    if (cache.status)
    {
        std::set<size_t> vertices_count;
        for (size_t row = 0; row < _size; ++row)
        {
            for (size_t col = 0; col < _size; ++col)
            {
                if (_graph[row][col] == true)
                {
                    vertices_count.insert(row);
                    vertices_count.insert(col);
                }
            }
        }
        cache.status = false;
        cache.vertices = vertices_count.size();
    }
   
   return cache.vertices;
}

void MatrixGraph::ShowGraph() const
{   std::cout<<"  ";
    for(int head = 0; head < _size; ++head)
        std::cout<<head;
    std::cout << std::endl;

    for(int i = 0; i < _size; ++i)
    {
        std::cout << i <<":";
        for(int j = 0; j < _size; ++j)
        {
            std::cout<<_graph[i][j];
            //if(_graph[i][j])
            //    std::cout << i <<" -> " << j << " ";
        }
        std::cout<<"\n";
    }
    std::cout<<std::endl;
}

void MatrixGraph::GetNextVertices(size_t vertex, std::vector<size_t> &vertices) const
{
    if(vertex > _size)
    {
        std::cout<< "Incorect vertex" << std::endl;
        return;
    }

    for (size_t col = 0; col < _size; ++col)
    {
        if (_graph[vertex][col] == true)
        {
            vertices.push_back(col);
        }
    }
}

void MatrixGraph::GetPrevVertices(size_t vertex, std::vector<size_t> &vertices) const
{
    if(vertex > _size)
    {
        std::cout<< "Incorect vertex" << std::endl;
        return;
    }
    for (size_t row = 0; row < _size; ++row)
    {
        if (_graph[row][vertex] == true)
        {
            vertices.push_back(row);
        }
    }
}