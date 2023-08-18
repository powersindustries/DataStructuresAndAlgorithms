#include <iostream>
#include "DataTypes/LinkedLists.h"
#include "DataTypes/Stack.h"
#include "DataTypes/HashTable.h"
#include "DataTypes/BinarySearchTree.h"
#include "DataTypes/DynamicArray.h"
#include "DataTypes/Graphs/DisjointSet.h"

int main()
{
    std::cout << "Welcome to Data Types and Algorithms!" << std::endl;
    std::cout << "Feel free to use this space to try out the various data types." << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;


    // Single Linked List Example
    std::cout << "Single Linked List" << std::endl;
    SingleLinkedList SingleLL;
    SingleLL.AddNodeToEnd(0);
    SingleLL.AddNodeToEnd(1);
    SingleLL.AddNodeToEnd(2);
    SingleLL.AddNodeToEnd(3);
    SingleLL.Print();

    SingleLL.InsertNode(10, 2);
    SingleLL.Print();

    SingleLL.DeleteNode(1);
    SingleLL.DeleteNode(0);
    SingleLL.Print();

    SingleLL.AddNodeToBeginning(20);
    SingleLL.Print();
    std::cout << std::endl;


    // Double Linked List Example
    std::cout << "Double Linked List" << std::endl;
    DoubleLinkedList DoubleLL;
    DoubleLL.AddNodeToEnd(0);
    DoubleLL.AddNodeToEnd(1);
    DoubleLL.AddNodeToEnd(2);
    DoubleLL.AddNodeToEnd(3);
    DoubleLL.Print();

    DoubleLL.AddNodeToBeginning(10);
    DoubleLL.Print();

    DoubleLL.InsertNode(20, 2);
    DoubleLL.Print();

    DoubleLL.ReverseList();
    DoubleLL.Print();

    DoubleLL.DeleteNode(2);
    DoubleLL.Print();

    std::cout << std::endl;


    // Stack Example
    std::cout << "Stack" << std::endl;
    Stack stack;
    stack.Push(0);
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.Print();

    stack.Pop();
    stack.Print();

    stack.Push(7);
    stack.Print();

    std::cout << std::endl;


    // Array Stack Example
    std::cout << "Array Stack" << std::endl;
    ArrayStack arrayStack;
    arrayStack.Push(0);
    arrayStack.Push(1);
    arrayStack.Push(2);
    arrayStack.Push(3);
    arrayStack.Print();

    arrayStack.Push(5);
    arrayStack.Print();

    arrayStack.Pop();
    arrayStack.Print();

    std::cout << "Peak: " << arrayStack.Peek() << std::endl;
    std::cout << std::endl;

    // Binary Search Tree Example
    std::cout << "Binary Search Tree" << std::endl;
    BinarySearchTree BST;
    BST.Insert(0);
    BST.Insert(1);
    BST.Insert(2);
    BST.Insert(3);
    BST.Print();

    BST.Delete(3);
    BST.Print();

    std::cout << "Does 2 exist in tree? " << (BST.Find(2) ? "Yes" : "No") << std::endl;
    std::cout << std::endl;


    // Dynamic Arrays Example
    std::cout << "Dynamic Array" << std::endl;
    DynamicArray DArray;
    DArray.PushBack(0);
    DArray.PushBack(1);
    DArray.PushBack(2);
    DArray.PushBack(3);
    DArray.Print();

    DArray.Emplace(2, 10);
    DArray.Print();

    DArray.Insert(1, 15);
    DArray.Print();

    DArray.RemoveAt(1);
    DArray.Print();

    DArray.Pop();
    DArray.Print();

    std::cout << "Value at 2 is " << DArray.GetValueAt(2) << " and the size is " << DArray.Size() << std::endl;
    std::cout << std::endl;


    // Hash Table Example
    std::cout << "Hash Table" << std::endl;
    HashTable hashTable;
    hashTable.AddEntry(0,0);
    hashTable.AddEntry(1,1);
    hashTable.AddEntry(2,2);
    hashTable.AddEntry(3,3);
    hashTable.Print();

    hashTable.RemoveElement(2);
    hashTable.Print();

    std::cout << "Value at 1 is " << hashTable.GetElementByKey(1) << std::endl;

    DisjointSet uf(10);
	// 1-2-5-6-7 3-8-9 4
	uf.AddUnionSet(1, 2);
	uf.AddUnionSet(2, 5);
	uf.AddUnionSet(5, 6);
	uf.AddUnionSet(6, 7);
	uf.AddUnionSet(3, 8);
	uf.AddUnionSet(8, 9);
	std::cout << uf.VertexConnected(1, 5) << std::endl;  // true
	std::cout << uf.VertexConnected(5, 7) << std::endl;  // true
	std::cout << uf.VertexConnected(4, 9) << std::endl;  // false
	// 1-2-5-6-7 3-8-9-4
	uf.AddUnionSet(9, 4);
	std::cout << uf.VertexConnected(4, 9) << std::endl;  // true

    return 0;
}