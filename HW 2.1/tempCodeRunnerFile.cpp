#include <iostream>
#include <vector>
#include "Sorter.h"
#include <string>

// to be able to read the data from the file
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
    cout << "Test Case 1" << endl;
    vector<int> none;
    Sorter sorter(none);
    sorter.readDataFromFile("test_case1.txt");

    cout << "Test Case 2" << endl;
    sorter.readDataFromFile("test_case2.txt");

    cout << "Test Case 3" << endl;
    sorter.readDataFromFile("test_case3.txt");

    cout << "Test Case 4" << endl;
    sorter.readDataFromFile("test_case4.txt");

    return 0;
}
/*
1 sorting followed by the size of the vector and then the values
2 search for a value
3 end the program
4 create a value
5 modify the index i with value x ( i x)
6 delete index i

*/
