#include "Stack.h"
#include <iostream>


// ----------------------------------------------------------------
// ----------------------------------------------------------------
Stack::Stack()
{
    m_TopNode = nullptr;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
Stack::~Stack()
{
    delete m_TopNode;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void Stack::Push(int data)
{
    StackNode* newNode = new StackNode();
    newNode->m_Data = data;

    if (m_TopNode == nullptr)
    {
        m_TopNode = newNode;
        return;
    }

    newNode->m_NextNode = m_TopNode;
    m_TopNode = newNode;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void Stack::Pop()
{
    if (m_TopNode == nullptr)
    {
        std::cout << "Stack Under-Flow or Empty" << std::endl;
        return;
    }

    StackNode* currentNode = m_TopNode;
    m_TopNode = m_TopNode->m_NextNode;
    delete currentNode;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void Stack::Print()
{
    if (m_TopNode == nullptr)
    {
        std::cout << "Empty Stack Please push elements" << std::endl;
        return;
    }

    StackNode* tempNode = m_TopNode;
    while (tempNode != nullptr)
    {
        std::cout << tempNode->m_Data << " ";
        tempNode = tempNode->m_NextNode;
    }
    std::cout << std::endl;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
ArrayStack::ArrayStack()
{
    m_Array = new int[128];
    m_TopIndex = -1;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
ArrayStack::~ArrayStack()
{
    delete m_Array;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void ArrayStack::Push(int data)
{
    if (m_TopIndex > SIZE_MAX)
    {
        std::cout << "Stack Over-Flows" << std::endl;
        return;
    }

    m_TopIndex = m_TopIndex + 1;
    m_Array[m_TopIndex] = data;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void ArrayStack::Pop()
{
    if (m_TopIndex < 0)
    {
        std::cout << "Stack Under-Flow" << std::endl;
        return;
    }

    m_TopIndex--;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
int ArrayStack::Peek()
{
    return m_Array[m_TopIndex];
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void ArrayStack::Print()
{
    if (m_TopIndex < 0)
    {
        std::cout << "Please Fill the elements first" << std::endl;
        return;
    }

    for (int x = m_TopIndex; x >= 0; --x)
    {
        std::cout << m_Array[x] << " ";
    }
    std::cout << std::endl;
}