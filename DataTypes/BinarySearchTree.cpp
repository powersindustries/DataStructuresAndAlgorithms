#include "BinarySearchTree.h"
#include <iostream>
#include <stack>


// ----------------------------------------------------------------
// ----------------------------------------------------------------
BinarySearchTree::BinarySearchTree()
{
    m_RootNode = nullptr;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
BinarySearchTree::~BinarySearchTree()
{
    delete m_RootNode;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void BinarySearchTree::Print()
{
    BSTNode* tempNode = m_RootNode;
    std::stack<BSTNode*> tempStack;

    while (tempNode != nullptr || !tempStack.empty())
    {
        if (tempNode != nullptr)
        {
            tempStack.push(tempNode);
            tempNode = tempNode->m_LeftNode;
        }
        else
        {
            tempNode = tempStack.top();
            tempStack.pop();

            std::cout << tempNode->m_Data << " ";

            tempNode = tempNode->m_RightNode;
        }
    
    }

    std::cout << std::endl;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void BinarySearchTree::Insert(int data)
{
    BSTNode* newNode = new BSTNode();
    newNode->m_Data = data;
    
    BSTNode* tempNode = m_RootNode;
    BSTNode* iteratorNode = nullptr;

    while (tempNode != nullptr)
    {
        iteratorNode = tempNode;
        if (data < tempNode->m_Data)
        {
            tempNode = tempNode->m_LeftNode;
        }
        else
        {
            tempNode = tempNode->m_RightNode;
        }
    }

    if (iteratorNode == nullptr)
    {
        m_RootNode = newNode;
    }
    else if (data < iteratorNode->m_Data)
    {
        iteratorNode->m_LeftNode = newNode;
    }
    else
    {
        iteratorNode->m_RightNode = newNode;
    }

}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void BinarySearchTree::Delete(int data)
{
    if (m_RootNode == nullptr)
    {
        std::cout << "Tree is empty." << std::endl;
        return;
    }

    BSTNode* tempNode = m_RootNode;
    BSTNode* parentNode = m_RootNode;
    while (tempNode != nullptr)
    {
        if (data < tempNode->m_Data)
        {
            parentNode = tempNode;
            tempNode = tempNode->m_LeftNode;
        }
        else if (data > tempNode->m_Data)
        {
            parentNode = tempNode;
            tempNode = tempNode->m_RightNode;
        }
        else
        {
            if (tempNode->m_LeftNode == nullptr && tempNode->m_RightNode == nullptr)
            {
                std::cout << "Deleting the root node." << std::endl;
                if (parentNode->m_LeftNode == tempNode)
                {
                    parentNode->m_LeftNode = nullptr;
                }
                else
                {
                    parentNode->m_RightNode = nullptr;
                }

                delete tempNode;
                return;
            }
            else if (tempNode->m_LeftNode == nullptr || tempNode->m_RightNode == nullptr)
            {
                std::cout << "Deleting parent node with one child." << std::endl;
                if (tempNode->m_LeftNode != nullptr)
                {
                    parentNode->m_LeftNode = tempNode->m_LeftNode;
                }
                else
                {
                    parentNode->m_RightNode = tempNode->m_RightNode;
                }

                delete tempNode;
                return;
            }
            else
            {
                std::cout << "Deleting parent Node with two children." << std::endl;

                // In this case we need to find the pre-order successor.
                BSTNode* iteratorNode = tempNode->m_RightNode;
                if (iteratorNode->m_LeftNode == nullptr && iteratorNode->m_RightNode == nullptr)
                {
                    tempNode->m_Data = iteratorNode->m_Data;
                    tempNode->m_RightNode = nullptr;

                    delete iteratorNode;
                    return;
                }
                else if (iteratorNode->m_LeftNode == nullptr && iteratorNode->m_RightNode != nullptr)
                {
                    tempNode->m_Data = iteratorNode->m_Data;
                    tempNode->m_RightNode = iteratorNode->m_RightNode;

                    delete iteratorNode;
                    return;
                }

                while (iteratorNode->m_LeftNode != nullptr)
                {
                    parentNode = iteratorNode;
                    iteratorNode = iteratorNode->m_LeftNode;
                }

                tempNode->m_Data = iteratorNode->m_Data;
                parentNode->m_LeftNode = nullptr;

                delete iteratorNode;
                return;
            }
        }
    }

    std::cout << "No Nodes Found to delete" << std::endl;
    return;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
bool BinarySearchTree::Find(int data)
{
    if (m_RootNode == nullptr)
    {
        std::cout << "Tree Empty." << std::endl;
        return false;
    }

    BSTNode* tempNode = m_RootNode;
    while (tempNode != nullptr)
    {
        if (tempNode->m_Data > data)
        {
            tempNode = tempNode->m_LeftNode;
        }
        else if (tempNode->m_Data < data)
        {
            tempNode = tempNode->m_RightNode;
        }
        else if (tempNode->m_Data == data)
        {
            return true;
        }
    }

    return false;
}
