#pragma once
#include <iostream>

class Deque
{
public:

	Deque(int inSize);


	bool empty();
	bool full();

	void push_front(const int inData);
	void push_back(const int inData);

	void pop_front();
	void pop_back();

	int* front();
	int* back();


private:

	int* m_Array;

	int m_iSize;
	int m_iBackIndex;
	int m_iFrontIndex;

};
