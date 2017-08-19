#include <iostream>
#include <vector>

using namespace std;

class Matrix
{
public:
    Matrix();
    Matrix(int the_rows, int the_columns);
    void set_columns(int the_columns);
    void set_rows(int the_rows);
    int get_columns() const;
    int get_rows() const;
    void input_matrix();
    friend Matrix operator +(const Matrix& matrix1, const Matrix& matrix2);
    friend Matrix operator -(const Matrix& matrix1, const Matrix& matrix2);
    friend Matrix operator *(const Matrix& matrix1, const Matrix& matrix2);
    friend ostream& operator <<(ostream& outs, const Matrix& m);
private:
    vector< vector<int> > the_vector;
    int rows;
    int columns;
};

Matrix::Matrix()
{
    rows = 0;
    columns = 0;
}

Matrix::Matrix(int the_rows, int the_columns)
{
    rows = the_rows;
    columns = the_columns;
    the_vector.resize(rows);
    for(int i = 0; i < rows; i++)
    {
        the_vector[i].resize(columns);
    }
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
    if(m1.get_rows() != m2.get_rows() || m1.get_columns() != m2.get_columns())
    {
        cout << "Cannot add matrices." << endl;
    }
    else
    {
        Matrix sum_array(m1.get_rows(), m2.get_columns());
        sum_array.the_vector.resize(m1.the_vector.size());
        for(int i = 0; i < m1.the_vector.size(); i++)
        {
            sum_array.the_vector[i].resize(m1.the_vector[i].size());
        }

        for(int i = 0; i < m1.the_vector.size(); i++)
        {
            for(int j = 0; j < m1.the_vector[i].size(); j++)
            {
                sum_array.the_vector[i][j] = m1.the_vector[i][j] + m2.the_vector[i][j];
            }
        }
        return sum_array;
    }
}

Matrix operator -(const Matrix& m1, const Matrix& m2)
{
    if(m1.get_rows() != m2.get_rows() || m1.get_columns() != m2.get_columns())
    {
        cout << "Cannot add matrices." << endl;
    }
    else
    {
        Matrix subtract_array(m1.get_rows(), m2.get_columns());
        subtract_array.the_vector.resize(m1.the_vector.size());
        for(int i = 0; i < m1.the_vector.size(); i++)
        {
            subtract_array.the_vector[i].resize(m1.the_vector[i].size());
        }

        for(int i = 0; i < m1.the_vector.size(); i++)
        {
            for(int j = 0; j < m1.the_vector[i].size(); j++)
            {
                subtract_array.the_vector[i][j] = m1.the_vector[i][j] - m2.the_vector[i][j];
            }
        }
        return subtract_array;
    }
}

Matrix operator *(const Matrix& m1, const Matrix& m2)//, int rows, int columns, int rows2)
{
    //If the first matrix input is a scalar
    if(m1.get_rows() == 1 && m1.get_columns() == 1)
    {
        Matrix product_array(m2.get_rows(), m2.get_columns());
        product_array.the_vector.resize(m2.get_rows());
        for(int i = 0; i < m2.get_rows(); i++)
        {
            product_array.the_vector[i].resize(m2.get_columns());
        }
        for(int i = 0; i < m2.get_rows(); i++)
        {
            for(int j = 0; j < m2.get_columns(); j++)
            {
                product_array.the_vector[i][j] = 0;
            }
        }
        for(int i = 0; i < m2.get_rows(); i++)
        {
            for(int j = 0; j < m2.get_columns(); j++)
            {
                product_array.the_vector[i][j] += m1.the_vector[0][0] * m2.the_vector[i][j];
            }
        }
        return product_array;
    }
    else
    {
        Matrix product_array(m1.get_rows(), m2.get_columns());
        for(int i = 0; i < m1.get_rows(); i++)
        {
            for(int j = 0; j < m2.get_columns(); j++)
            {
                product_array.the_vector[i][j] = 0;
            }
        }
        for(int i = 0; i < m1.get_rows(); i++)
        {
            for(int j = 0; j < m2.get_columns(); j++)
            {
                //product_array[i][j] = 0;
                for(int k = 0; k < m2.get_rows(); k++)
                {
                    product_array.the_vector[i][j] += m1.the_vector[i][k] * m2.the_vector[k][j];
                }
            }
        }
        return product_array;
    }
}

void Matrix::input_matrix()
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            cout << "Please enter the number for row " << i + 1
                 << " and for column " << j + 1 << " : ";
            cin >> the_vector[i][j];
        }
    }
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

int main()
{
    int rows, rows2, columns, columns2;
    char choice;
    int num = 1;
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
    m1.input_matrix();
    cout << endl;
    cout << m1 << endl;

    cout << "Matrix 2" << endl;
    m2.input_matrix();
    cout << endl;
    cout << m2 << endl;

    cout << "Please choose from the following: " << endl;
    cout << "1. Add." << endl;
    cout << "2. Subtract." << endl;
    cout << "3. Multiply." << endl;
    cout << endl;
    cout << "Please enter your selection: ";
    cin >> num;
    if(num == 1)
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
    else if(num == 2)
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
    else if(num == 3)
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

    return 0;
}
