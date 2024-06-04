#pragma once
#include <ctype.h>



template <typename T>
class Stack
{
public:
    T* Data;
    size_t Size;
    int count = 0;

    Stack(size_t size)
    {
        Size = size;
        Data = new T[Size];
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
    count--;
    return T();
}

template<typename T>
inline T Stack<T>::Peek()
{
    return Data[count - 1];
}

template<typename T>
inline void Stack<T>::Push(T dataToPush)
{
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
