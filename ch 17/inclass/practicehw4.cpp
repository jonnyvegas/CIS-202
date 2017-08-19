#include <iostream>
using namespace std;

template <class BaseType>
void delete_repeats(BaseType a[], int &size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            if (a[i] == a[j])
            {
                for(int k = j; k < size; k++)
                {
                    a[k] = a[k+1];
                }
                size--;
            }
        }
    }
}

int main()
{
    int size = 6;
    char a[10];
    a[0] = 'a';
    a[1] = 'b';
    a[2] = 'a';
    a[3] = 'c';
    a[4] = 'a';
    a[5] = 'd';
    cout << "original size: " << size << endl;
    cout << "original array: ";
    for(int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    delete_repeats(a, size);
    cout << "new size: " << size << endl;
    cout << "new array: ";
    for(int j = 0; j < size; j++)
    {
        cout << a[j] << " ";
    }
    cout << endl;

    size = 8;
    int b[8];
    b[0] = 1;
    b[1] = 23;
    b[2] = 34;
    b[3] = 3;
    b[4] = 1;
    b[5] = 34;
    b[6] = 23;
    b[7] = 5;
    cout << "original size: " << size << endl;
    cout << "original array: ";
    for(int i = 0; i < size; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;
    delete_repeats(b, size);
    cout << "new size: " << size << endl;
    cout << "new array: ";
    for(int j = 0; j < size; j++)
    {
        cout << b[j] << " ";
    }
    cout << endl;

    return 0;
}
