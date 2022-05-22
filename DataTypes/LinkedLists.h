#pragma once


struct SNode
{
    SNode() : m_NextNode(nullptr), m_Data(0) {}

    SNode* m_NextNode;
    int m_Data;
};


struct DNode
{
    DNode() : m_NextNode(nullptr), m_PreviousNode(nullptr), m_Data(0) {}

    DNode* m_NextNode;
    DNode* m_PreviousNode;

    int m_Data;
};


class SingleLinkedList
{
public:
    SingleLinkedList();
    ~SingleLinkedList();

    void Print();

    void InsertNode(int data, unsigned int index);
    void AddNodeToEnd(int data);
    void AddNodeToBeginning(int data);
    void DeleteNode(unsigned int index);

    int GetNodeCount() { return m_NodeCount; };


public:
    SNode* m_HeadNode;

    unsigned int m_NodeCount;

};


class DoubleLinkedList
{
public:
    DoubleLinkedList();
    ~DoubleLinkedList();

    void Print();
    void ReverseList();

    void InsertNode(int data, unsigned int index);
    void AddNodeToEnd(int data);
    void AddNodeToBeginning(int data);
    void DeleteNode(unsigned int index);


public:
    DNode* m_HeadNode;

    unsigned int m_NodeCount;
};
