#include "DynamicArray.h"
#include <iostream>
#include <map>
#include <vector>


// ----------------------------------------------------------------
// ----------------------------------------------------------------
DynamicArray::DynamicArray()
{
    m_Array        = new int[2];
    m_Capacity     = 2;
    m_ElementCount = 0;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void DynamicArray::Push(int data)
{
    if (m_ElementCount == m_Capacity)
    {
        int* tempArray = new int[2 * m_Capacity];

        for (int x = 0; x < m_Capacity; ++x)
        {
            tempArray[x] = m_Array[x];
        }

        delete[] m_Array;

        m_Capacity = m_Capacity * 2;
        m_Array = tempArray;
    }

    m_Array[m_ElementCount] = data;
    m_ElementCount++;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void DynamicArray::Push(int data, int index)
{
    if (index == m_Capacity)
    {
        Push(data);
        return;
    }

    m_Array[index] = data;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void DynamicArray::InsertElement(int data, int index)
{
    if (index == m_Capacity)
    {
        Push(data);
    }

    for (int x = m_ElementCount; x > index; --x)
    {
        m_Array[x] = m_Array[x - 1];
    }

    m_Array[index] = data;
    m_ElementCount++;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void DynamicArray::Pop(int index)
{
    if (index > -1 && index < m_ElementCount)
    {
        m_ElementCount--;

        for (int x = index; x < m_ElementCount; ++x)
        {
            m_Array[x] = m_Array[x + 1];
        }
    }
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
int DynamicArray::Pop()
{
    int currentElement = m_Array[m_ElementCount - 1];
    m_ElementCount--;

    return currentElement;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
int DynamicArray::GetValueByIndex(int index)
{
    if (index > -1 && index < m_Capacity)
    {
        return m_Array[index];
    }

    return NULL;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
int DynamicArray::Length()
{
    return m_ElementCount;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void DynamicArray::PrintArrayValues(int array[], int size)
{
    for (int x = 0; x < size; ++x)
    {
        std::cout << array[x] << ", ";
    }
    std::cout << std::endl;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void DynamicArray::Print()
{
    for (int x = 0; x < m_ElementCount; ++x)
    {
        std::cout << m_Array[x] << "\t";
    }
    std::cout << std::endl;
}
