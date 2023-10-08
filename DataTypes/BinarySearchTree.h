#pragma once


#include <stack>

template <class T>
struct BSTNode
{
    BSTNode() : m_LeftNode(nullptr), m_RightNode(nullptr) {}

    BSTNode* m_LeftNode;
    BSTNode* m_RightNode;
    
    T m_Data;
};


template <class T>
class BinarySearchTree
{
public:


    // ----------------------------------------------------------------
    // ----------------------------------------------------------------
    BinarySearchTree()
    {
        m_RootNode = nullptr;
    }


    // ----------------------------------------------------------------
    // ----------------------------------------------------------------
    ~BinarySearchTree()
    {
        delete m_RootNode;
    }


    // ----------------------------------------------------------------
    // ----------------------------------------------------------------
    void Print()
    {
        BSTNode<T>* tempNode = m_RootNode;
        std::stack<BSTNode<T>*> tempStack;

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
    void Insert(T inData)
    {
        BSTNode<T>* newNode = new BSTNode<T>();
        newNode->m_Data = inData;

        BSTNode<T>* tempNode = m_RootNode;
        BSTNode<T>* iteratorNode = nullptr;

        while (tempNode != nullptr)
        {
            iteratorNode = tempNode;
            if (inData < tempNode->m_Data)
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
        else if (inData < iteratorNode->m_Data)
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
    void Delete(T inData)
    {
        if (m_RootNode == nullptr)
        {
            std::cout << "Tree is empty." << std::endl;
            return;
        }

        BSTNode<T>* tempNode = m_RootNode;
        BSTNode<T>* parentNode = m_RootNode;
        while (tempNode != nullptr)
        {
            if (inData < tempNode->m_Data)
            {
                parentNode = tempNode;
                tempNode = tempNode->m_LeftNode;
            }
            else if (inData > tempNode->m_Data)
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
                    BSTNode<T>* iteratorNode = tempNode->m_RightNode;
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
    bool Find(T inData)
    {
        if (m_RootNode == nullptr)
        {
            std::cout << "Tree Empty." << std::endl;
            return false;
        }

        BSTNode<T>* tempNode = m_RootNode;
        while (tempNode != nullptr)
        {
            if (tempNode->m_Data > inData)
            {
                tempNode = tempNode->m_LeftNode;
            }
            else if (tempNode->m_Data < inData)
            {
                tempNode = tempNode->m_RightNode;
            }
            else if (tempNode->m_Data == inData)
            {
                return true;
            }
        }

        return false;
    }


public:

    BSTNode<T>* m_RootNode;

};

