#include <iostream>
using namespace std;

// TEMPLATES

template <typename T>
T suma(T n1, T n2, T n3)
{
    return n1 + n2 + n3;
}
/*
int main()
{
    int a = 5, b = 10, c = 15;
    double d1 = 5.5, d2 = 10.5, d3 = 15.5;

    cout << "Suma de enteros: " << suma(a, b, c) << std::endl;
    cout << "Suma de doubles: " << suma(double(a), d2, d3) << std::endl;

    return 0;
}
    */

// Struct
template <typename T>
struct Box
{
    T value_attribute;
    void show()
    {
        cout << value_attribute << endl;
    }
};

struct point
{
    float x;
    float y;
};

struct node
{
    int value;
    node *left;
    node *right;
    // node: a node is something that has a value and two pointers to other nodes, left and right
};

int main(int argc, char *argv[])
{
    Box<string> box1;
    box1.value_attribute = "Hello, World!";
    Box<double> box2;
    box2.value_attribute = 3.14159;

    box1.show();
    box2.show();

    return 0;
}