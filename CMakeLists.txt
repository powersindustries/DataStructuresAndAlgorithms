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
    DataTypes/DynamicArray.h
    DataTypes/HashTable.h
    DataTypes/LinkedLists.h
    DataTypes/Stack.h
    DataTypes/Deque.h
    DataTypes/Queue.h

    DataTypes/Graphs/Graph.h
    DataTypes/Graphs/DisjointSet.h
)

add_executable(DataAlgorithms  ${SOURCE_FILES})
