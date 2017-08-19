//Name: Jonathan Villegas
//Assignment: Define a class for rational numbers. A rational number is a number that
//can be represented as the quotient of two integers. Represent rational numbers as two values
//of type int, one for the numerator and one for the denominator.
//Also include functions to add, subtract, multiply, and divide the numbers.
//Date: 4/3/14
//Email: jonathan.e.villegas@gmail.com
//filename: main.cpp

#include <iostream>
#include "rational.h"
using namespace std;
using namespace villegasrational;

int main()
{
    Rational first, second, third;

    char ans;
    do
    {
        cout << "Please enter the first fraction, separated by a slash(/): ";
        cin >> first;
        reduce(first);//reduces the fraction
        cout << "Please enter the second fraction, separated by a slash(/): ";
        cin >> second;
        reduce(second);

        cout << "First fraction: " << first << endl;
        cout << "Second fraction: " << second << endl;

        if (first == second)
            cout << first << " is equal to " << second << "." << endl;
        else
            cout << first << " does not equal " << second << "." << endl;

        if(first < second)
            cout << first << " less than " << second << "." << endl;
        else
            cout << first << " is not less than " << second << "." << endl;

        if(first <= second)
            cout << first << " less than or equal to " << second << "." << endl;
        else
            cout << first << " is not less than or equal to " << second << "." << endl;

        if(first > second)
            cout << first << " greater than " << second << "." << endl;
        else
            cout << first << " is not greater than " << second << "." << endl;

        if(first >= second)
            cout << first << " greater than or equal to " << second << "." << endl;
        else
            cout << first << " is not greater than or equal to " << second << "." << endl;

        third = first * second;
        reduce(third);
        cout << first << " times " << second << " equals " << third << endl;

        third = first + second;
        reduce(third);
        cout << first << " plus " << second << " equals " << third << endl;

        third = first - second;
        reduce(third);
        cout << first << " minus " << second << " equals " << third << endl;

        third = first / second;
        reduce(third);
        cout << first << " divided by " << second << " equals " << third << endl;
        cout << endl;
        cout << "Would you like to try another two rational numbers?(Y/N): ";
        cin >> ans;
    }while(ans != 'N' && ans != 'n');
    return 0;
}
