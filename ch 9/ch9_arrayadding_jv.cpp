//
// File: ch9_arrayadding_jv.cpp
// Description: This program takes an input of two numbers,
// puts them into an array, and outputs the added result
// Created: 2/18/14
// Author: Jonathan Villegas
// e-mail: jonathan.e.villegas@gmail.com
//
#include <iostream>

typedef int* intArrayPtr;

void greeting();
void sizeOfArrays(int& size1, int& size2, int& size3);
//Once the user enters the size of the arrays in the keyboard, they will be set.
//Larger will be set to the larger size of the two array sizes entered.
//Size 3 will also be set to the larger of the two
void fillArray(int a[], int size, int size3);
//Fills the array according to size. Places extra 0s as placeholders
//to be stored in the array to be added by addArrays.
void addArrays(int a1[], int size1, int a2[], int size2, int a3[], int size3);
//Both arrays should be added together and their result will be
//printed to the screen.
char loop();
//Loop to see if the user would like to continue the program.

int main()
{
    int size1 = 0, size2 = 0, size3 = 0;
    intArrayPtr a1, a2, a3;
    char ans;

    greeting();

    do
    {
    sizeOfArrays(size1, size2, size3);

    a1 = new int[size3];  //This will make the arrays both the appropriate size
    a2 = new int[size3];  //to hold the array.

    fillArray(a1, size1, size3);
    fillArray(a2, size2, size3);

    a3 = new int[size3];

    addArrays(a1, size1, a2, size2, a3, size3);
    ans = loop();
    } while (ans != 'n' && ans != 'N');
    return 0;
}

void greeting()
{
    using namespace std;

    cout << "Hello! This program will take two numbers of a length" << endl;
    cout << "of your choosing and will output the result." << endl;
    cout << endl;
}

void sizeOfArrays(int& size1, int& size2, int& size3)
{
    using namespace std;

    cout << "Please enter the size of array 1: ";
    cin >> size1;
    cout << "Please enter the size of array 2: ";
    cin >> size2;

    if (size1 >= size2)
        size3 = size1;
    else
        size3 = size2;
}

void fillArray(int a[], int size, int size3)
{
    using namespace std;

    char digitArr[size];
    char next;

    cout << "Please enter a number of length " << size << ": ";

    cin.get(next);
    if (next == '\n')       //This allows us to type in two numbers and not have the
        cin.get(next);      //'\n' character carry over.


    int i = 0;
    while (isdigit(next) && i < size) //Loop to fill digitArr with numbers as characters.
    {
        digitArr[i] = next;
        i++;
        cin.get(next);
    }

    int  j = 0;
    while (j < size)
    {
        i--;
        a[j] = digitArr[i] - '0'; //Conversion from char to int leaves
        j++;                      //ASCII 48 or '0' char. Needs to be removed
    }                             //to get appropriate number for array since
    if (size < size3)             //converted from char to int.
    {
        for(int i = size; i < size3; i++)  //If the size for the array is smaller
            a[i] = 0;                       //than the larger size, the rest of the
    }                                       //array is filled with 0's. If not,
}                                           //may access invalid array elements.

void addArrays(int a1[], int size1, int a2[], int size2, int a3[], int size3)
{
    using namespace std;

    int carry = 0;                      //Integer to carry a 1 over if the total of
                                        //the two array elements is more than 10.
    for (int i = 0; i < size3; i++)
    {
        a3[i] = a1[i] + a2[i] + carry;
        if (a3[i] > 9)                  //If the two elements in a1
        {                               //and a2 were greater than 9,
            carry = 1;                  //carry gets the 1 and the number
            a3[i] = a3[i] - 10;         //stored in the a3 element gets
        }                               //subtracted by 10 to get the
        else                            //appropriate number.
            carry = 0;                  //Carry is then added on the next
    }                                   //iteration of the loop.
    cout << endl;
    cout << "The answer is: ";
    if (carry == 1)
    {
        a3[size3] = carry;
        for (int j = size3; j >= 0; j--) //Must be output backward for the loop.
            cout << a3[j];               //Since there is a 1 carried into this
    }                                    //array we must print that, too.
    else
    {
        for (int j = size3 - 1; j >= 0; j--)
            cout << a3[j];
    }
    cout << endl;
}

char loop()
{
    using namespace std;

    char ans;

    cout << "Would you like to add again? (Y/N): ";
    cin >> ans;
    return ans;
}
