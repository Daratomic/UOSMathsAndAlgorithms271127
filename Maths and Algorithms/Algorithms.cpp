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

    int* copyArr = new int[Size];
    for (int i = 0; i < Size; ++i)
    {
        copyArr[i] = Data[i];
    }

	return copyArr;
}

int* Algorithms::InsesrtionSort(int* Data, size_t Size)
{
    for (int i = 1; i < Size; i++)
    {
        int j = i - 1;
        int temp = Data[i];

        while (j >= 0 && Data[j] > temp)
        {
            Data[j + 1] = Data[j];
            j -= 1;
        }

        Data[j + 1] = temp;
    }

    int* copyArr = new int[Size];
    for (int i = 0; i < Size; ++i)
    {
        copyArr[i] = Data[i];
    }
    
    return copyArr;
}

int* Algorithms::SelectionSort(int* Data, size_t Size)
{
    for (int i = 0; i < Size - 1; i++)
    {
        int min_pos = i; // Smallest element in array
        for (int j = i + 1; j < Size; j++) // swap elements if value is bigger
        {
            if (Data[j] < Data[min_pos])
            {
                min_pos = j;
            }
        }

        if (min_pos != i) // if element is already the smallest, do not swap
        {
            int temp = Data[i];
            Data[i] = Data[min_pos];
            Data[min_pos] = temp;
        }
    }

    int* copyArr = new int[Size];
    for (int i = 0; i < Size; ++i)
    {
        copyArr[i] = Data[i];
    }

    return copyArr;
}

int* Algorithms::HeapSort(int* Data, size_t Size)
{
    return nullptr;
}

void Merge(int* data, size_t start, size_t midpoint, size_t end)
{
    if (end <= start) return;

    // temp destination Array
    int* mergedArr = new int[end - start];

    int leftI = start;
    int rightI = midpoint + 1;

    // mergedArr uses i
    // data uses leftI and rightI
    for (int i = 0; i < end - start; ++i)
    {
        if (leftI > midpoint) // no more left side elements
        {
            mergedArr[i] = data[rightI];
            rightI++;
            continue;
        }

        if (rightI > end) // no more right side elements 
        {
            mergedArr[i] = data[leftI];
            leftI++;
            continue;
        }

        // Insert the smaller of the currently pointed to elements and advance the pointer
        if (data[leftI] < data[rightI])
        {
            mergedArr[i] = data[leftI];
            leftI++;
        }
        else
        {
            mergedArr[i] = data[rightI];
            rightI++;
        }
    }

    for (int i = 0; i < end - start; ++i)
    {
        data[start + i] = mergedArr[i];
    }

    delete[] mergedArr;
}

void MergeSortRecursive(int* Data, size_t begin, size_t end)
{
    size_t size = end - begin;
    if (size <= 1) return;

    size_t midpoint = size / 2; // rounds down

    MergeSortRecursive(Data, begin, midpoint);
    MergeSortRecursive(Data, midpoint + 1, end);
    Merge(Data, begin, midpoint, end);
}

int* Algorithms::MergeSort(int* Data, size_t Size)
{
    int* copyArr = new int[Size];
    for (int i = 0; i < Size; ++i)
    {
        copyArr[i] = Data[i];
    }

    MergeSortRecursive(copyArr, 0, Size - 1);

    return copyArr;
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
