#pragma once

#include <iostream>
using namespace std;
#include <vector>
#include <string>

class Sorter
{
private:
    vector<int> data;

public:
    Sorter(vector<int> initialData);
    // Create
    void create(int value);
    // Search
    int search(int value);
    // Get
    int get(int index);
    // Update
    void update(int index, int newValue);
    // Delete
    void del(int index = 0);

    // Sorting method
    void sorting();
    void sortingQuick(int left, int right);
    // we have to sorting functions because one calls the other, and we need to call the first one without parameters

    // Search algorithm (not really necessary but I want to apply what we saw in class)
    int searchBinary(int value);

    void printVector();

    int readDataFromFile(string filename);
};