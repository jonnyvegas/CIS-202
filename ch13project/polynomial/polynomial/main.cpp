//Name: Jonathan Villegas
//Assignment: Design and implement a class whose objects represent polynomials. The
//polynomial will be implemented as a linked list. Each node will contain an int value
//for the power of x and an int value for the corresponding coefficient. The
//class operations should include addition, subtraction, multiplication, and
//evaluation of a polynomial. Overload the operators +, -, and * for
//addition, subtraction, and multiplication
//Date: 4/13/14
//Email: jonathan.e.villegas@gmail.com
//filename: main.cpp


#include <iostream>
#include <math.h>
#include "polynomial.h"
using namespace std;
using namespace villegaspolynomial;

int main()
{
    Polynomial p1, p2, p3;
    cout << "Please enter a polynomial: ";
    p1.input();
    p1.output();

    cout << "Please enter another polynomial: ";
    p2.input();
    p2.output();

    p3 = p1 + p2;
    cout << "Added together: " << endl;
    p3.output();

    p3 = p1 - p2;
    cout << "Subtracted: " << endl;
    p3.output();

    p3 = p1 * p2;
    cout << "Multiplied: " << endl;
    p3.output();

    int v1, v2, ans1, ans2;
    cout << "Please enter an integer to evaluate for x for the 1st: ";
    cin >> v1;
    cin.ignore(1);//Must be ignored or '\n' will be passed.

    ans1 = p1.evaluate(v1);
    cout << "The answer to the 1st with " << v1 << " plugged in is: " << endl;
    cout << ans1 << endl;

    cout << "Please enter an integer to evaluate for x for the 2nd: ";
    cin >> v2;
    cin.ignore(1);//Must be ignored or '\n' will be passed.

    ans2 = p2.evaluate(v2);
    cout << "The answer to the 2nd with " << v2 << " plugged in is: " << endl;
    cout << ans2 << endl;

    return 0;
}
