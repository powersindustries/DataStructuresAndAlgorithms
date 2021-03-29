#include "Recursion.h"
#include <iostream>
#include <vector>


// ----------------------------------------------------------------
// ----------------------------------------------------------------
int Recursion::Factorial(int number)
{
    if (number < 0)
    {
        return false;
    }

    if (number == 0 || number == 1)
    {
        return 1;
    }
    else
    {
        return number * Factorial(number - 1);
    }
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
int Recursion::FibonacciSequence(int number)
{
    std::vector<int> vectorList;

    if (number == 0)
    {
        return 0;
    }

    if (number == 1)
    {
        return 1;
    }

    if (vectorList[number] != 0)
    {
        return vectorList[number];
    }

    vectorList[number] = FibonacciSequence(number - 1) + FibonacciSequence(number - 2);
    return vectorList[number];
}
