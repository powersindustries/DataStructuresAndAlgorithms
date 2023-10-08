#pragma once


#include <iostream>

template <class T>
struct SNode
{
    SNode() : m_NextNode(nullptr) {}

    SNode* m_NextNode;
    T m_Data;
};


template <class T>
struct DNode
{
    DNode() : m_NextNode(nullptr), m_PreviousNode(nullptr) {}

    DNode* m_NextNode;
    DNode* m_PreviousNode;

    T m_Data;
};


template <class T>
class SingleLinkedList
{
public:


    // ----------------------------------------------------------------
    // ----------------------------------------------------------------
    SingleLinkedList()
    {
        m_HeadNode = nullptr;
        m_NodeCount = 0;
    }


    // ----------------------------------------------------------------
    // ----------------------------------------------------------------
    ~SingleLinkedList()
    {
        delete m_HeadNode;
    }


    // ----------------------------------------------------------------
    // ----------------------------------------------------------------
    void Print()
    {
        if (m_HeadNode == nullptr)
        {
            std::cout << "Please insert a node first" << std::endl;
            return;
        }

        SNode<T>* tempNode = m_HeadNode;
        while (tempNode != nullptr)
        {
            std::cout << tempNode->m_Data << " ";

            tempNode = tempNode->m_NextNode;
        }

        std::cout << std::endl;
    }


    // ----------------------------------------------------------------
    // ----------------------------------------------------------------
    void InsertNode(T inData, unsigned int index)
    {
        if (index == 0)
        {
            AddNodeToBeginning(inData);
        }
        else if (index >= m_NodeCount)
        {
            AddNodeToEnd(inData);
        }
        else
        {
            SNode<T>* newNode = new SNode<T>();
            newNode->m_Data = inData;

            SNode<T>* previousNode = m_HeadNode;

            for (unsigned int x = 0; x < index - 1; ++x)
            {
                previousNode = previousNode->m_NextNode;
            }

            newNode->m_NextNode = previousNode->m_NextNode;
            previousNode->m_NextNode = newNode;
            m_NodeCount++;
        }
    }


    // ----------------------------------------------------------------
    // ----------------------------------------------------------------
    void AddNodeToEnd(T inData)
    {
        SNode<T>* newNode = new SNode<T>();
        newNode->m_Data = inData;

        if (m_HeadNode == nullptr)
        {
            m_HeadNode = newNode;
            m_NodeCount++;
            return;
        }

        // Search through nodes until we find the end
        SNode<T>* tempNode = m_HeadNode;
        while (tempNode != nullptr)
        {
            // Once we found the end, add the newNode to the end and break the loop.
            if (tempNode->m_NextNode == nullptr)
            {
                tempNode->m_NextNode = newNode;
                break;
            }

            tempNode = tempNode->m_NextNode;
        }

        m_NodeCount++;
    }


    // ----------------------------------------------------------------
    // ----------------------------------------------------------------
    void AddNodeToBeginning(T inData)
    {
        SNode<T>* newNode = new SNode<T>();
        newNode->m_Data = inData;

        if (m_HeadNode == nullptr)
        {
            m_HeadNode = newNode;
            m_NodeCount++;
            return;
        }

        newNode->m_NextNode = m_HeadNode;
        m_HeadNode = newNode;
        m_NodeCount++;
    }


    // ----------------------------------------------------------------
    // ----------------------------------------------------------------
    void DeleteNode(unsigned int index)
    {
        if (index > m_NodeCount)
        {
            std::cout << "Cannot delete node at this position" << std::endl;
            return;
        }

        SNode<T>* tempNode = m_HeadNode;
        if (index == 0)
        {
            m_HeadNode = m_HeadNode->m_NextNode;

            delete tempNode;

            m_NodeCount--;
            return;
        }

        for (unsigned int x = 1; tempNode != nullptr && x < index - 1; ++x)
        {
            tempNode = tempNode->m_NextNode;
        }

        if (tempNode == nullptr || tempNode->m_NextNode == nullptr)
        {
            return;
        }

        SNode<T>* nextNode = tempNode->m_NextNode->m_NextNode;
        delete tempNode->m_NextNode;
        tempNode->m_NextNode = nextNode;

        m_NodeCount--;
        return;
    }

    int GetNodeCount() { return m_NodeCount; };


public:

    SNode<T>* m_HeadNode;

    unsigned int m_NodeCount;

};


template <class T>
class DoubleLinkedList
{
public:


    // ----------------------------------------------------------------
    // ----------------------------------------------------------------
    DoubleLinkedList()
    {
        m_HeadNode = nullptr;
        m_NodeCount = 0;
    }


