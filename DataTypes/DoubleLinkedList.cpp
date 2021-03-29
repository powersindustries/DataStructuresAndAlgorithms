#include "DoubleLinkedList.h"
#include <iostream>


// ----------------------------------------------------------------
// ----------------------------------------------------------------
DoubleLinkedList::DoubleLinkedList()
{
    m_HeadNode = NULL;
    m_TailNode = NULL;
    m_ElementCount = 0;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void DoubleLinkedList::AddNodeToEnd(int data)
{
    DLLNode* newNode = new DLLNode;

    newNode->m_Data = data;
    newNode->m_NextNode = newNode->m_PreviousNode = NULL;

    if (m_ElementCount == 0)
    {
        m_HeadNode = newNode;
        m_TailNode = newNode;
        m_ElementCount++;
    }
    else
    {
        m_TailNode->m_NextNode = newNode;
        newNode->m_NextNode = NULL;
        newNode->m_PreviousNode = m_TailNode;

        m_TailNode = newNode;
        m_ElementCount++;
    }
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void DoubleLinkedList::AddNodeToBeginning(int data)
{
    if (m_ElementCount == 0)
    {
        AddNodeToBeginning(data);
    }
    else
    {
        DLLNode* newNode = new DLLNode;
        newNode->m_Data = data;
        newNode->m_NextNode = newNode->m_PreviousNode = NULL;
        newNode->m_NextNode = m_HeadNode;

        m_HeadNode->m_PreviousNode = newNode;
        m_HeadNode = newNode;

        m_ElementCount++;
    }
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void DoubleLinkedList::InsertNode(int data, int index)
{
    if (index > m_ElementCount)
    {
        std::cout << "Cant insert, value too large." << std::endl;
        return;
    }
    else if (index < 1)
    {
        std::cout << "Position is negative" << std::endl;
        return;
    }
    else if (index == 1)
    {
        AddNodeToBeginning(data);
    }
    else if (index == m_ElementCount)
    {
        AddNodeToEnd(data);
    }
    else
    {
        DLLNode* newNode = new DLLNode;
        newNode->m_Data = data;
        newNode->m_PreviousNode = NULL;

        DLLNode* tempNode = new DLLNode;
        for (int x = m_ElementCount - 1; x >= index; --x)
        {
            tempNode = tempNode->m_PreviousNode;
        }

        newNode->m_NextNode = tempNode;
        newNode->m_PreviousNode = tempNode->m_PreviousNode;
        tempNode->m_PreviousNode->m_NextNode = newNode;

        m_ElementCount++;
    }
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void DoubleLinkedList::RemoveNode(int index)
{
    if (index < 1 || index > m_ElementCount)
    {
        std::cout << "Cannot Remove at this index" << std::endl;
        return;
    }
    else
    {
        DLLNode* tempNode = m_HeadNode;
        if (index == 1)
        {
            m_HeadNode = m_HeadNode->m_NextNode;
            free(tempNode);
            m_ElementCount--;
            return;
        }
        else
        {
            DLLNode* tempNode = m_HeadNode;

            if (index == 1)
            {
                m_HeadNode = m_HeadNode->m_NextNode;
                free(tempNode);
                m_ElementCount--;
                return;
            }

            for (int x = 1; x < index; ++x)
            {
                tempNode = tempNode->m_NextNode;
            }

            if (tempNode->m_NextNode != NULL)
            {
                tempNode->m_NextNode->m_PreviousNode = tempNode->m_PreviousNode;
                tempNode->m_PreviousNode->m_NextNode = tempNode->m_NextNode;
                free(tempNode);
                m_ElementCount--;
            }
            else
            {
                tempNode->m_PreviousNode->m_NextNode = NULL;
                m_TailNode = m_TailNode->m_PreviousNode;
                free(tempNode);
                m_ElementCount--;
            }
        }
    }
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void DoubleLinkedList::PrintLinkedList()
{
    if (m_HeadNode == NULL)
    {
        std::cout << "Please Insert element first" << std::endl;
        return;
    }

    DLLNode* tempNode = m_HeadNode;
    for (int x = 0; x < m_ElementCount; ++x)
    {
        std::cout << tempNode->m_NextNode << ", ";
        tempNode = tempNode->m_NextNode;
    }

    std::cout << std::endl;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void DoubleLinkedList::ReverseList()
{
    DLLNode* tempNode = NULL;
    DLLNode* currentNode = m_HeadNode;

    while (currentNode != NULL)
    {
        tempNode = currentNode->m_PreviousNode;

        currentNode->m_PreviousNode = currentNode->m_NextNode;
        currentNode->m_NextNode = tempNode;
        currentNode = currentNode->m_PreviousNode;
    }

    if (tempNode != NULL)
    {
        m_HeadNode = tempNode->m_PreviousNode;
    }
}