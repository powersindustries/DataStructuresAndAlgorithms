#include "DynamicArray.h"
#include <iostream>
#include <map>
#include <vector>


// ----------------------------------------------------------------
// ----------------------------------------------------------------
DynamicArray::DynamicArray()
{
    m_Array = new int[DEFAULT_ARRAY_SIZE];

    m_Capacity = DEFAULT_ARRAY_SIZE;
    m_Size = 0;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
DynamicArray::~DynamicArray()
{
    delete[] m_Array;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void DynamicArray::PushBack(int data)
{
    if (m_Size == m_Capacity)
    {
        IncreaseMemory();
    }

    m_Array[m_Size] = data;
    m_Size++;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void DynamicArray::Emplace(int index, int data)
{
    if (index == m_Capacity)
    {
        PushBack(data);
        return;
    }

    if ((m_Size + 1) >= m_Capacity)
    {
        IncreaseMemory();
    }

    for (int x = m_Size; x > index; --x)
    {
        m_Array[x] = m_Array[x - 1];
    }

    m_Array[index] = data;
    m_Size++;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void DynamicArray::Insert(int index, int data)
{
    if (index == m_Capacity)
    {
        PushBack(data);
        return;
    }

    m_Array[index] = data;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void DynamicArray::RemoveAt(int index)
{
    if (index > -1 && index < m_Size)
    {
        m_Size--;

        for (int x = index; x < m_Size; ++x)
        {
            m_Array[x] = m_Array[x + 1];
        }
    }
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
int DynamicArray::Pop()
{
    int currentElement = m_Array[m_Size - 1];
    m_Size--;

    return currentElement;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
const int DynamicArray::GetValueAt(const int index)
{
    if (index > -1 && index < m_Capacity)
    {
        return m_Array[index];
    }

    return NULL;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void DynamicArray::IncreaseMemory()
{
    const int newCapacity = m_Capacity * DEFAULT_ARRAY_SIZE;

    std::cout << "NOTE: Size Increased from " << m_Capacity << " to " << newCapacity << std::endl;

    int* tempArray = new int[newCapacity];
    for (int x = 0; x < m_Capacity; ++x)
    {
        tempArray[x] = m_Array[x];
    }

    m_Capacity = newCapacity;

    delete[] m_Array;
    m_Array = tempArray;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void DynamicArray::Print()
{
    for (int x = 0; x < m_Size; ++x)
    {
        std::cout << m_Array[x] << " ";
    }
    std::cout << std::endl;
}
