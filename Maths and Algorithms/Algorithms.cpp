#include "Algorithms.h"

int* Algorithms::BubbleSort(int* Data, size_t Size)
{

        for(int i = 0; i < Size; i++)
        {
            for (int j = 0; j < Size; j++)
            {
                if (Data[j] > Data[j + 1])
                {
                    int temp1 = Data[j];
                    int temp2 = Data[j + 1];

                    Data[j] = temp2;
                    Data[j + 1] = temp1;
                }
            }
        }    
    
        return Data;
}

int* Algorithms::InsertionSort(int* Data, size_t Size)
{
    return nullptr;
}

int* Algorithms::SelectionSort(int* Data, size_t Size)
{
    return nullptr;
}

int* Algorithms::HeapSort(int* Data, size_t Size)
{
    return nullptr;
}

int* Algorithms::MergeSort(int* Data, size_t Size)
{
    return nullptr;
}

int* Algorithms::QuickSort(int* Data, size_t Size)
{
    return nullptr;
}

int* Algorithms::BinSort(int* Data, size_t Size)
{
    return nullptr;
}

int* Algorithms::LinierSearch(int* Data, size_t Size, int target)
{
    return nullptr;
}

int* Algorithms::BinarySearch(int* Data, size_t Size, int target)
{
    return nullptr;
}
