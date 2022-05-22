#pragma once
#include <iostream>

#define DEFAULT_ARRAY_SIZE 2

class DynamicArray
{
public:
    DynamicArray();
    ~DynamicArray();

    void Print();

    void PushBack(int data);
    void Emplace(int index, int data);
    void Insert(int index, int data);

    void RemoveAt(int index);
    int Pop();

    const int GetValueAt(const int index);

    int Size() { return m_Size; };


private:
    
    void IncreaseMemory();


public:
    int* m_Array;
    int  m_Capacity; // How much memory array can currently hold
    int  m_Size; // How many elements are currently saved in Array

};
