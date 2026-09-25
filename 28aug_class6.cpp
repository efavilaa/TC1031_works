#include <iostream>
using namespace std;
#include <vector>

/*
Sorting Algorithms

1. Selection Sort - O(n^2)

2. Bubble Sort - O(n^2) [Swap sort]

3. Exchange Sort - O(n^2)

*/

// ACTIVITY
// Exchange Sort
// Computational complexity:O(n^2)
int exchangeSort(std::vector<int> &vec, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (vec[i] > vec[j])
            {
                int temp = vec[i];
                vec[i] = vec[j];
                vec[j] = temp;
            }
        }
    }
    return 0;
}

// Bubble Sort
// Computational complexity:O(n^2)
int bubbleSort(std::vector<int> &vec, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (vec[j] > vec[j + 1])
            {
                int a = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = a;
            }
        }
    }
    return 0;
}

// selection order sort
// Computational complexity:O(n^2)
int selectionSort(std::vector<int> &vec, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int eo = i;
        for (int j = i + 1; j < n; j++)
        {
            if (vec[j] < vec[eo])
            {
                eo = j;
            }
        }
        if (eo != i)
        {
            int temp = vec[i];
            vec[i] = vec[eo];
            vec[eo] = temp;
        }
    }
    return 0;
}

int main()
{
    // print vector function

    auto printVector = [](const std::vector<int> &vec)
    {
        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    };

    // Vectors for test cases
    std::vector<int> vec1 = {5, 2, 9, 1, 5, 6};
    std::vector<int> vec2 = {3, 0, -1, 8, 7, 2};
    std::vector<int> vec3 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> vec4 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    std::vector<int> vec5 = {2, 2, 2, 3, 3, 1, 1, 0, 0};
    std::vector<int> vec6 = {5, 5, 5, 5, 5, 5};
    std::vector<int> vec7 = {1};
    std::vector<int> vec8 = {2, 5, 6, 7, 83, 2};
    std::vector<int> vec9 = {};
    std::vector<int> vec10 = {42, -5, 3204, 0, 1, -1, 100};
    std::vector<int> vec11 = {1, 2, 3, 4};
    std::vector<int> vec12 = {67, 34, 23, 12, 45, 56, 78, 89, 90, 11};

    // Exchange sort
    cout << "Exchange Sort Test Cases" << endl;
    cout << "Vector 1: ";
    exchangeSort(vec1, vec1.size());
    printVector(vec1);

    cout << "Vector 2: ";
    exchangeSort(vec2, vec2.size());
    printVector(vec2);
    cout << "Vector 3: ";
    exchangeSort(vec3, vec3.size());
    printVector(vec3);
    cout << "Vector 4: ";
    exchangeSort(vec4, vec4.size());
    printVector(vec4);

    // Bubble Sort
    cout << "Bubble Sort Test Cases" << endl;
    cout << "Vector 5: ";
    bubbleSort(vec5, vec5.size());
    printVector(vec5);
    cout << "Vector 6: ";
    bubbleSort(vec6, vec6.size());
    printVector(vec6);
    cout << "Vector 7: ";
    bubbleSort(vec7, vec7.size());
    printVector(vec7);
    cout << "Vector 8: ";
    bubbleSort(vec8, vec8.size());
    printVector(vec8);

    // Selection Sort
    cout << "Selection Sort Test Cases" << endl;
    cout << "Vector 9: ";
    selectionSort(vec9, vec9.size());
    printVector(vec9);
    cout << "Vector 10: ";
    selectionSort(vec10, vec10.size());
    printVector(vec10);
    cout << "Vector 11: ";
    selectionSort(vec11, vec11.size());
    printVector(vec11);
    cout << "Vector 12: ";
    selectionSort(vec12, vec12.size());
    printVector(vec12);
    return 0;
}