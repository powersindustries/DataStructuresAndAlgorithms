#pragma once


struct StackNode
{
    StackNode() : m_NextNode(nullptr), m_Data(0) {}

    StackNode* m_NextNode;
    int m_Data;
};


class Stack
{
public:
    Stack();
    ~Stack();

    void Print();

    void Push(int data);
    void Pop();


public:
    StackNode* m_TopNode;

};


class ArrayStack
{
public:
    ArrayStack();
    ~ArrayStack();

    void Print();

    void Push(int data);
    void Pop();
    int Peek();


public:
    int* m_Array;
    int m_TopIndex;

};
