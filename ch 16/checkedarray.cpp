//Name: Jonathan Villegas
//Description:   Define a class named CheckedArray. The objects of this
//class are like regular arrays but have range checking. If a is an object
//of the class CheckedArray
//and i is an illegal index then use of a[i]will cause your program to throw
//an exception (an object) of the class ArrayOutOfRangeError.
//Date: 5/18/14
//Email: jonathan.e.villegas@gmail.com
//File: checkedarray.cpp

#include <iostream>
using namespace std;

class ArrayOutOfRangeError
{};

template <class T>
class CheckedArray
{
public:
    //Constructor
    CheckedArray(int the_size);
    //Operator overload
    T& operator[](int index);
    //Returns the value at the index.
    T get_value(int index);
    //Adds the value to the array.
    void add_value(T the_val, int the_value);
private:
    int *value;
    int size;
};
template <class T>
CheckedArray<T>::CheckedArray(int the_size)
{
    value = new T[the_size];
    size = the_size;
}
template <class T>
T& CheckedArray<T>::operator[](int index)
{
    //If the index is out of range
    if(index < 0 || index >= size)
    {
        throw ArrayOutOfRangeError();
    }
    //else return the value at the index.
    return value[index];
}

template <class T>
T CheckedArray<T>::get_value(int index)
{
    //If the value accessed is not in the range
    if(index < 0 || index >= size)
    {
        throw ArrayOutOfRangeError();
    }
    return value[index];
}

template <class T>
void CheckedArray<T>::add_value(T the_val, int index)
{
    if(index < 0 || index >= size)
    {
        throw ArrayOutOfRangeError();
    }
    value[index] = the_val;
}

int main()
{
    int num, input;
    //Construct an array of 10 numbers.
    CheckedArray<int> a(10);
    try
    {
        for(int i = 0; i < 10; i++)
        {
            cout << "Please enter value " << i + 1 << ": ";
            cin >> num;
            a[i] = num;
        }
        cout << "Enter value 11: ";
        cin >> num;
        a[10] = num;
    }
    catch(ArrayOutOfRangeError)
    {
        int num2;
        cout << "You tried to access an illegal index!!!" << endl;
        cout << "Which index did you want to access?: ";
        cin >> num;
        cout << "What did you want to store in there?: ";
        cin >> num2;
        a.add_value(num2,num);
    }
    cout << "You entered: " << endl;
    for (int j = 0; j < 10; j++)
    {
        cout << a[j] << " ";
    }
    cout << endl;
    return 0;
}
