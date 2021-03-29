#pragma once
#include <iostream>


class DynamicArray
{
public:
    DynamicArray();

    void PrintArrayValues(int array[], int size);
    void Print();

    void Push(int data);
    void Push(int data, int index);

    void InsertElement(int data, int index);

    void Pop(int index);
    int Pop();

    int GetValueByIndex(int index);

    int Length();

public:
    int* m_Array;
    int  m_Capacity; // How much memory space array can currently hold
    int  m_ElementCount; // How many elements are currently saved in Array

};
