#pragma once
#include <ctype.h>



template <typename T>
class Stack
{
public:
    T* Data;
    size_t Size;
    int count = 0;

    Stack()
    {
        Size = 0;
        Data = nullptr;
    }

    ~Stack()
    {
        if (Data != nullptr)
        {
           delete[] Data;
        }
    }

    T Pop();
    T Peek();
    void Push(T dataToPush);

};

template <typename T>
class Queue
{
public:

    T* Data;
    size_t Size;

    T Pop();
    T Peek();
    void Push(T dataToPush);
};


template <typename T>
struct Node
{
    T Data;

    Node* Left;
    Node* Right;
};

template <typename T>
class MinimumBinaryHeap
{

public:
    Node<T>* Root;

    void Add(T DataToAdd);
    T Remove();

    void HeapifyUp(); //bubble Up
    void HeapifyDown(); //Bubble Down;
};

template<typename T>
inline T Stack<T>::Pop()
{    
    if (count == 0) throw std::out_of_range("Pop");
    count--;
    return Data[count];
}

template<typename T>
inline T Stack<T>::Peek()
{
    if (count == 0) throw std::out_of_range("Peek");
    return Data[count - 1];
}

template<typename T>
inline void Stack<T>::Push(T dataToPush)
{
    // No array allocated yet
    if (Data == nullptr)
    {
        Data = new T[4];
        Size = 4;
    }

    // Array already full
    if (Size == count)
    {
        T* newData = new T[Size * 2];
        for (int = 0; i < Size; ++i)
        {
            newData[i] = Data[i];
        }
        delete[] Data;
        Data = newData;
        Size = 2 * Size;
    }

    Data[count] = dataToPush;
    count++;
}

template<typename T>
inline T Queue<T>::Pop()
{
    T firstIndex = Data[0];
    Data[0] = null;
}

template<typename T>
inline T Queue<T>::Peek()
{
    return Data[0];
}

template<typename T>
inline void Queue<T>::Push(T dataToPush)
{
    Data[Index] = dataToPush;
    index++;
}
