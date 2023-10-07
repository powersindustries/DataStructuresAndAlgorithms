#include "Queue.h"

#define MAX_CAPACITY 128

Queue::Queue()
{
    m_Array = new int[MAX_CAPACITY];
    m_iHead = -1;
    m_iTail = -1;
}

Queue::~Queue()
{
    delete[] m_Array;
}

bool Queue::empty() const
{
    return m_iHead == -1;
}

void Queue::enqueu(int inData)
{
    if (full())
    {
        return;
    }

    m_Array[m_iTail] = inData;
    if (m_iTail == MAX_CAPACITY - 1)
    {
        m_iTail = 0;
    } else
    {
        m_iTail++;
    }
}

void Queue::dequeue()
{
    if (full())
    {
        return;
    }

    if (m_iHead == MAX_CAPACITY - 1)
    {
        m_iHead = 0;
    } else
    {
        m_iHead++;
    }
}

int Queue::front()
{
    return m_Array[m_iHead];
}

int Queue::back()
{
    return m_Array[m_iTail - 1];
}

bool Queue::full() const
{
    return (m_iHead == m_iTail + 1) || (m_iHead == 1 && m_iTail == MAX_CAPACITY);
}
