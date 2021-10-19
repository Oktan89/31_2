#include <iostream>
#include "matrixgraph.h"
#include "listgraph.h"
//
//  MatrixGraph implementation
//

MatrixGraph::MatrixGraph(int capacity) : c_ratio(capacity)
{
    _size_from = 0;
    _size_to = 0;
    _capacity_from = 0;
    _capacity_to = 0;
    _graph = nullptr;
}

void MatrixGraph::resize(size_t new_size_from, size_t new_size_to)
{
    
    bool **new_graph = nullptr;
    
    //копируем старый массив во временный если он есть
    if (_graph != nullptr)
    {
        //Создаем временный массив с новым размером
        new_graph = new bool *[new_size_from];
        for (int count_row = 0; count_row < new_size_from; ++count_row)
        {
            new_graph[count_row] = new bool[new_size_to];
            //Заполняем строку массива
            for (int j = 0; j < new_size_to; ++j)
            {
                new_graph[count_row][j] = false;
            }
        }
        //копируем старый массив во временный
        for (int i = 0; i < new_size_from; ++i)
        {
            for (int j = 0; j < new_size_to; ++j)
            {
                if (i < _size_from && j < _size_to)
                {
                   new_graph[i][j] = _graph[i][j];
                }
            }
        }
        //Удаляем старый массив из пямяти
        for (int count_col = 0; count_col < _capacity_from; ++count_col)
        {
            delete[] _graph[count_col];
        }
        delete[] _graph;
        _graph = nullptr;
    }
    //Сохраняем новый размер
    _size_from = new_size_from;
    _size_to = new_size_to;
    //увеличиваем емскость
    _capacity_from = new_size_from + c_ratio; 
    _capacity_to = new_size_to + c_ratio;    
    //Выделяем новый размер массива из пямяти c увеличенной емкостью
    _graph = new bool *[_capacity_from];
    for (int count_row = 0; count_row < _capacity_from; ++count_row)
    {
        _graph[count_row] = new bool[_capacity_to];
        for (int j = 0; j < new_size_to; ++j)
        {
            _graph[count_row][j] = false;
        }
    }
    //Копируем массив из временного в постоянный
    if (new_graph != nullptr)
    {
        for (int i = 0; i < new_size_from; ++i)
        {
            for (int j = 0; j < new_size_to; ++j)
            {
                _graph[i][j] = new_graph[i][j];
            }
        }
        //Удаляем временный массив
        for (int count_col = 0; count_col < new_size_from; ++count_col)
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
    _graph = new bool *[list_g._capacity_from];
    for(int count_row = 0; count_row < list_g._capacity_from; ++count_row)
    {
        _graph[count_row] = new bool[list_g._capacity_to];
        //Заполняем строку массива
        for (int j = 0; j < list_g._capacity_to; ++j)
        {
            _graph[count_row][j] = false;
        }
    }
    //Копируем массив 
     for(int i = 0; i < list_g._size_from; ++i)
    {
        for(int j = 0; j < list_g._size_to; ++j)
        {
            _graph[i][j] = list_g._graph[i][j];
        }
    }
    _size_from = list_g._size_from;
    _size_to = list_g._size_to;
    _capacity_from = list_g._capacity_from;
    _capacity_to = list_g._capacity_to;
}

MatrixGraph& MatrixGraph::operator=(const MatrixGraph &list_g)
{
    std::cout << "Create copy= Matrix" << std::endl;
    if(this == &list_g)
        return *this;

    if (_graph != nullptr)
    {
        for (int count_col = 0; count_col < _capacity_from; ++count_col)
        {
            delete[] _graph[count_col];
        }
        delete[] _graph;
    }

    _graph = new bool *[list_g._capacity_from];
    for(int count_row = 0; count_row < list_g._capacity_from; ++count_row)
    {
        _graph[count_row] = new bool[list_g._capacity_to];
        //Заполняем строку массива
        for (int j = 0; j < list_g._capacity_to; ++j)
        {
            _graph[count_row][j] = false;
        }
    }
    //Копируем массив 
     for(int i = 0; i < list_g._size_from; ++i)
    {
        for(int j = 0; j < list_g._size_to; ++j)
        {
            _graph[i][j] = list_g._graph[i][j];
        }
    }
    _size_from = list_g._size_from;
    _size_to = list_g._size_to;
    _capacity_from = list_g._capacity_from;
    _capacity_to = list_g._capacity_to;

    return *this;
}

MatrixGraph::~MatrixGraph()
{
    std::cout << "destructor ~MatrixGraph\n";
    for(int count_col = 0; count_col < _capacity_from; ++count_col)
    {
        delete[] _graph[count_col];
    }
    delete[] _graph;
}

void MatrixGraph::AddEdge(size_t from, size_t to) 
{
    // провекра на отрицательные
    if(from < 0 || to < 0) 
    {
        std::cout << "error input: can't be negative\n";
        return;
    }
    //Проверка на длину ребра и если мало увеличиваем массив и емкость
    if(from >= _capacity_from || to >= _capacity_to) 
    {
        //Увеличиваем размер на 1 из за принимаемых параметров от 0
        resize(std::max(from+1, _capacity_from), std::max(to+1, _capacity_to)); 
    }
    //Проверка на длину ребра и если мало увеличиваем рабочий размер массива
    if(from >= _size_from || to >= _size_to) 
    {
        _size_from = std::max(_size_from, from+1);
        _size_to = std::max(_size_to, to+1);
    }

    //Соединяем вершины от from до to 
    //(индекс строки массива - номер вершины хвоста)
    //(индекс колонки массива - номер вершины головы) 
    // Например from->to
    _graph[from][to] = true; 
}

int MatrixGraph::VerticesCount() const
{
    
    return 0;
}

void MatrixGraph::ShowGraph() const
{   std::cout<<"  ";
    for(int head = 0; head < _size_to; ++head)
        std::cout<<head;
    std::cout << std::endl;

    for(int i = 0; i < _size_from; ++i)
    {
        std::cout << i <<":";
        for(int j = 0; j < _size_to; ++j)
        {
            std::cout<<_graph[i][j];
            //if(_graph[i][j])
            //    std::cout << i <<" -> " << j << " ";
        }
        std::cout<<"\n";
    }
    std::cout<<std::endl;
}

void MatrixGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const
{
    std::cout << "GetNext" << std::endl;
}

void MatrixGraph::GetPrevVerices(int vertex, std::vector<int> &vertices) const
{
    std::cout << "GetPrev" << std::endl;
}