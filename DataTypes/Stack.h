#pragma once


class StackNode
{
public:
    StackNode(int data);

public:
    StackNode* m_NextNode;
    
    int m_Data;

};


class Stack
{
public:
    Stack();
    
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
    
    void Display();

    void Push(int data);
    int Pop();
    int Peek();

public:
    int* m_Array;
    int m_Top;

};
