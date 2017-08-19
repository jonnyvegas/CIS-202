#include <iostream>
#include "rational.h"
using namespace std;
using namespace villegasrational;

int main()
{
    Rational first, second, third;

    cout << "Please enter the first fraction: ";
    cin >> first;
    reduce(first);
    cout << "Please enter the second fraction: ";
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
    return 0;
}
