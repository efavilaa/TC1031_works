#include "Sorter.h"
#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

// Sorting method: Quicksort
// Description: This function implements the quicksort algorithm
// Entry: left and right indices of the subarray to be sorted
// Output: The subarray is sorted in place
// Precondition: The input vector is not empty
// Postcondition: The input vector is sorted in ascending order
// Complexity: O(n log n) average, O(n^2) worst case
// Notes: Ayuda porque las demás funciones necesitan reacomodarse cuando hay cambios y asi
void Sorter::sortingQuick(int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int pivot = data[right];
    int i = left - 1;
    for (int x = left; x < right; x++)
    {
        if (data[x] < pivot)
        {
            i++;
            // cambio los valores y el temproal se reinicia
            int holder = data[i];
            data[i] = data[x];
            data[x] = holder;
        }
    }
    // ponemos pivot donde va
    int holder = data[i + 1];
    data[i + 1] = data[right];
    data[right] = holder;

    int pivotIndex = i + 1;

    // llamamos recursivamente a la funcion
    sortingQuick(left, pivotIndex - 1);
    sortingQuick(pivotIndex + 1, right);
}

// Sorting calling sortingQuick
// Description: Calls quicksort and gives it its parameters, the left and right indices of the vector
// Entry: None
// Output: The vector is sorted in place
// Precondition: The input vector is not empty
// Postcondition: The input vector is sorted in ascending order
// Complexity:O(n log n) average, O(n^2) worst case
void Sorter::sorting()
{
    sortingQuick(0, data.size() - 1);
}

// Constructor
// Description: Initiates the Sorter
// Entry: A vector of integers
// Output: None
// Precondition: The input vector is not empty
// Postcondition: The input vector is sorted in ascending order
// Complexity: O(n log n) average, O(n^2) worst case (because sorting is called)
Sorter::Sorter(vector<int> initialData)
{
    data = initialData;
    sorting();
}

// Search binary
// Description: This function implements the binary search algorithm to find the position of a value in the sorted vector
// Entry: An integer value to search for
// Output: The index of the value if found, or the index where it should be inserted
// Precondition: The input vector is sorted in ascending order
// Postcondition: The input vector remains sorted in ascending order
// Complexity: O(log n)
int Sorter::searchBinary(int value)
{
    int left = 0;
    int right = data.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (data[mid] == value)
        {
            // we did find in and we get the position, but we return left to use in create
            return mid;
        }
        else if (data[mid] < value)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    // Didn't find it but we still wher eit should go
    return left;
}

// 1. Create
// Description: Add a new value then sort the vector
// Entry: An integer value to add
// Output: None
// Precondition: The input vector is not empty
// Postcondition: The input vector is sorted in ascending order
// Complexity: O(n log n) average, O(n^2) worst case (Because sorting is called)
void Sorter::create(int value)
{
    data.push_back(value);
    sorting();
}

// 2. Search
// Description: This function searches for a value in the sorted vector and returns its index if found, or -1 if not found
// Entry: An integer value to search for
// Output: The index of the value if found, or -1 if not found
// Precondition: The input vector is sorted in ascending order
// Postcondition: The input vector remains sorted in ascending order
// Complexity: O(log n)
// Notes: Valor si si lo encontro, no -1, binary regresa left, para hacer psuh
int Sorter::search(int value)
{
    int where = searchBinary(value);
    if (where < data.size() && data[where] == value)
    {
        // here it does tell me wether it found it or nor, not just wher eis should go
        return where;
    }
    else
    {
        return -1;
    }
}

// 2.5 Get
// Description: This function returns the value at a given index in the vector, or -1 if the index is out of bounds
// Entry: An integer index
// Output: The value at the given index if valid, or -1 if the index is out of bounds
// Precondition: The input vector is not empty
// Postcondition: The input vector remains unchanged
// Complexity: O(1)
int Sorter::get(int index)
{
    if (index >= 0 && index < data.size())
    {
        return data[index];
    }
    else
    {
        return -1;
    }
}

// 3. Update not swap but index
// Description: replaces an element at a certain index with a new value, maintaining the sorted order of the vector
// Entry: An integer index and a new integer value
// Output: None
// Precondition: The input vector is not empty and the index is valid
// Postcondition: The input vector is sorted in ascending order
// Complexity: O(n log n) average, O(n^2) worst case (Because sorting is called)
void Sorter::update(int index, int newValue)
{
    // delete old value according to index
    del(index);

    // we add new value using sorting
    int where = searchBinary(newValue);
    // binray search tells me where the number is supposed to go
    // and even if it doesn't find it it shows me where to put it

    data.insert(data.begin() + where, newValue);
}

// 4. Delete
// Description: removes an element at a certain index from the vector, maintaining the sorted order of the vector
// Entry: An integer index
// Output: None
// Precondition: The input vector is not empty and the index is valid
// Postcondition: The input vector is sorted in ascending order
// Complexity: O(n log n) average, O(n^2) worst case (Because sorting is called)
// Else it would be O(n)
// Note: (if no parameter are given we assume its 0)

void Sorter::del(int index)
{
    if (index < 0 || index >= data.size())
    {
        cout << "Index out of bounds" << endl;
        return;
    }
    data.erase(data.begin() + index);
    sorting();
}

// Print vector
// Description: This function prints the elements of the vector to the console
// Entry: None
// Output: The elements of the vector are printed to the console
// Precondition: The input vector is not empty
// Postcondition: The input vector remains unchanged
// Complexity: O(n)
void Sorter::printVector()
{
    for (int i = 0; i < data.size(); i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

// Read data from file
//  Description: This function reads data from a file and populates the vector with the values read
//  Entry: A string representing the filename
//  Output: The vector is populated with the values read from the file
//  Precondition: The file exists and is readable
//  Postcondition: The input vector is sorted in ascending order
//  Complexity: O(n log n) average, O(n^2) worst case (Because
int Sorter::readDataFromFile(string filename)
{
    ifstream inputFile(filename);

    string line;
    while (getline(inputFile, line))
    {
        stringstream ss(line);
        int command;
        ss >> command;

        switch (command)
        {
        case 1:
        {
            int size;
            ss >> size;

            for (int i = 0; i < size; i++)
            {
                int value;
                ss >> value;
                create(value);
            }

            sorting();

            cout << "Sorted vector: ";
            printVector();
            cout << endl;
            break;
        }
        case 2:
        {
            int value;
            ss >> value;

            int position = search(value);

            if (position != -1)
                cout << "Value " << value << " found at index " << position << endl;
            else
                cout << "Value " << value << " not found" << endl;
            break;
        }
        case 3:
        {
            cout << "Program finished." << endl;
            inputFile.close();
            return 0;
        }
        case 4:
        {
            int value;
            ss >> value;

            create(value);

            cout << "Added " << value << ": ";
            printVector();
            cout << endl;
            break;
        }
        case 5:
        {
            int index, value;
            ss >> index >> value;

            update(index, value);

            cout << "Updated index " << index << " to " << value << ": ";
            printVector();
            cout << endl;
            break;
        }
        case 6:
        {
            int index;
            ss >> index;

            del(index);

            cout << "Deleted index " << index << ": ";
            printVector();
            cout << endl;
            break;
        }
        default:
            break;
        }
    }
    return 0;
}