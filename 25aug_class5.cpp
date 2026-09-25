#include <iostream>
using namespace std;

// SEUQENCIAL SEARCH
int sequentialSearch(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
            // lo regresa si si esta
            return i;
    }
    // si no esta
    return -1;
}

// BINARY SEARCH
int binarySearch(int arr[], int n, int x)
{
    int l = 0;
    int r = n - 1;
    while (l <= r)
    {
        int i = l + (r - l) / 2;
        if (arr[i] == x)
        {
            // si lo encuentra en la mitad ya estuvo
            return i;
        }
        // si no para arriba
        if (arr[i] > x)
        {
            r = i - 1;
        }
        // o abajo
        else
        {
            l = i + 1;
        }
        // pero si esta desacomodado ya valio
    }
    // si no esta
    return -1;
}

int main()
{

    /*
    SEARCH

    Sequential vs Binary Search
    Sequential Search - O(n)
    Search every item one by one

    Binary Search - O(log n)
    Needs the elements to be sorted
    Repeatedly splitsa sorted list in half
    https://coddy.tech/visualize/searching/binary-search
    */

    int uno[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int uno_x = 9;
    int dos[5] = {2, 4, 6, 8, 10};
    int dos_x = 5;
    int tres[7] = {1, 3, 5, 7, 9, 11, 13};
    int tres_x = 7;
    int cuatro[6] = {10, 20, 30, 40, 50, 60};
    int cuatro_x = 20;

    cout << "Sequential 1" << endl;
    cout << sequentialSearch(uno, 10, uno_x) << endl;

    cout << "Binary 1" << endl;
    cout << binarySearch(uno, 10, uno_x) << endl;

    cout << "Sequential 2" << endl;
    cout << sequentialSearch(dos, 5, dos_x) << endl;

    cout << "Binary 2" << endl;
    cout << binarySearch(dos, 5, dos_x) << endl;

    cout << "Sequential 3" << endl;
    cout << sequentialSearch(tres, 7, tres_x) << endl;

    cout << "Binary 3" << endl;
    cout << binarySearch(tres, 7, tres_x) << endl;

    cout << "Sequential 4" << endl;
    cout << sequentialSearch(cuatro, 6, cuatro_x) << endl;

    cout << "Binary 4" << endl;
    cout << binarySearch(cuatro, 6, cuatro_x) << endl;

    return 0;
}