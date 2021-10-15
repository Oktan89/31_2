#include <iostream>
#include "matrixgraph.h"
#include "listgraph.h"
//
//  MatrixGraph implementation
//

MatrixGraph::MatrixGraph() : c_ratio(10)
{
    _size = 0;
    _capacity = 0;
    _graph = nullptr;
}

void MatrixGraph::resize(int new_size)
{
    ++new_size; //Увеличиваем размер на 1 из за принимаемых параметров от 0
    //Создаем временный массив сновым разером
    bool** new_graph = new bool *[new_size];
    for(int count_row = 0; count_row < new_size; ++count_row)
    {
        new_graph[count_row] = new bool[new_size];
    }
    //копируем старый массив во временный если он есть
    if (_graph != nullptr)
    {
        for (int i = 0; i < new_size; ++i)
        {
            for (int j = 0; j < new_size; ++j)
            {
                if (i >= _size || j >= _size)
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
        for (int count_col = 0; count_col < _capacity; ++count_col)
        {
            delete[] _graph[count_col];
        }
        delete[] _graph;
    }
    _capacity = new_size + c_ratio; //увеличиваем емскость
    //Выделяем новый размер массива из пямяти
    _graph = new bool *[_capacity];
    for(int count_row = 0; count_row < _capacity; ++count_row)
    {
        _graph[count_row] = new bool[new_size];
    }
    //Копируем массив из временного в постоянный
     for(int i = 0; i < new_size; ++i)
    {
        for(int j = 0; j < new_size; ++j)
        {
            _graph[i][j] = new_graph[i][j];
        }
    }
    //Сохраняем новый размер
    _size = new_size;

    //Удаляем временный массив
    for(int count_col = 0; count_col < new_size; ++count_col)
    {
        delete[] new_graph[count_col];
    }
    delete[] new_graph;
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
    for(int count_col = 0; count_col < _capacity; ++count_col)
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
    if(from >= _capacity || to >= _capacity) //Проверка на длину ребра и если мало увеличиваем массив и емкость
    {
        int new_size = std::max(from, to);
        resize(new_size);
    }
    if(from >= _size || to >= _size) //Проверка на длину ребра и если мало увеличиваем рабочий размер массива
    {
        _size = std::max(from, to)+1;
    }
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
    for(int head = 0; head < _size; ++head)
        std::cout<<head;
    std::cout << std::endl;

    for(int i = 0; i < _size; ++i)
    {
        std::cout << i <<":";
        for(int j = 0; j < _size; ++j)
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