#include "Deque.h"

#define DEQUEU_MAX 128


// ----------------------------------------------------------------
// ----------------------------------------------------------------
Deque::Deque(int inSize)
	: m_Array(nullptr)
{
	m_iSize = inSize;

	m_Array = new int[128];

	m_iBackIndex = 0;
	m_iFrontIndex = -1;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
bool Deque::empty()
{
	return m_iFrontIndex == -1;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
bool Deque::full()
{
	return (m_iFrontIndex == 0 && m_iBackIndex == (m_iSize - 1)) || (m_iFrontIndex == (m_iBackIndex + 1));
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void Deque::push_front(const int inData)
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
void Deque::push_back(const int inData)
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
void Deque::pop_front()
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
void Deque::pop_back()
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
int* Deque::front()
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
int* Deque::back()
{
	if (empty() || m_iBackIndex < 0)
	{
		std::cout << "Deque is empty." << std::endl;
		return nullptr;
	}

	return &m_Array[m_iBackIndex];
}
