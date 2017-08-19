/*
Name: Jonathan Villegas
Filename: main.cpp
Description: Write a function template for a function that has parameters for a partially
filled array and for a value of the base type of the array. If the value is in
the partially filled array, then the function returns the index of the first
indexed variable that contains the value. If the value is not in the array,
the function returns -1.
Date: 4/13/14
e-mail address: jonathan.e.villegas@gmail.com
*/

#include <iostream>
#include <string>
#include "findposition.h"
#include "findposition.cpp"
using namespace std;

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int the_index;
    int the_num;
    cout << "Please enter the number to find: ";
    cin >> the_num;
    the_index = find_item(a, the_num, 15);
    if(the_index != -1)
        cout << the_num << " was found in position: " << the_index << endl;
    else //the_index == -1
        cout << the_num << " was not found in the array." << endl;

    char b[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    char the_letter;
    cout << "Please enter the letter to find: ";
    cin >> the_letter;
    the_index = find_item(b, the_letter, 10);
    if(the_index != -1)
        cout << the_letter << " was found in position: " << the_index << endl;
    else //the_index == -1
        cout << the_letter << " was not found in the array." << endl;

    string c[] = {"John", "Bob", "Ed", "Pete", "Shawn", "Larry", "Jeff", "Eric"};
    string the_name;
    cout << "Please enter the name to find: ";
    cin >> the_name;
    the_index = find_item(c, the_name, 8);
    if(the_index != -1)
        cout << the_name << " was found in position: " << the_index << endl;
    else //the_index == -1
        cout << the_name << " was not found in the array." << endl;
    return 0;
}
