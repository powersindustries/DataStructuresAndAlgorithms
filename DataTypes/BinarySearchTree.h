#pragma once


struct BSTNode
{
    BSTNode() : m_LeftNode(nullptr), m_RightNode(nullptr), m_Data(0){}

    BSTNode* m_LeftNode;
    BSTNode* m_RightNode;
    
    int m_Data;
};


class BinarySearchTree
{
public:
    BinarySearchTree();
    ~BinarySearchTree();

    void Print();
    void Insert(int data);
    void Delete(int data);
    bool Find(int data);


public:
    BSTNode* m_RootNode;

};

