#pragma once


class Sorting
{
public:

    Sorting();

    void BubbleSort(int array[], int size);
    void BubbleSortOptimized(int array[], int size);

    void SelectionSort(int array[], int size);

    void InsertionSort(int array[], int size);

    void MergeSort(int array[], int lowValue, int highValue);

    int QuickSort(int a[], int lowIndex, int highIndex);

private:
    void SelectionSortSwap(int* value1, int* value2);

    void MergeSortMergeArrays(int array[], int lowValue, int midValue, int highValue);
    
    int QuickSortPartition(int a[], int lowIndex, int highIndex);
    void PartitionSwap(int* val1, int* val2);

};


