#pragma once


class DLLNode
{
public:
    DLLNode* m_NextNode;
    DLLNode* m_PreviousNode;
    
    int m_Data;
};


class DoubleLinkedList
{
public:
    DoubleLinkedList();

    void PrintLinkedList();
    void ReverseList();

    void AddNodeToEnd(int data);
    void AddNodeToBeginning(int data);
    void InsertNode(int data, int index);
    void RemoveNode(int index);

public:
    DLLNode* m_HeadNode;
    DLLNode* m_TailNode;

    int m_ElementCount;
};
