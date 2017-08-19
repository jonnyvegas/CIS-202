//Name: Jonathan Villegas
//Assignment: This calculator will ask the user to input 2 matrices
//or a scalar and one matrix. It will ask first for the number of
//rows, then the number of columns. It will ask for an operation
//*, +, - It will check to see if the result can be calculated,
//and will then calculate and display the matrix from the operation selected.
//Date: 5/29/14
//Email: jonathan.e.villegas@gmail.com
//Filename: main.cpp

#include <iostream>
#include <vector>
#include "matrix.h"

using namespace std;
using namespace villegasmatrix;

int main()
{
    char ch;
    do
    {
        int rows, rows2, columns, columns2;
        int num;

        cout << "Please enter the amount of rows for the first: ";
        cin >> rows;
        cout << "Please enter the amount of columns for the first: ";
        cin >> columns;
        cout << "Please enter the amount of rows for the second: ";
        cin >> rows2;
        cout << "Please enter the amount of columns for the second: ";
        cin >> columns2;

        Matrix m1(rows, columns);
        Matrix m2(rows2, columns2);

        cout << "Matrix 1" << endl;
        cin >> m1;
        cout << endl;
        cout << m1 << endl;

        cout << "Matrix 2" << endl;
        cin >> m2;
        cout << endl;
        cout << m2 << endl;

        cout << "Please choose from the following: " << endl;
        cout << "1. Add." << endl;
        cout << "2. Subtract." << endl;
        cout << "3. Multiply." << endl;
        cout << endl;
        cout << "Please enter your selection: ";
        cin >> num;
        if(num == 1)//Add the matrices
        {
            cout << "Adding matrices..." << endl;
            if(rows == rows2 && columns == columns2)
            {
                Matrix m3(rows, columns);
                m3 = m1 + m2;
                cout << m3 << endl;
            }
            else
            {
                cout << "Cannot add. Not the same size." << endl;
            }
        }
        else if(num == 2)//Subtract the matrices
        {
            cout << "Subtracting matrices..." << endl;
            if(rows == rows2 && columns == columns2)
            {
                Matrix m3(rows, columns);
                m3 = m1 - m2;
                cout << m3 << endl;
            }
            else
            {
                cout << "Cannot subtract. Not the same size." << endl;
            }
        }
        else if(num == 3)//Multiply the matrices
        {
            if(rows == columns2 || (rows == 1 && columns == 1))
            {
                Matrix m4(rows, columns2);
                m4 = m1 * m2;
                cout << m4 << endl;
            }
            else
            {
                cout << "Cannot multiply. Incompatible matrices." << endl;
            }
        }

        cout << "Would you like to try again?(Y/N): ";
        cin >> ch;
    }while(ch != 'n' && ch != 'N');
    cout << "Thanks for using the matrix program. See ya!" << endl;
    return 0;
}
