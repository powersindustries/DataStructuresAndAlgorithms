#include "HashTable.h"


// ----------------------------------------------------------------
// ----------------------------------------------------------------
HashTable::HashTable()
{
    m_Array = new TableEntry * [HASH_TABLE_CAPACITY];

    for (int x = 0; x < HASH_TABLE_CAPACITY; ++x)
    {
        m_Array[x] = nullptr;
    }
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
HashTable::~HashTable()
{
    delete[] m_Array;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
int HashTable::HashFunction(int key)
{
    return key % HASH_TABLE_CAPACITY; // Open addressing
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void HashTable::AddEntry(int key, int value)
{
    int hashedKey = HashFunction(key);

    while (m_Array[hashedKey] != nullptr && m_Array[hashedKey]->m_Key != key)
    {
        hashedKey = HashFunction(hashedKey + 1);
    }

    // Delete pair if the key already exists
    if (m_Array[hashedKey] != nullptr)
    {
        delete m_Array[hashedKey];
    }

    // Create new hashnode
    m_Array[hashedKey] = new TableEntry();
    m_Array[hashedKey]->m_Key = key;
    m_Array[hashedKey]->m_Value = value;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void HashTable::RemoveElement(int key)
{
    int hashedKey = HashFunction(key);

    if (m_Array[hashedKey] == nullptr)
    {
        std::cout << "Element is DNE" << std::endl;
        return;
    }

    m_Array[hashedKey] = nullptr;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void HashTable::Print()
{
    for (int x = 0; x < HASH_TABLE_CAPACITY; ++x)
    {
        if (m_Array[x] != nullptr)
        {
            std::cout << "(" << m_Array[x]->m_Key << "," << m_Array[x]->m_Value << ") ";
        }
    }

    std::cout << std::endl;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
int HashTable::GetElementByKey(int key)
{
    int hashedKey = HashFunction(key);

    while (m_Array[hashedKey] != nullptr && m_Array[hashedKey]->m_Key != key)
    {
        hashedKey = HashFunction(hashedKey + 1);
    }

    if (m_Array[hashedKey] == nullptr)
    {
        return -1;
    }

    return m_Array[hashedKey]->m_Value;
}