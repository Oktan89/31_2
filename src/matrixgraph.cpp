#include <iostream>
#include "matrixgraph.h"
#include "listgraph.h"
//
//  MatrixGraph implementation
//

MatrixGraph::MatrixGraph() : c_ratio(0)
{
    _size_from = 0;
    _size_to = 0;
    _capacity_from = 0;
    _capacity_to = 0;
    _graph = nullptr;
}

void MatrixGraph::resize(int new_size_from, int new_size_to)
{
    ++new_size_from; //Увеличиваем размер на 1 из за принимаемых параметров от 0
    ++new_size_to; //Увеличиваем размер на 1 из за принимаемых параметров от 0
    //Создаем временный массив с новым разером
    bool** new_graph = new bool *[new_size_from];
    for(int count_row = 0; count_row < new_size_from; ++count_row)
    {
        new_graph[count_row] = new bool[new_size_to];
    }
    //копируем старый массив во временный если он есть
    if (_graph != nullptr)
    {
        for (int i = 0; i < new_size_from; ++i)
        {
            for (int j = 0; j < new_size_to; ++j)
            {
                if (i >= _size_from || j >= _size_to)
                {
                    new_graph[i][j] = false;
                }
                else
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
    _capacity_from = new_size_from + c_ratio; //увеличиваем емскость
    _capacity_to = new_size_to + c_ratio; //увеличиваем емскость
    //Выделяем новый размер массива из пямяти
    _graph = new bool *[_capacity_from];
    for(int count_row = 0; count_row < _capacity_from; ++count_row)
    {
        _graph[count_row] = new bool[_capacity_to];
    }
    //Копируем массив из временного в постоянный
     for(int i = 0; i < new_size_from; ++i)
    {
        for(int j = 0; j < new_size_to; ++j)
        {
            _graph[i][j] = new_graph[i][j];
        }
    }
    //Сохраняем новый размер
    _size_from = new_size_from;
    _size_to = new_size_to;

    //Удаляем временный массив
    for(int count_col = 0; count_col < new_size_from; ++count_col)
    {
        delete[] new_graph[count_col];
    }
    delete[] new_graph;
    new_graph = nullptr;
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
     //create ptr || copy ptr
     std::cout << "Create copy Matrix" << std::endl;
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
    for(int count_col = 0; count_col < _capacity_from; ++count_col)
    {
        delete[] _graph[count_col];
    }
    delete[] _graph;
}

void MatrixGraph::AddEdge(int from, int to) 
{
    if(from < 0 || to < 0) // провекра на отрицательные
    {
        std::cout << "error input: can't be negative\n";
        return;
    }
    if(from >= _capacity_from || to >= _capacity_to) //Проверка на длину ребра и если мало увеличиваем массив и емкость
    {
        resize(std::max(from, _capacity_from), std::max(to, _capacity_to));
    }
    if(from > _size_from || to > _size_to) //Проверка на длину ребра и если мало увеличиваем рабочий размер массива
    {
        _size_from = std::max(_size_from, from)+1 ;
        _size_to = std::max(_size_to, to) + 1;
    }
    if(to < _size_from && from < _size_to)
        if(_graph[to][from]) //Проверка на направление между вершинами, вершины друг на друга указывать не могут
        {
            std::cout << "wrong edge direction\n";
            return;
        }
    //Соединяем вершины от from до to 
    //(индекс строки массива - номер вершины хвоста)
    //(ндекс колонки массива - номер вершины головы) 
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
            /*if(_graph[i][j])
                std::cout << i <<" -> " << j;*/
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