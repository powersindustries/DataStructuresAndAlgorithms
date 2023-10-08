#pragma once
#include <iostream>

#define DEFAULT_ARRAY_SIZE 2

template <class T>
class DynamicArray
{
public:


    // ----------------------------------------------------------------
    // ----------------------------------------------------------------
    DynamicArray()
    {
        m_Array = new T[DEFAULT_ARRAY_SIZE];

        m_Capacity = DEFAULT_ARRAY_SIZE;
        m_Size = 0;
    }


    // ----------------------------------------------------------------
    // ----------------------------------------------------------------
    ~DynamicArray()
    {
        delete[] m_Array;
    }


    // ----------------------------------------------------------------
    // ----------------------------------------------------------------
    void Print()
    {
        for (int x = 0; x < m_Size; ++x)
        {
            std::cout << m_Array[x] << " ";
        }
        std::cout << std::endl;
    }


    // ----------------------------------------------------------------
    // ----------------------------------------------------------------
    void PushBack(T inData)
    {
        if (m_Size == m_Capacity)
        {
            IncreaseMemory();
        }

        m_Array[m_Size] = inData;
        m_Size++;
    }


    // ----------------------------------------------------------------
    // ----------------------------------------------------------------
    void Emplace(int index, T inData)
    {
        if (index == m_Capacity)
        {
            PushBack(inData);
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

        m_Array[index] = inData;
        m_Size++;
    }


    // ----------------------------------------------------------------
    // ----------------------------------------------------------------
    void Insert(int index, T inData)
    {
        if (index == m_Capacity)
        {
            PushBack(inData);
            return;
        }

        m_Array[index] = inData;
    }


    // ----------------------------------------------------------------
    // ----------------------------------------------------------------
    void RemoveAt(int index)
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
    T Pop()
    {
        int currentElement = m_Array[m_Size - 1];
        m_Size--;

        return currentElement;
    }


    // ----------------------------------------------------------------
    // ----------------------------------------------------------------
    const T GetValueAt(const int index)
    {
        if (index > -1 && index < m_Capacity)
        {
            return m_Array[index];
        }

        return T();
    }


    // ----------------------------------------------------------------
    // ----------------------------------------------------------------
    int Size() { return m_Size; };


private:


    // ----------------------------------------------------------------
    // ----------------------------------------------------------------
    void IncreaseMemory()
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


public:

    T* m_Array;
    int  m_Capacity; // How much memory array can currently hold
    int  m_Size; // How many elements are currently saved in Array

};
