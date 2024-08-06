#include "Algorithms.h"

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

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

int getParent(int child) // get the parent of an element
{
    return (child - 1) / 2;
}

int getLeftChild(int parent) // get the left child of the parent
{
    return (parent * 2) + 1;
}

int getRightChild(int parent) // get the right child of the parent
{
    return (parent * 2) + 2;
}

void siftdown(int* Data, int root, int end)
{
    while (getLeftChild(root) < end)
    {
        int child = getLeftChild(root);

        if (getRightChild(root) < end && Data[getLeftChild(root)] > Data[getRightChild(root)]) // select the smaller of the two children
        {
            child = getRightChild(root);
        }

        if (Data[root] > Data[child]) //  if root is larger than the child element, swap them and continue
        {
            swap(Data[root], Data[child]);
            root = child;
        }
        else
        {
            return;
        }
    }
}

void heapify(int* Data, int count) 
{
    int start = getParent(count - 1) + 1;

    while (start > 0)
    {
        start--;

        siftdown(Data, start, count);
    }
}

int* Algorithms::HeapSort(int* Data, size_t Size)
{
    heapify(Data, Size);

    size_t end = Size;
    while (end > 1)
    {
        end--;
        swap(Data[end], Data[0]);
        siftdown(Data, 0, Size);
    }

    int* copyArr = new int[Size];
    for (int i = 0; i < Size; ++i)
    {
        copyArr[i] = Data[i];
    }

    return copyArr;
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

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low; // temp pivot index

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }

    swap(arr[i], arr[high]);
    return i;
}

void quicksort_recursion(int* Data, size_t begin, size_t end)
{
    if (begin < end) // only apply recursion if beginning is bigger than the end index
    {
        int pivot_index = partition(Data, begin, end); // where the split/partition will occur

        if (pivot_index > 0)
        {
            quicksort_recursion(Data, begin, pivot_index - 1); // left side of the partition
        }

        quicksort_recursion(Data, pivot_index + 1, end); // right side of the partition
    }
}

int* Algorithms::QuickSort(int* Data, size_t Size)
{
    int* copyArr = new int[Size];
    for (int i = 0; i < Size; ++i)
    {
        copyArr[i] = Data[i];
    }
    
    quicksort_recursion(copyArr, 0, Size - 1);

    return copyArr;
}

int* Algorithms::BinSort(int* Data, size_t Size)
{
    return nullptr;
}

int* Algorithms::LinierSearch(int* Data, size_t Size, int target)
{
    for (int i = 0; i < Size; i++) // loop through array
    {
        if (Data[i] == target) // if the declared element is found, return it
        {
            return &Data[i];
        }
    }
}

int* Algorithms::BinarySearch(int* Data, size_t Size, int target)
{
    return nullptr;
}
