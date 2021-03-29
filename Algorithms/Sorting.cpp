#include "Sorting.h"
#include <iostream>


// ----------------------------------------------------------------
// ----------------------------------------------------------------
Sorting::Sorting()
{
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void Sorting::BubbleSort(int array[], int size)
{
    for (int x = 0; x < size - 1; ++x)
    {
        for (int y = 0; y < size - 1 - x; ++y)
        {
            if (array[y] > array[y + 1])
            {
                int tempValue = array[y];
                array[y] = array[y + 1];
                array[y + 1] = tempValue;
            }
        }
    }
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void Sorting::BubbleSortOptimized(int array[], int size)
{
    bool swapped;

    for (int x = 0; x < size - 1; ++x)
    {
        swapped = false;

        for (int y = 0; y < size - 1 - x; ++y)
        {
            if (array[y] > array[y + 1])
            {
                int tempValue = array[y];
                array[y] = array[y + 1];
                array[y + 1] = tempValue;
                swapped = true;
            }
        }

        if (swapped == false)
        {
            break;
        }
    }
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void Sorting::SelectionSort(int array[], int size)
{
    for (int x = 0; x < size - 1; ++x)
    {
        int minIndex = x;

        for (int y = x + 1; y < size; ++y)
        {
            if (array[y] < array[minIndex])
            {
                minIndex = y;
            }

            SelectionSortSwap(&array[minIndex], &array[x]);
        }
    }
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void Sorting::SelectionSortSwap(int* value1, int* value2)
{
    int tempValue = *value1;
    *value1 = *value2;
    *value2 = tempValue;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void Sorting::InsertionSort(int array[], int size)
{
    for (int x = 1; x < size; ++x)
    {
        int currentValue = array[x];
        int index = x - 1;

        while (index >= 0 && array[index] > currentValue)
        {
            array[index + 1] = array[index];
            index = index - 1;
        }

        array[index + 1] = currentValue;
    }
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void Sorting::MergeSortMergeArrays(int array[], int lowValue, int midValue, int highValue)
{
    const int size1 = midValue - lowValue + 1;
    const int size2 = highValue - midValue;

    int* leftArr  = new int[size1];
    int* rightArr = new int[size2];

    int index      = lowValue; // index traversing in original Array
    int indexLeft  = 0; // index traversing in leftArray
    int indexRight = 0; // index traversing in rightArray

    for (int i = 0; i < size1; i++)
    {
        leftArr[i] = array[lowValue + i];
    }
    
    for (int j = 0; j < size2; j++)
    {
        rightArr[j] = array[midValue + 1 + j];
    }

    while (indexLeft < size1 && indexRight < size2)
    {
        if (leftArr[indexLeft] <= rightArr[indexRight])
        {
            array[index] = leftArr[indexLeft];
            indexLeft++;
        }
        else
        {
            array[index] = rightArr[indexRight];
            indexRight++;
        }
        index++;
    }
    
    while (indexLeft < size1)
    {
        array[index] = leftArr[indexLeft];
        indexLeft++;
        index++;
    }
    
    while (indexRight < size2)
    {
        array[index] = rightArr[indexRight];
        indexRight++;
        index++;
    }
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void Sorting::MergeSort(int array[], int lowValue, int highValue)
{
    if (lowValue < highValue)
    {
        int midValue = (lowValue + (highValue - 1)) / 2;

        MergeSort(array, lowValue, midValue);
        MergeSort(array, midValue + 1, highValue);

        MergeSortMergeArrays(array, lowValue, midValue, highValue);
    }
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
int Sorting::QuickSort(int a[], int lowIndex, int highIndex)
{
    int pIndex = 0;

    if (lowIndex < highIndex)
    {
        pIndex = QuickSortPartition(a, lowIndex, highIndex);
        QuickSort(a, lowIndex, highIndex);
        QuickSort(a, pIndex + 1, highIndex);
    }

    return 0;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
int Sorting::QuickSortPartition(int a[], int lowIndex, int highIndex)
{
    int pivot = highIndex;
    int index = lowIndex;

    for (int x = lowIndex; x < highIndex; ++x)
    {
        if (a[x] < a[pivot])
        {
            PartitionSwap(&a[x], &a[index]);
            index++;
        }
    }

    PartitionSwap(&a[pivot], &a[index]);
    return index;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void Sorting::PartitionSwap(int* val1, int* val2)
{
    int tempValue = *val1;
    *val1 = *val2;
    *val2 = tempValue;
}
