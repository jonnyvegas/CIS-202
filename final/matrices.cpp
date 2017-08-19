#include <iostream>

using namespace std;

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
    int** array3;
    if(rows > rows2)
    {
        rows3 = rows;
        array3 = new int*[rows3];
    }
    else
    {
        rows3 = rows2;
        array3 = new int*[rows3];
    }
    if(columns > columns2)
    {
        columns3 = columns;
        //columns2 = columns;
        for(int i = 0; i < columns; i++)
        {
            array3[i] = new int[columns3];
        }
    }
    else
    {
        columns3 = columns2;
        for(int i = 0; i < columns2; i++)
        {
            array3[i] = new int[columns3];
        }
    }

    int** array = new int*[rows];
    int** array2 = new int*[rows2];

    for(int i = 0; i < rows; i++)
    {
        array[i] = new int[columns];
    }
    for(int i = 0; i < rows2; i++)
    {
        array2[i] = new int[columns2];
    }

    cout << "Matrix 1" << endl;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            cout << "Please enter the number for row " << i + 1 << endl;
            cout << "And the number for column " << j + 1 << " : ";
            cin >> array[i][j];
        }
    }
    for(int i = 0; i < rows; i++)
    {
        cout << "[";
        for(int j = 0; j < columns; j++)
        {
            cout << array[i][j];
            if((j != (columns - 1)))
                cout << ", ";
        }
        cout << "]" << endl;
    }
    cout << "Matrix 2" << endl;
    for(int i = 0; i < rows2; i++)
    {
        for(int j = 0; j < columns2; j++)
        {
            cout << "Please enter the number for row " << i + 1 << endl;
            cout << "And the number for column " << j + 1 << " : ";
            cin >> array2[i][j];
        }
    }
    for(int i = 0; i < rows2; i++)
    {
        cout << "[";
        for(int j = 0; j < columns2; j++)
        {
            cout << array2[i][j];
            if((j != (columns2 - 1)))
                cout << ", ";
        }
        cout << "]" << endl;
    }

    cout << "Size of 3rd array rows: " << rows3 << endl;
    cout << "Size of 3rd array column: " << columns3 << endl;
    cout << "Adding" << endl;
    for(int i = 0; i < rows2; i++)
    {
        for(int j = 0; j < columns2; j++)
        {
            array3[i][j] = array2[i][j] + array[i][j];
        }
    }
    /*
    for(int i = rows2; i < rows3; i++)
    {
        for(int j = columns2; i < columns2; j++)
        {
            array3[i][j] = array[i][j];
        }
    }
    */
    for(int i = 0; i < rows3; i++)
    {
        cout << "[";
        for(int j = 0; j < columns3; j++)
        {
            cout << array3[i][j];
            if((j != (columns3 - 1)))
                cout << ", ";
        }
        cout << "]" << endl;
    }
    return 0;
}
