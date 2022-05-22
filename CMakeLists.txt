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
    DataTypes/Graph.h
    DataTypes/Graph.cpp
    DataTypes/HashTable.h
    DataTypes/HashTable.cpp
    DataTypes/LinkedLists.h
    DataTypes/LinkedLists.cpp
    DataTypes/Stack.h
    DataTypes/Stack.cpp

)

add_executable(DataAlgorithms  ${SOURCE_FILES})