    // ----------------------------------------------------------------
    // ----------------------------------------------------------------
    ~DoubleLinkedList()
    {
        delete m_HeadNode;
    }


    // ----------------------------------------------------------------
    // ----------------------------------------------------------------
    void Print()
    {
        if (m_HeadNode == nullptr)
        {
            std::cout << "Please insert a node first" << std::endl;
            return;
        }

        DNode<T>* tempNode = m_HeadNode;
        while (tempNode != nullptr)
        {
            std::cout << tempNode->m_Data << " ";

            tempNode = tempNode->m_NextNode;
        }

        std::cout << std::endl;
    }


    // ----------------------------------------------------------------
    // ----------------------------------------------------------------
    void ReverseList()
    {
        DNode<T>* tempNode = nullptr;
        DNode<T>* currentNode = m_HeadNode;

        while (currentNode != nullptr)
        {
            tempNode = currentNode->m_PreviousNode;

            currentNode->m_PreviousNode = currentNode->m_NextNode;
            currentNode->m_NextNode = tempNode;
            currentNode = currentNode->m_PreviousNode;
        }

        if (tempNode != nullptr)
        {
            m_HeadNode = tempNode->m_PreviousNode;
        }
    }


    // ----------------------------------------------------------------
    // ----------------------------------------------------------------
    void InsertNode(T inData, unsigned int index)
    {
        if (index > m_NodeCount)
        {
            std::cout << "Cant insert, value too large." << std::endl;
            return;
        }

        if (index == 0)
        {
            AddNodeToBeginning(inData);
        }
        else if (index == m_NodeCount)
        {
            AddNodeToEnd(inData);
        }
        else
        {
            DNode<T>* newNode = new DNode<T>();
            newNode->m_Data = inData;

            DNode<T>* tempNode = m_HeadNode;
            unsigned int tempIndex = 0;
            while (tempNode != nullptr)
            {
                if (tempIndex == index)
                {
                    newNode->m_NextNode = tempNode;
                    newNode->m_PreviousNode = tempNode->m_PreviousNode;

                    tempNode->m_PreviousNode->m_NextNode = newNode;
                    tempNode->m_PreviousNode = newNode;

                    m_NodeCount++;
                    return;
                }

                tempNode = tempNode->m_NextNode;
                tempIndex++;
            }
        }
    }


    // ----------------------------------------------------------------
    // ----------------------------------------------------------------
    void AddNodeToEnd(T inData)
    {
        DNode<T>* newNode = new DNode<T>();
        newNode->m_Data = inData;

        if (m_NodeCount == 0)
        {
            m_HeadNode = newNode;
            m_NodeCount++;
            return;
        }

        DNode<T>* tempNode = m_HeadNode;
        while (tempNode != nullptr)
        {
            if (tempNode->m_NextNode == nullptr)
            {
                tempNode->m_NextNode    = newNode;
                newNode->m_PreviousNode = tempNode;
                newNode->m_NextNode     = nullptr;

                m_NodeCount++;
                return;
            }

            tempNode = tempNode->m_NextNode;
        }
    }


    // ----------------------------------------------------------------
    // ----------------------------------------------------------------
    void AddNodeToBeginning(T inData)
    {
        DNode<T>* newNode = new DNode<T>();
        newNode->m_Data = inData;

        if (m_HeadNode == nullptr)
        {
            m_HeadNode = newNode;
        }
        else
        {
            newNode->m_NextNode = m_HeadNode;
            newNode->m_PreviousNode = nullptr;

            m_HeadNode->m_PreviousNode = newNode;
            m_HeadNode = newNode;
        }

        m_NodeCount++;
    }


    // ----------------------------------------------------------------
    // ----------------------------------------------------------------
    void DeleteNode(unsigned int index)
    {
        if (index > m_NodeCount)
        {
            std::cout << "Cannot Remove at this index" << std::endl;
            return;
        }

        DNode<T>* tempNode = m_HeadNode;
        if (index == 0)
        {
            m_HeadNode = m_HeadNode->m_NextNode;
            m_HeadNode->m_PreviousNode = nullptr;

            delete tempNode;
            m_NodeCount--;
            return;
        }

        unsigned int tempIndex = 0;
        while (tempNode != nullptr)
        {
            if (tempIndex == index)
            {
                tempNode->m_NextNode->m_PreviousNode = tempNode->m_PreviousNode;
                tempNode->m_PreviousNode->m_NextNode = tempNode->m_NextNode;

                delete tempNode;
                m_NodeCount--;
                return;
            }

            tempNode = tempNode->m_NextNode;
            tempIndex++;
        }
    }


public:

    DNode<T>* m_HeadNode;

    unsigned int m_NodeCount;

};
