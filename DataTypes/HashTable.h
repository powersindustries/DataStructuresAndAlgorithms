#pragma once
#include <iostream>


class HashNode
{
public:
    HashNode(int key, int value);
    
public:
    int m_Key;
    int m_Value;
};


class HashTable
{
public:
    HashTable();

    void PrintHashtable();
    
    int GetElementByKey(int key);

    void InsertElement(int key, int value);
    void RemoveElement(int key);

private:
    int HashFunction(int key);


public:
    HashNode** m_Array;

};
