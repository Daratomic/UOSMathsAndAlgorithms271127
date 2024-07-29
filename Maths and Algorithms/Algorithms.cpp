#include "Algorithms.h"

int* Algorithms::BubbleSort(int* Data, size_t Size)
{

	for (int i = 0; i < Size; i++)
	{
		for (int j = 0; j < Size - 1; j++)
		{
			if (Data[j] > Data[j + 1])
			{
				int temp1 = Data[j];
				Data[j] = Data[j + 1];
				Data[j + 1] = temp1;
			}
		}
	}

	return Data;
}

int* Algorithms::InsesrtionSort(int* Data, size_t Size)
{
    for (int i = 1; i < Size; i++)
    {
        int j = i - 1;

        while (j >= 0 && Data[j] > Data[i])
        {
            Data[j + 1] = Data[j];
            j = j - 1;
        }

        Data[j + 1] = Data[i];
    }
    
    return Data;
}

int* Algorithms::SelectionSort(int* Data, size_t Size)
{
    for (int i = 0; i < Size - 1; i++)
    {
        int min_pos = i; // Smallest element in array
        for (int j = i + 1; j < Size; j++) // swap elements if value is bigger
        {
            if (Data[j] < Data[i])
            {
                Data[i] = j;
            }
        }

        if (min_pos != i) // if element is already the smallest, do not swap
        {
            int temp = Data[i];
            Data[i] = Data[min_pos];
            Data[min_pos] = temp;
        }
    }

    return Data;
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
