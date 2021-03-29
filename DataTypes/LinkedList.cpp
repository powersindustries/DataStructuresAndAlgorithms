#include "LinkedList.h"
#include <iostream>


// ----------------------------------------------------------------
// ----------------------------------------------------------------
LLNode::LLNode(int data)
{
    m_Data = data;
    m_NextNode = NULL;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
LinkedList::LinkedList()
{
    m_HeadNode = NULL;
    m_TailNode = NULL;
    m_ElementCount = 0;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void LinkedList::AddNodeToEnd(int data)
{
    LLNode* newNode = new LLNode(data);

    if (m_HeadNode == NULL)
    {
        m_HeadNode = newNode;
        m_TailNode = newNode;
        m_ElementCount++;
        return;
    }

    m_TailNode->m_NextNode = newNode;
    m_TailNode = newNode;
    m_ElementCount++;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void LinkedList::AddNodeToBeginning(int data)
{
    LLNode* newNode = new LLNode(data);

    if (m_HeadNode == NULL)
    {
        m_HeadNode = newNode;
        m_TailNode = newNode;
        m_ElementCount++;
        return;
    }

    newNode->m_NextNode = m_HeadNode;
    m_HeadNode = newNode;
    m_ElementCount++;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void LinkedList::InsertNode(int data, int index)
{
    if (index < 0)
    {
        std::cout << "Cannot Insert node at this position" << std::endl;
        return;
    }

    if (index == 0)
    {
        AddNodeToBeginning(data);
    }
    else if (index >= m_ElementCount)
    {
        AddNodeToEnd(data);
    }
    else
    {
        LLNode* newNode = new LLNode(data);
        LLNode* previousNode = m_HeadNode;

        for (int x = 0; x < index - 1; ++x)
        {
            previousNode = previousNode->m_NextNode;
        }

        newNode->m_NextNode = previousNode->m_NextNode;
        previousNode->m_NextNode = newNode;
        m_ElementCount++;
    }
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void LinkedList::RemoveNode(int index)
{
    if (index < 1)
    {
        std::cout << "Cannot Insert node at this position" << std::endl;
        return;
    }

    if (index > m_ElementCount)
    {
        std::cout << "Cannot Insert node at this position" << std::endl;
        return;
    }

    LLNode* tempNode = m_HeadNode;
    if (index == 1)
    {
        m_HeadNode = m_HeadNode->m_NextNode;
        free(tempNode);
        m_ElementCount++;
        return;
    }

    for (int x = 1; tempNode != NULL && x < index - 1; ++x)
    {
        tempNode = tempNode->m_NextNode;
    }

    if (tempNode == NULL || tempNode->m_NextNode == NULL)
    {
        return;
    }

    LLNode* nextNode = tempNode->m_NextNode->m_NextNode;
    free(tempNode->m_NextNode);
    tempNode->m_NextNode = nextNode;
    m_ElementCount++;

    return;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void LinkedList::PrintLinkedList()
{
    if (m_HeadNode == NULL)
    {
        std::cout << "Please Insert element first" << std::endl;
        return;
    }

    LLNode* tempNode = m_HeadNode;
    for (int x = 0; x < m_ElementCount; ++x)
    {
        std::cout << tempNode->m_NextNode << ", ";
        tempNode = tempNode->m_NextNode;
    }

    std::cout << std::endl;
}