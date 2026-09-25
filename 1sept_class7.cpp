#include <iostream>
using namespace std;

// insert sort function
int insertSort(std::vector<int> &vec, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > key)
        {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = key;
    }
    return 0;
}

// merge sort function
void merge(std::vector<int> &vec, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = vec[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = vec[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            vec[k] = L[i];
            i++;
        }
        else
        {
            vec[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        vec[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        vec[k] = R[j];
        j++;
        k++;
    }
}

// quick sort function
void quickSort(std::vector<int> &vec, int low, int high)
{
    if (low < high)
    {
        int pivot = vec[high];
        int i = (low - 1);
        for (int j = low; j < high; j++)
        {
            if (vec[j] < pivot)
            {
                i++;
                std::swap(vec[i], vec[j]);
            }
        }
        std::swap(vec[i + 1], vec[high]);
        int pi = i + 1;

        quickSort(vec, low, pi - 1);
        quickSort(vec, pi + 1, high);
    }
}

int main()
{

    // SORTING ALGORITHMS

    // Insert Swap
    /*o(n^2)
     */

    /*
    Merge Solving Algorithm (Arbolito)
    O(nlogn)
    */

    /*

    */

    return 0;
}