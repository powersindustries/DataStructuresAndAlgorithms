#pragma once

#include <iostream>

template <class T>
struct StackNode
{
    StackNode() : m_NextNode(nullptr) {}

    StackNode* m_NextNode;
    T m_Data;
};

template <class T>
class Stack
{
public:


    // ----------------------------------------------------------------
    // ----------------------------------------------------------------
    Stack()
    {
        m_TopNode = nullptr;
    }


    // ----------------------------------------------------------------
    // ----------------------------------------------------------------
    ~Stack()
    {
        delete m_TopNode;
    }


    // ----------------------------------------------------------------
    // ----------------------------------------------------------------
    void Print()
    {
        if (m_TopNode == nullptr)
        {
            std::cout << "Empty Stack Please push elements" << std::endl;
            return;
        }

        StackNode<T> *tempNode = m_TopNode;
        while (tempNode != nullptr)
        {
            std::cout << tempNode->m_Data << " ";
            tempNode = tempNode->m_NextNode;
        }
        std::cout << std::endl;
    }


    // ----------------------------------------------------------------
    // ----------------------------------------------------------------
    void Push(T inData)
    {
        StackNode<T>* newNode = new StackNode<T>();
        newNode->m_Data = inData;

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
    void Pop()
    {
        if (m_TopNode == nullptr)
        {
            std::cout << "Stack Under-Flow or Empty" << std::endl;
            return;
        }

        StackNode<T>* currentNode = m_TopNode;
        m_TopNode = m_TopNode->m_NextNode;
        delete currentNode;
    }


public:

    StackNode<T>* m_TopNode;

};

template <class T>
class ArrayStack
{
public:


    // ----------------------------------------------------------------
    // ----------------------------------------------------------------
    ArrayStack()
    {
        m_Array = new T[128];
        m_TopIndex = -1;
    }


    // ----------------------------------------------------------------
    // ----------------------------------------------------------------
    ~ArrayStack()
    {
        delete m_Array;
    }


    // ----------------------------------------------------------------
    // ----------------------------------------------------------------
    void Print()
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


    // ----------------------------------------------------------------
    // ----------------------------------------------------------------
    void Push(T data)
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
    void Pop()
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
    T Peek()
    {
        return m_Array[m_TopIndex];
    }


public:

    T* m_Array;
    int m_TopIndex;

};
