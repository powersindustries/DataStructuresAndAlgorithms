#pragma once


class BSTNode
{
public:
    BSTNode(int data);

public:
    BSTNode* m_LeftNode;
    BSTNode* m_RightNode;
    
    int m_Data;

};


class BinarySearchTree
{
public:
    BinarySearchTree();

    void PrintElements();

    void InsertNode(int data);
    void DeleteNode(int data);

    bool Lookup(int data);

public:
    BSTNode* m_RootNode;

};

