//
// File: ch9_ex4.cpp
// Description: This program takes a string input and outputs
// the string in reverse.
// Created: 2/6/14
// Author: Jonathan Villegas
// mail: jonathan.e.villegas@gmail.com
//
#include <iostream>
#include <cstring>

void revString(char a[],int size);
//Precondition: A string is entered into the screen.
//Postcondition: The string is printed to the screen in reverse order.

int main()
{
    using namespace std;

    const int MAX_NUMBER = 81;//Maximum size of an array.
    char input[MAX_NUMBER];
    int length;

    cout << "This program will take a string as input and output the string in reverse." << endl;
    cout << "Please input a string (less than 80 characters): ";

    cin.getline(input, MAX_NUMBER);

    length = strlen(input);  //Stores the length of the string input into int length.

    cout << endl;
    cout << "In reverse, the string is: ";

    revString(input, length);  //Uses length to pass the size of the array to revString.

    return 0;
}

void revString(char a[], int size)
{
    using namespace std;

    int count = size;//Need to create a new count variable or only half of the loop will iterate.
    int i = 0;
    char *Front, *Rear;

    Front = new char;
    Rear = new char;

    *Front = a[i];      //Points to the first char in the array.
    *Rear = a[size - 1];//Points to the last char in the array.

    for (int j = 0; j <= size; j++)
    {
        char *temp;

        *temp = *Front;  //Swaps the front and rear pointers by changing what is in
        *Front = *Rear;  //the memory locations being pointed to using a temp pointer.
        *Rear = *temp;

        *Rear = a[count--]; //Points to the previous char in the array.
        *Front = a[i++];    //Points to the next char in the array.

        cout << *Rear;
    }
}
