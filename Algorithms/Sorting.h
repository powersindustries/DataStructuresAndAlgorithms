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

    void QuickSort(int array[], int lowIndex, int highIndex);


private:

    void MergeSortMergeArrays(int array[], int lowValue, int midValue, int highValue);

    int QuickSortPartition(int array[], int lowIndex, int highIndex);

};


