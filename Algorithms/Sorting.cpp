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
        }

        int tempValue = array[minIndex];
        array[minIndex] = array[x];
        array[x] = tempValue;
    }
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
void Sorting::MergeSortMergeArrays(int array[], int lowValue, int midValue, int highValue)
{
    const int size1 = midValue - lowValue + 1;
    const int size2 = highValue - midValue;

    int* leftArray  = new int[size1];
    int* rightArray = new int[size2];

    int index      = lowValue; // index for original Array
    int indexLeft  = 0;        // index for leftArray
    int indexRight = 0;        // index for rightArray

    for (int i = 0; i < size1; i++)
    {
        leftArray[i] = array[lowValue + i];
    }
    
    for (int j = 0; j < size2; j++)
    {
        rightArray[j] = array[midValue + 1 + j];
    }

    while (indexLeft < size1 && indexRight < size2)
    {
        if (leftArray[indexLeft] <= rightArray[indexRight])
        {
            array[index] = leftArray[indexLeft];
            indexLeft++;
        }
        else
        {
            array[index] = rightArray[indexRight];
            indexRight++;
        }
        index++;
    }
    
    while (indexLeft < size1)
    {
        array[index] = leftArray[indexLeft];
        indexLeft++;
        index++;
    }
    
    while (indexRight < size2)
    {
        array[index] = rightArray[indexRight];
        indexRight++;
        index++;
    }

    delete[] leftArray;
    delete[] rightArray;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void Sorting::QuickSort(int array[], int lowIndex, int highIndex)
{
    if (lowIndex < highIndex)
    {
        int pIndex = QuickSortPartition(array, lowIndex, highIndex);
        QuickSort(array, lowIndex, pIndex - 1);
        QuickSort(array, pIndex + 1, highIndex);
    }
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
int Sorting::QuickSortPartition(int array[], int lowIndex, int highIndex)
{
    int pivot = highIndex;
    int index = lowIndex;

    for (int x = lowIndex; x < highIndex; ++x)
    {
        if (array[x] < array[pivot])
        {
            // Update pivot index
            int tempValue = array[x];
            array[x] = array[index];
            array[index] = tempValue;
            
            index++;
        }
    }
    
    // Swap pivot with index
    int tempValue = array[pivot];
    array[pivot] = array[index];
    array[index] = tempValue;

    return index;
}
