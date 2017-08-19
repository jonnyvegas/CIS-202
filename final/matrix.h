//Name: Jonathan Villegas
//Assignment: This calculator will ask the user to input 2 matrices
//or a scalar and one matrix. It will ask first for the number of
//rows, then the number of columns. It will ask for an operation
//*, +, - It will check to see if the result can be calculated,
//and will then calculate and display the matrix from the operation selected.
//Date: 5/29/14
//Email: jonathan.e.villegas@gmail.com
//Filename: matrix.h

#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
#include <vector>
#include <iostream>
using namespace std;

namespace villegasmatrix
{
    class Matrix
    {
    public:
        //Constructors
        Matrix();
        Matrix(int the_rows, int the_columns);
        //Mutators
        void set_columns(int the_columns);
        void set_rows(int the_rows);
        //Accessors
        int get_columns() const;
        int get_rows() const;
        //Overloaded operators
        friend Matrix operator +(const Matrix& matrix1, const Matrix& matrix2);
        friend Matrix operator -(const Matrix& matrix1, const Matrix& matrix2);
        friend Matrix operator *(const Matrix& matrix1, const Matrix& matrix2);
        //Formatted to ask to input the matrix in order.
        friend istream& operator >>(istream& ins, Matrix& m);
        //Formatted to output the matrix surrounded by braces [].
        friend ostream& operator <<(ostream& outs, const Matrix& m);
    private:
        vector< vector<int> > the_vector;
        int rows;
        int columns;
    };
}

#endif // MATRIX_H_INCLUDED
