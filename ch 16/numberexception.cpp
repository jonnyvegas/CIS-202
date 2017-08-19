//Name: Jonathan Villegas
//Description:  Write a program that inputs numeric values from 1
//through 10 and outputsa textual histogram of the values using *’s
//to count the number of occurrences of each value.
//The program should first ask the user how many numbers to enter.
//If the user enters a value that does not consist of all digits
//or a number outside the range 1 to 10, then an exception should be
//caught.
//Date: 5/18/14
//Email: jonathan.e.villegas@gmail.com
//File: numberexception.cpp

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class NumsOnly
{};

class OutOfRange
{};

//Returns a string as an integer.
int string_to_int(string the_string) throw (NumsOnly, OutOfRange)
{
    string::iterator iter;
    int the_num;
    //Check the string to see if it is all digits. Throw an exception if not.
    for(iter = the_string.begin(); iter != the_string.end(); iter++)
    {
        if(!isdigit(*iter))
        {
            throw NumsOnly();
        }
    }
    //If the number is not 1-10. Throw an exception if not.
    if((atoi(the_string.c_str()) < 1) || (atoi(the_string.c_str()) > 10))
    {
        throw OutOfRange();
    }
    //else, return the string as an integer.
    return atoi(the_string.c_str());
}

//Fills the array based on the size. Dynamic array.
void fill_array(int a[], int size)
{
    string the_num;
    int the_int;
    //Loop through and have user enter each number.
    for(int i = 0; i < size; i ++)
    {
        bool correct_input = false;//Must be false to enter while loop.
        cout << "Enter number " << i + 1 << ": ";
        cin >> the_num;
        while(!correct_input)
        {
            try
            {
                the_int = string_to_int(the_num);
                //If input was correct, break loop.
                correct_input = true;
            }
            catch(NumsOnly)
            {
                //Input was not correct.
                correct_input = false;
                cout << "You entered a non number." << endl;
                cout << "Try again. Please re-enter number " << i + 1 << ": ";
                cin >> the_num;
            }
            catch(OutOfRange)
            {
                //Input was not correct.
                correct_input = false;
                cout << "You entered a number outside of the range 1 - 10." << endl;
                cout << "Try again. Please re-enter number " << i + 1 << ": ";
                cin >> the_num;
            }
        }
        //If input was correct, we add the number to the array.
        a[i] = the_int;
    }
}
//Prints the array.
void print_array(int a[], int size)
{
    //Check each number 1-10.
    for(int i = 0; i < 10; i++)
    {
        //Print out the current.
        cout << i + 1 << ":";
        //Loop through each element in the array
        for(int j = 0; j < size; j++)
        {
            if(a[j] == (i + 1))//if the current element is the same as the outer loop's number print a star
            {
                cout << "*";
            }
        }
        cout << endl;
    }
}

int main()
{
    string input;
    typedef int* IntPtr;
    IntPtr the_ptr;

    cout << "How many numbers would you like to enter?: ";
    cin >> input;

    the_ptr = new int[atoi(input.c_str())];
    fill_array(the_ptr, atoi(input.c_str()));
    print_array(the_ptr, atoi(input.c_str()));

    return 0;
}
