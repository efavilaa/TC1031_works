// TC1031.610
// A00844789
// Ethiel Favila Alvarado

#include <iostream>
using namespace std;

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

// normal recursion ig
int two_power_normal(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return 2 * two_power_normal(n - 1);
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
    // Coding exercise
    printf("Powers \n");

    printf("%d", two_power(3, 1));
    printf("\n");

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