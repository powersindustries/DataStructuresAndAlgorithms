#pragma once
#include <iostream>

#define DEQUEU_MAX 128

template <class T>
class Deque
{
public:


    // ----------------------------------------------------------------
    // ----------------------------------------------------------------
	Deque<T>(int inSize)
        : m_Array(nullptr)
    {
        m_iSize = inSize;

        m_Array = new T[DEQUEU_MAX];

        m_iBackIndex = 0;
        m_iFrontIndex = -1;
    }


    // ----------------------------------------------------------------
    // ----------------------------------------------------------------
	bool empty()
    {
        return m_iFrontIndex == -1;
    }


    // ----------------------------------------------------------------
    // ----------------------------------------------------------------
	bool full()
    {
        return (m_iFrontIndex == 0 && m_iBackIndex == (m_iSize - 1)) || (m_iFrontIndex == (m_iBackIndex + 1));
    }


    // ----------------------------------------------------------------
    // ----------------------------------------------------------------
	void push_front(const T inData)
    {
        if (full())
        {
            std::cout << "Deque is full." << std::endl;
            return;
        }

        if (m_iFrontIndex == -1)
        {
            m_iFrontIndex = 0;
            m_iBackIndex = 0;
        }
        else if (m_iFrontIndex == 0)
        {
            m_iFrontIndex = m_iSize - 1;
        }
        else
        {
            m_iFrontIndex = m_iFrontIndex - 1;
        }

        m_Array[m_iFrontIndex] = inData;
    }


    // ----------------------------------------------------------------
    // ----------------------------------------------------------------
	void push_back(const T inData)
    {
        if (full())
        {
            std::cout << "Deque is full." << std::endl;
            return;
        }

        if (m_iFrontIndex == -1)
        {
            m_iFrontIndex = 0;
            m_iBackIndex = 0;
        }
        else if (m_iBackIndex == m_iSize - 1)
        {
            m_iBackIndex = 0;
        }
        else
        {
            m_iBackIndex = m_iBackIndex + 1;
        }

        m_Array[m_iBackIndex] = inData;
    }


    // ----------------------------------------------------------------
    // ----------------------------------------------------------------
	void pop_front()
    {
        if (empty())
        {
            std::cout << "Deque is empty." << std::endl;
            return;
        }

        if (m_iBackIndex == m_iFrontIndex)
        {
            m_iBackIndex = -1;
            m_iFrontIndex = -1;
        }
        else if (m_iFrontIndex == m_iSize - 1)
        {
            m_iFrontIndex = 0;
        }
        else
        {
            m_iFrontIndex = m_iFrontIndex + 1;
        }
    }


    // ----------------------------------------------------------------
    // ----------------------------------------------------------------
	void pop_back()
    {
        if (empty())
        {
            std::cout << "Deque is empty." << std::endl;
            return;
        }

        if (m_iFrontIndex == m_iBackIndex)
        {
            m_iFrontIndex = -1;
            m_iBackIndex = -1;
        }
        else if (m_iBackIndex == 0)
        {
            m_iBackIndex = m_iSize - 1;
        }
        else
        {
            m_iBackIndex = m_iBackIndex - 1;
        }
    }


    // ----------------------------------------------------------------
    // ----------------------------------------------------------------
	T* front()
    {
        if (empty())
        {
            std::cout << "Deque is empty." << std::endl;
            return nullptr;
        }

        return &m_Array[m_iFrontIndex];
    }


    // ----------------------------------------------------------------
    // ----------------------------------------------------------------
	T* back()
    {
        if (empty() || m_iBackIndex < 0)
        {
            std::cout << "Deque is empty." << std::endl;
            return nullptr;
        }

        return &m_Array[m_iBackIndex];
    }


private:

	T* m_Array;

	int m_iSize;
	int m_iBackIndex;
	int m_iFrontIndex;

};
