#include <iostream>
using namespace std;

// RECLUSIVITY
// Creating increasingly smalles versions of the same problem

// Recursive 1
//  goes on and on and on
int recursiveFactorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * recursiveFactorial(n - 1);
    }
}
// if i choose an insanely large number, it will go on and
// on and on until it crashes the program

// Recursive 2: Tail recursion
int fact_tail(int n, int acc)
{
    if (n == 0)
        return acc;
    return fact_tail(n - 1, acc * n);
}

// Differences:
//  1. Recursive 1: Creates a new stack frame for each recursive call
//  2. Recursive 2: Uses tail recursion, which can be optimized by the compiler to use a single stack frame

// CODING EXERCISE: 2^n a^n
// 2^n
int two_power(int n, int cummulative)
{
    if (n == 0)
    {
        return cummulative;
    }
    return two_power(n - 1, cummulative * 2);
}

// a^n
int a_power(int a, int n, int cummulative)
{
    if (n == 0)
    {
        return cummulative;
    }
    return a_power(a, n - 1, cummulative * a);
}

// Activity 1.1 Recursive vs iterative functions
// sum of consecutive numbers from 1 to n

// Recursive method
int act1_recursive(int n, int cumulative)
{
    if (n == 0)
    {
        return cumulative;
    }
    return (act1_recursive(n - 1, cumulative + n));
}

// Iterative method
int act1_iterative(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n;
        n -= 1;
    }
    return sum;
}

// Direct methiod (formula)
int act1_direct(int n)
{
    int result = (n * (n + 1)) / 2;
    return result;
}

int main()
{
    printf("Powers \n");

    printf("%d", two_power(3, 1));
    printf("\n");
    // printf("%d", recursiveFactorial(5));
    //  if i choose an insanely large number, it will go on and
    //  on and on until it crashes the program
    printf("%d", a_power(3, 3, 1));
    // Activity 1.1 Recursive vs iterative functions

    printf("\nSums \n");
    // Recursive method
    printf("%d", act1_recursive(5, 0));
    printf("\n");
    // Iterative method
    printf("%d", act1_iterative(5));

    printf("\n");

    // Direct methiod (formula)
    printf("%d", act1_direct(5));

    return 0;
}