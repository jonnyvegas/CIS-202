#include <iostream>
#include <vector>

using namespace std;



void initialize_vector(vector< vector<int> >& the_vector, int rows, int columns)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            the_vector[i][j] = 0;
        }
    }
}

vector< vector<int> > add_arrays(vector< vector<int> > array1, vector< vector<int> > array2)
{
    vector< vector<int> > sum_array;
    sum_array.resize(array1.size());
    for(int i = 0; i < array1.size(); i++)
    {
        sum_array[i].resize(array1[i].size());
    }

    for(int i = 0; i < array1.size(); i++)
    {
        for(int j = 0; j < array1[i].size(); j++)
        {
            sum_array[i][j] = array1[i][j] + array2[i][j];
        }
    }
    return sum_array;
}

vector< vector<int> > subtract_arrays(vector< vector<int> > array1, vector< vector<int> > array2)
{
    vector< vector<int> > subtract_array;
    subtract_array.resize(array1.size());
    for(int i = 0; i < array1.size(); i++)
    {
        subtract_array[i].resize(array1[i].size());
    }

    for(int i = 0; i < array1.size(); i++)
    {
        for(int j = 0; j < array1[i].size(); j++)
        {
            subtract_array[i][j] = array1[i][j] - array2[i][j];
        }
    }
    return subtract_array;
}

vector< vector<int> > multiply_arrays(vector< vector<int> > array1, vector< vector<int> > array2, int rows, int columns, int rows2)
{
    vector< vector<int> > product_array;
    product_array.resize(rows);
    for(int i = 0; i < rows; i++)
    {
        product_array[i].resize(columns);
    }
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            product_array[i][j] = 0;
        }
    }
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            product_array[i][j] = 0;
            for(int k = 0; k < rows2; k++)
            {
                product_array[i][j] += array1[i][k] * array2[k][j];
            }
        }
    }
    return product_array;
}

void input_vector(vector< vector<int> >& the_vector, int rows, int columns)
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

void print_vector(vector< vector<int> > the_vector, int row_size, int column_size)
{
    for(int i = 0; i < row_size; i++)
    {
        cout << "[";
        for(int j = 0; j < column_size; j++)
        {
            cout << the_vector[i][j];
            if((j != (column_size - 1)))
                cout << ", ";
        }
        cout << "]" << endl;
    }
}

int main()
{
    int rows, rows2, rows3, columns, columns2, columns3;
    cout << "Please enter the amount of rows for the first: ";
    cin >> rows;
    cout << "Please enter the amount of columns for the first: ";
    cin >> columns;
    cout << "Please enter the amount of rows for the second: ";
    cin >> rows2;
    cout << "Please enter the amount of columns for the second: ";
    cin >> columns2;

    vector< vector<int> > array;
    vector< vector<int> > array2;
    vector< vector<int> > sum_array;
    vector< vector<int> > product_array;
    array.resize(rows);
    array2.resize(rows2);
    sum_array.resize(rows);
    product_array.resize(rows);

    for(int i = 0; i < rows; i++)
    {
        array[i].resize(columns);
        sum_array[i].resize(columns);
        product_array[i].resize(columns2);
    }
    for(int i = 0; i < rows2; i++)
    {
        array2[i].resize(columns2);
    }

    initialize_vector(array, rows, columns);
    initialize_vector(array2, rows2, columns2);
    initialize_vector(sum_array, rows, columns);
    initialize_vector(product_array, rows, columns2);
    cout << "Matrix 1" << endl;
    input_vector(array,rows, columns);
    print_vector(array, rows, columns);

    cout << "Matrix 2" << endl;
    input_vector(array2,rows2, columns2);
    print_vector(array2, rows2, columns2);

    cout << "Adding matrices..." << endl;
    if(rows == rows2 && columns == columns2)
    {
        sum_array = add_arrays(array, array2);
        print_vector(sum_array,rows, columns);
    }
    else
    {
        cout << "Cannot add. Not the same size." << endl;
    }


    cout << "Subtracting matrices..." << endl;
    if(rows == rows2 && columns == columns2)
    {
        sum_array = subtract_arrays(array, array2);
        print_vector(sum_array, rows, columns);
    }
    else
    {
        cout << "Cannot subtract. Not the same size." << endl;
    }

    cout << "Multiplying matrices..." << endl;
    if(rows == columns2)
    {
        product_array = multiply_arrays(array, array2, rows, columns2, rows2);
        print_vector(product_array, rows, columns2);
    }
    else
    {
        cout << "Cannot multiply. Incompatible matrices." << endl;
    }
    return 0;
}
