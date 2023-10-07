cmake_minimum_required(VERSION 2.7)
project(DataAlgorithms)

set(SOURCE_FILES

    main.cpp

    Algorithms/Recursion.h
    Algorithms/Recursion.cpp
    Algorithms/Searching.h
    Algorithms/Searching.cpp
    Algorithms/Sorting.h
    Algorithms/Sorting.cpp

    DataTypes/BinarySearchTree.h
    DataTypes/BinarySearchTree.cpp
    DataTypes/DynamicArray.h
    DataTypes/DynamicArray.cpp
    DataTypes/HashTable.h
    DataTypes/HashTable.cpp
    DataTypes/LinkedLists.h
    DataTypes/LinkedLists.cpp
    DataTypes/Stack.h
    DataTypes/Stack.cpp
    DataTypes/Deque.h
    DataTypes/Deque.cpp
    DataTypes/Queue.h
    DataTypes/Queue.cpp

    DataTypes/Graphs/Graph.h
    DataTypes/Graphs/Graph.cpp
    DataTypes/Graphs/DisjointSet.h
    DataTypes/Graphs/DisjointSet.cpp
)

add_executable(DataAlgorithms  ${SOURCE_FILES})
