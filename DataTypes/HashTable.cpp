#include "HashTable.h"
#include <map>


// ----------------------------------------------------------------
// ----------------------------------------------------------------
HashNode::HashNode(int key, int value)
{
    m_Key = key;
    m_Value = value;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
HashTable::HashTable()
{
    m_Array = new HashNode * [128];

    for (int x = 0; x < 128; ++x)
    {
        m_Array[x] = NULL;
    }
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
int HashTable::HashFunction(int key)
{
    return key % 128; // Open addressing
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void HashTable::InsertElement(int key, int value)
{
    int hashedKey = HashFunction(key);

    while (m_Array[hashedKey] != NULL && m_Array[hashedKey]->m_Key != key)
    {
        hashedKey = HashFunction(hashedKey + 1);
    }

    // Delete pair if the key already exists
    if (m_Array[hashedKey] != NULL)
    {
        delete m_Array[hashedKey];
    }

    // Create new hashnode
    m_Array[hashedKey] = new HashNode(key, value);
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void HashTable::RemoveElement(int key)
{
    int hashedKey = HashFunction(key);

    if (m_Array[hashedKey] == NULL)
    {
        std::cout << "Element is DNE" << std::endl;
        return;
    }

    while (m_Array[hashedKey] != NULL)
    {
        if (m_Array[hashedKey]->m_Key == key)
        {
            break;
        }
        hashedKey = HashFunction(hashedKey + 1);
    }

    delete m_Array[hashedKey];

    std::cout << "Element Deleted" << std::endl;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void HashTable::PrintHashtable()
{
    for (int x = 0; x < 128; ++x)
    {
        if (m_Array[x] != NULL && m_Array[x]->m_Key != -1)
        {
            std::cout << m_Array[x]->m_Key << ", " << m_Array[x]->m_Value << std::endl;
        }
    }
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
int HashTable::GetElementByKey(int key)
{
    int hashedKey = HashFunction(key);

    while (m_Array[hashedKey] != NULL && m_Array[hashedKey]->m_Key != key)
    {
        hashedKey = HashFunction(hashedKey + 1);
    }

    if (m_Array[hashedKey] == NULL)
    {
        return -1;
    }

    return m_Array[hashedKey]->m_Value;
}