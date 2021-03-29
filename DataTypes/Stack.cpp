#include "Stack.h"
#include <iostream>


// ----------------------------------------------------------------
// ----------------------------------------------------------------
StackNode::StackNode(int data)
{
    m_Data = data;
    m_NextNode = NULL;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
Stack::Stack()
{
    m_TopNode = NULL;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void Stack::Push(int data)
{
    StackNode* newNode = new StackNode(data);

    if (m_TopNode == NULL)
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
    if (m_TopNode == NULL)
    {
        std::cout << "Stack Under-Flow or Empty" << std::endl;
        return;
    }

    StackNode* currentNode = m_TopNode;
    std::cout << m_TopNode->m_Data << std::endl;
    m_TopNode = m_TopNode->m_NextNode;
    free(currentNode);
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void Stack::Print()
{
    if (m_TopNode == NULL)
    {
        std::cout << "Empty Stack Please push elements" << std::endl;
        return;
    }

    StackNode* tempNode = m_TopNode;
    while (tempNode != NULL)
    {
        std::cout << tempNode->m_Data << ", ";
        tempNode = tempNode->m_NextNode;
    }
    std::cout << std::endl;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
ArrayStack::ArrayStack()
{
    m_Top = -1;
    m_Array = new int[128];
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void ArrayStack::Push(int data)
{
    if (m_Top > SIZE_MAX)
    {
        std::cout << "Stack Over-Flows" << std::endl;
        return;
    }

    m_Top = m_Top + 1;
    m_Array[m_Top] = data;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
int ArrayStack::Pop()
{
    if (m_Top == -1)
    {
        std::cout << "Stack Under-Flow" << std::endl;
        return 0;
    }

    int data = m_Array[m_Top];
    m_Top--;
    return data;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
int ArrayStack::Peek()
{
    return m_Array[m_Top];
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void ArrayStack::Display()
{
    if (m_Top >= 0)
    {
        std::cout << "The Stack elements are: " << std::endl;

        for (int x = m_Top; x >= 0; --x)
        {
            std::cout << m_Array[x] << ", ";
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "Please Fill the elements first" << std::endl;
        return;
    }
}