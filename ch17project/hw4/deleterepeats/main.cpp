/*
Name: Jonathan Villegas
Filename: main.cpp
Description: Write a function template for a function called delete_repeats
that deletes any duplicate elements in an array and gives the appropriate size
for the partially filled array. The array is adjusted accordingly after delete_repeats
has run.
e-mail address: jonathan.e.villegas@gmail.com
Date: 4/13/14
*/


#include <iostream>
#include "deleterepeats.h"
#include "deleterepeats.cpp"
using namespace std;

int main()
{
    int size = 6;
    char a[10];
    a[0] = 'a';
    a[1] = 'b';
    a[2] = 'a';
    a[3] = 'c';
    a[4] = 'a';
    a[5] = 'd';
    cout << "original size: " << size << endl;
    cout << "original array: ";
    for(int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    delete_repeats(a, size);
    cout << "new size: " << size << endl;
    cout << "new array: ";
    for(int j = 0; j < size; j++)
    {
        cout << a[j] << " ";
    }
    cout << endl;

    size = 8;
    int b[8];
    b[0] = 1;
    b[1] = 23;
    b[2] = 34;
    b[3] = 3;
    b[4] = 1;
    b[5] = 34;
    b[6] = 23;
    b[7] = 5;
    cout << "original size: " << size << endl;
    cout << "original array: ";
    for(int i = 0; i < size; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;
    delete_repeats(b, size);
    cout << "new size: " << size << endl;
    cout << "new array: ";
    for(int j = 0; j < size; j++)
    {
        cout << b[j] << " ";
    }
    cout << endl;

    return 0;
}
