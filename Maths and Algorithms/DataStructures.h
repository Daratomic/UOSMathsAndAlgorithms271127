#pragma once
#include <ctype.h>
#include <stdexcept>


template <typename T>
struct LinkedNode
{
    T element;
    LinkedNode* next = nullptr;
};

template <typename T>
class Stack
{
    LinkedNode<T>* Data = nullptr;
public:
    size_t Size = 0;

    Stack()
    {
    }

    ~Stack()
    {
        // while pointing to any node, delete it and move on to the next node
        while (Data != nullptr)
        {
            LinkedNode<T>* topmost = Data;
            Data = topmost->next;
            delete topmost;
        }
    }

    T Pop();
    T Peek();
    void Push(T dataToPush);

};

template <typename T>
class Queue
{
    LinkedNode<T>* Front = nullptr;
    LinkedNode<T>* Back = nullptr;
public:
    size_t Size = 0;

    Queue()
    {
    }

    ~Queue()
    {
        while (Front != nullptr)
        {
            LinkedNode<T>* first = Front;
            Front = first->next;
            delete first;
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
    if (Data == nullptr) throw std::out_of_range("Pop");
    
    // store topmost node
    LinkedNode<T>* topmost = Data;
    
    // move pointer to item below
    Data = Data->next;
    
    // Take out the stored element
    T element = topmost->element;
    
    // delete allocated container node
    delete topmost;
    
    // Decrement in size and return
    Size--;
    return element;
}

template<typename T>
inline T Stack<T>::Peek()
{
    if (Data == nullptr) throw std::out_of_range("Peek");
    return Data->element;
}

template<typename T>
inline void Stack<T>::Push(T dataToPush)
{
    // No array allocated yet
    if (Data == nullptr)
    {
        Data = new LinkedNode<T>();
        Data->element = dataToPush;
        Size = 1;
        return;
    }

    // Array already full
    LinkedNode<T>* nextData = new LinkedNode<T>();
    nextData->element = dataToPush;
    nextData->next = Data;

    Data = nextData;
    Size++;
}

template<typename T>
inline T Queue<T>::Pop()
{
    if (Front == nullptr) throw std::out_of_range("Pop");

    // store first node
    LinkedNode<T>* first = Front;

    // move pointer to item below
    Front = Front->next;

    // if this removed the last element, set back to nullptr as well
    if (Front == nullptr)
    {
        Back = nullptr;
    }

    // take out stored element
    T element = first->element;

    // deletes the first element
    delete first;

    // decrement size and return
    Size--;
    return element;
}

template<typename T>
inline T Queue<T>::Peek()
{
    if (Front == nullptr) throw std::out_of_range("Peek");
    return Front->element;
}

template<typename T>
inline void Queue<T>::Push(T dataToPush)
{
    // No array allocated yet
    if (Back == nullptr)
    {
        Back = new LinkedNode<T>();
        Back->element = dataToPush;
        Front = Back;
        Size = 1;
        return;
    }

    LinkedNode<T>* nextData = new LinkedNode<T>();
    nextData->element = dataToPush;
    Back->next = nextData;
    Back = nextData;
    Size++;
}

template<typename T>
inline void MinimumBinaryHeap<T>::Add(T DataToAdd)
{
    if (Root == nullptr)
    {
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
