//Name: Jonathan Villegas
//Assignment: This calculator will ask the user to input 2 matrices
//or a scalar and one matrix. It will ask first for the number of
//rows, then the number of columns. It will ask for an operation
//*, +, - It will check to see if the result can be calculated,
//and will then calculate and display the matrix from the operation selected.
//Date: 5/29/14
//Email: jonathan.e.villegas@gmail.com
//Filename: matrix.cpp

#include <iostream>
#include <vector>
#include "matrix.h"

using namespace std;

namespace villegasmatrix
{
    Matrix::Matrix()
    {
        rows = 0;
        columns = 0;
    }

    Matrix::Matrix(int the_rows, int the_columns)
    {
        rows = the_rows;
        columns = the_columns;
        //Must make size of matrix 2 dimensions.
        the_vector.resize(rows);
        for(int i = 0; i < rows; i++)
        {
            the_vector[i].resize(columns);
        }
        //Initialize all entries in the matrix to 0 upon construction.
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < columns; j++)
            {
                the_vector[i][j] = 0;
            }
        }
    }

    void Matrix::set_rows(int the_rows)
    {
        rows = the_rows;
    }

    void Matrix::set_columns(int the_columns)
    {
        columns = the_columns;
    }

    int Matrix::get_rows() const
    {
        return rows;
    }

    int Matrix::get_columns() const
    {
        return columns;
    }

    Matrix operator +(const Matrix& m1, const Matrix& m2)
    {
        //Matrices must have the same dimensions to add.
        //Else we return a matrix with 0, 0 for dimensions.
        if(m1.get_rows() != m2.get_rows() || m1.get_columns() != m2.get_columns())
        {
            cout << "Cannot add matrices." << endl;
            Matrix sum(0, 0);
            return sum;
        }
        //Otherwise the columns and rows are the same size. They can be added.
        else
        {
            Matrix sum(m1.get_rows(), m2.get_columns());
            //Initialize matrix to proper size.
            sum.the_vector.resize(m1.the_vector.size());
            for(unsigned int i = 0; i < m1.the_vector.size(); i++)
            {
                sum.the_vector[i].resize(m1.the_vector[i].size());
            }
            //Add the matrices.
            for(unsigned int i = 0; i < m1.the_vector.size(); i++)
            {
                for(unsigned int j = 0; j < m1.the_vector[i].size(); j++)
                {
                    sum.the_vector[i][j] = m1.the_vector[i][j] + m2.the_vector[i][j];
                }
            }
            return sum;
        }
    }

    Matrix operator -(const Matrix& m1, const Matrix& m2)
    {
        //Matrices must have the same dimensions to subtract.
        //Else we return a matrix with 0, 0 for dimensions.
        if(m1.get_rows() != m2.get_rows() || m1.get_columns() != m2.get_columns())
        {
            Matrix difference(0, 0);
            cout << "Cannot add matrices." << endl;
            return difference;
        }
        //Rows and columns same size. Can subtract.
        else
        {
            Matrix difference(m1.get_rows(), m2.get_columns());
            //Initialize to proper size.
            difference.the_vector.resize(m1.the_vector.size());
            for(unsigned int i = 0; i < m1.the_vector.size(); i++)
            {
                difference.the_vector[i].resize(m1.the_vector[i].size());
            }
            //Subtract the matrices.
            for(unsigned int i = 0; i < m1.the_vector.size(); i++)
            {
                for(unsigned int j = 0; j < m1.the_vector[i].size(); j++)
                {
                    difference.the_vector[i][j] = m1.the_vector[i][j] - m2.the_vector[i][j];
                }
            }
            return difference;
        }
    }

    Matrix operator *(const Matrix& m1, const Matrix& m2)
    {
        //If the first matrix input is a scalar
        if(m1.get_rows() == 1 && m1.get_columns() == 1)
        {
            Matrix product(m2.get_rows(), m2.get_columns());
            product.the_vector.resize(m2.get_rows());
            for(int i = 0; i < m2.get_rows(); i++)
            {
                product.the_vector[i].resize(m2.get_columns());
            }
            //Initialize the product matrix
            for(int i = 0; i < m2.get_rows(); i++)
            {
                for(int j = 0; j < m2.get_columns(); j++)
                {
                    product.the_vector[i][j] = 0;
                }
            }
            //Multiply every entry in the second matrix by the only number
            //in the first matrix, since it is a scalar.
            for(int i = 0; i < m2.get_rows(); i++)
            {
                for(int j = 0; j < m2.get_columns(); j++)
                {
                    product.the_vector[i][j] += m1.the_vector[0][0] * m2.the_vector[i][j];
                }
            }
            return product;
        }
        //Matrices are incompatible. Return a matrix with 0 rows and columns.
        else if(m1.get_rows() != m2.get_columns())
        {
            Matrix product(0,0);
            cout << "Cannot multiply. Incompatible matrices." << endl;
            return product;
        }
        //Else it is not a scalar and the rows of the 1st equal the columns of the 2nd.
        //They can be multiplied.
        else
        {
            Matrix product(m1.get_rows(), m2.get_columns());
            //Initialize the array to 0, since we need to add the products
            //to these entries.
            for(int i = 0; i < m1.get_rows(); i++)
            {
                for(int j = 0; j < m2.get_columns(); j++)
                {
                    product.the_vector[i][j] = 0;
                }
            }
            //Multiply the matrices.
            for(int i = 0; i < m1.get_rows(); i++)
            {
                for(int j = 0; j < m2.get_columns(); j++)
                {
                    for(int k = 0; k < m2.get_rows(); k++)
                    {
                        product.the_vector[i][j] += m1.the_vector[i][k] * m2.the_vector[k][j];
                    }
                }
            }
            return product;
        }
    }

    istream& operator >>(istream& ins, Matrix& m)
    {
        for(int i = 0; i < m.get_rows(); i++)
        {
            for(int j = 0; j < m.get_columns(); j++)
            {
                cout << "Please enter the number for row " << i + 1
                     << " and for column " << j + 1 << " : ";
                ins >> m.the_vector[i][j];
            }
        }
        return ins;
    }

    ostream& operator <<(ostream& outs, const Matrix& m)
    {
        for(int i = 0; i < m.get_rows(); i++)
        {
            outs << "[";
            for(int j = 0; j < m.get_columns(); j++)
            {
                outs << m.the_vector[i][j];
                if((j != (m.get_columns() - 1)))
                    outs << ", ";
            }
            outs << "]" << endl;
        }
        return outs;
    }
}
