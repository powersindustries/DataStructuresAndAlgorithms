#pragma once
#include <iostream>

#define HASH_TABLE_CAPACITY 128


struct TableEntry
{
    int m_Key;
    int m_Value;
};


class HashTable
{
public:
    HashTable();
    ~HashTable();

    void Print();

    void AddEntry(int key, int value);
    void RemoveElement(int key);
    
    int GetElementByKey(int key);


private:
    int HashFunction(int key);


public:
    TableEntry** m_Array;

};
