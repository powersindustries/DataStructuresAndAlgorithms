#include "BinarySearchTree.h"
#include <iostream>
#include <stack>


// ----------------------------------------------------------------
// ----------------------------------------------------------------
BSTNode::BSTNode(int data)
{
    m_Data      = data;
    m_LeftNode  = NULL;
    m_RightNode = NULL;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
BinarySearchTree::BinarySearchTree()
{
    m_RootNode = NULL;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void BinarySearchTree::PrintElements()
{
    std::stack<BSTNode*> printStack;
    BSTNode* tempNode = m_RootNode;

    while (tempNode != NULL || printStack.empty() == false)
    {
        while (tempNode != NULL)
        {
            printStack.push(tempNode);
            tempNode = tempNode->m_LeftNode;
        }

        tempNode = printStack.top();
        std::cout << tempNode->m_LeftNode << ", ";
        printStack.pop();

        tempNode = tempNode->m_RightNode;
    }

}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void BinarySearchTree::InsertNode(int data)
{
    BSTNode* newNode      = new BSTNode(data);
    BSTNode* tempNode     = m_RootNode;
    BSTNode* iteratorNode = NULL;

    while (tempNode != NULL)
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

    if (iteratorNode == NULL)
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
void BinarySearchTree::DeleteNode(int data)
{
    if (m_RootNode == NULL)
    {
        std::cout << "Tree is empty. Please insert values" << std::endl;
        return;
    }

    BSTNode* tempNode = m_RootNode;
    BSTNode* parentNode = NULL;
    while (tempNode != NULL)
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
            if (tempNode->m_LeftNode == NULL && tempNode->m_RightNode == NULL)
            {
                std::cout << "We are deleting a root node" << std::endl;
                if (parentNode->m_LeftNode == tempNode)
                {
                    parentNode->m_LeftNode = NULL;
                }
                else
                {
                    parentNode->m_RightNode = NULL;
                }
                free(tempNode);
                return;
            }
            else if (tempNode->m_LeftNode == NULL || tempNode->m_RightNode == NULL)
            {
                std::cout << "Deleting a parent node with one child" << std::endl;
                if (tempNode->m_LeftNode != NULL)
                {
                    parentNode->m_LeftNode = tempNode->m_LeftNode;
                }
                else
                {
                    parentNode->m_RightNode = tempNode->m_RightNode;
                }
                free(tempNode);
                return;
            }
            else
            {
                std::cout << "Deleting a parent Node with two children" << std::endl;

                // In this case we need to find the pre-order successor.
                BSTNode* iteratorNode = tempNode->m_RightNode;
                if (iteratorNode->m_LeftNode == NULL && iteratorNode->m_RightNode == NULL)
                {
                    tempNode->m_Data = iteratorNode->m_Data;
                    tempNode->m_RightNode = NULL;
                    free(iteratorNode);
                    return;
                }
                else if (iteratorNode->m_LeftNode == NULL && iteratorNode->m_RightNode != NULL)
                {
                    tempNode->m_Data = iteratorNode->m_Data;
                    tempNode->m_RightNode = iteratorNode->m_RightNode;
                    free(iteratorNode);
                    return;
                }
                while (iteratorNode->m_LeftNode != NULL)
                {
                    parentNode = iteratorNode;
                    iteratorNode = iteratorNode->m_LeftNode;
                }
                tempNode->m_Data = iteratorNode->m_Data;
                parentNode->m_LeftNode = NULL;
                free(iteratorNode);
                return;
            }
        }
    }

    std::cout << "No Nodes Found to delete" << std::endl;
    return;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
bool BinarySearchTree::Lookup(int data)
{
    if (m_RootNode == NULL)
    {
        std::cout << "Tree Empty please Insert values" << std::endl;
        return false;
    }

    BSTNode* tempNode = m_RootNode;
    while (tempNode != NULL)
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
