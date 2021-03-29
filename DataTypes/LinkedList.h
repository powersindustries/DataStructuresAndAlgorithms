#pragma once


class LLNode
{
public:
    LLNode(int data);

public:
    LLNode* m_NextNode;

    int m_Data;

};


class LinkedList
{
public:
    LinkedList();
    
    void PrintLinkedList();

    void InsertNode(int data, int index);
    void AddNodeToEnd(int data);
    void AddNodeToBeginning(int data);
    
    void RemoveNode(int index);

public:
    LLNode* m_HeadNode;
    LLNode* m_TailNode;
    
    int m_ElementCount;

};
