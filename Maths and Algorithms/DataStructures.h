#pragma once
#include <ctype.h>
#include <stdexcept>



template <typename T>
class Stack
{
    size_t allocatedSize = 0;
public:
    T* Data = nullptr;
    size_t Size = 0;

    Stack()
    {
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
    size_t allocatedSize = 0;
public:
    T* Data = nullptr;
    size_t Size = 0;

    Queue()
    {
    }

    ~Queue()
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
    if (Size == 0) throw std::out_of_range("Pop");
    Size--;
    return Data[Size];
}

template<typename T>
inline T Stack<T>::Peek()
{
    if (Size == 0) throw std::out_of_range("Peek");
    return Data[Size - 1];
}

template<typename T>
inline void Stack<T>::Push(T dataToPush)
{
    // No array allocated yet
    if (Data == nullptr)
    {
        Data = new T[4];
        allocatedSize = 4;
    }

    // Array already full
    if (allocatedSize == Size)
    {
        T* newData = new T[allocatedSize * 2];
        for (int i = 0; i < allocatedSize; ++i)
        {
            newData[i] = Data[i];
        }
        delete[] Data;
        Data = newData;
        allocatedSize = 2 * allocatedSize;
    }

    Data[Size] = dataToPush;
    Size++;
}

template<typename T>
inline T Queue<T>::Pop()
{
    if (Size == 0) throw std::out_of_range("Pop");
    T popped = Data[0];
    for (int i = 0; i < Size - 1; ++i)
    {
        Data[i] = Data[i + 1];
    }
    Size--;
    return popped;
}

template<typename T>
inline T Queue<T>::Peek()
{
    if (Size == 0) throw std::out_of_range("Peek");
    return Data[0];
}

template<typename T>
inline void Queue<T>::Push(T dataToPush)
{
    // No array allocated yet
    if (Data == nullptr)
    {
        Data = new T[4];
        allocatedSize = 4;
    }

    // Array already full
    if (allocatedSize == Size)
    {
        T* newData = new T[allocatedSize * 2];
        for (int i = 0; i < allocatedSize; ++i)
        {
            newData[i] = Data[i];
        }
        delete[] Data;
        Data = newData;
        allocatedSize = 2 * allocatedSize;
    }

    Data[Size] = dataToPush;
    Size++;
}

template<typename T>
inline void MinimumBinaryHeap<T>::Add(T DataToAdd)
{
    if (Root == nullptr)
    {
        Root = new Node<T>(DataToAdd);
        return;
    }

    while (Root == nullptr)
    {

    }
}

template<typename T>
inline T MinimumBinaryHeap<T>::Remove()
{
    return T();
}

template<typename T>
inline void MinimumBinaryHeap<T>::HeapifyUp()
{
    
}
