#pragma once

class Queue
{
public:

    Queue();
    ~Queue();

    bool empty() const;

    void enqueu(int inData);
    void dequeue();

    int front();
    int back();


private:

    bool full() const;


private:

    int *m_Array;

    int m_iHead;
    int m_iTail;

};