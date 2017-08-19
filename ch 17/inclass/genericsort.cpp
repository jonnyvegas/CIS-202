//Name: Jonathan Villegas
//Assignment: Define a generic print array class for
//types with arrays and the size.
//Date: 4/8/14
//Email: jonathan.e.villegas@gmail.com
//filename: generic_print_array.cpp

#include<iostream>
#include<string>

using namespace std;

template <class T>
void print_array(const T a[], int size_of_array)
{
    for(int index = 0; index < size_of_array; index++)
    {
        if(index == size_of_array - 1)//last element. Don't print a comma.
        {
            cout << a[index] << "." <<endl;
        }
        else//Not the last element.
        {
            cout << a[index] << ", ";
        }
    }
}

template<class T>
void swap_values(T& variable1, T& variable2)
{
    T temp;

    temp = variable1;
    variable1 = variable2;
    variable2 = temp;
}
template<class BaseType>
int index_of_smallest(const BaseType a[], int start_index, int number_used)
{
    BaseType min = a[start_index];
    int index_of_min = start_index;

    for (int index = start_index + 1; index < number_used; index++)
        if (a[index] < min)
        {
            min = a[index];
            index_of_min = index;
            //min is the smallest of a[start_index] through a[index]
        }

    return index_of_min;
}

template<class BaseType>
void sort(BaseType a[], int number_used)
{
    int index_of_next_smallest;
    for(int index = 0; index < number_used - 1; index++)
       {//Place the correct value in a[index]:
             index_of_next_smallest =
                  index_of_smallest(a, index, number_used);
             swap_values(a[index], a[index_of_next_smallest]);
          //a[0] <= a[1] <=...<= a[index] are the smallest of the original array
          //elements. The rest of the elements are in the remaining positions.
       }
}


int main()
{

    int ar1[] = {3,8,2,9,7,5,6,8,1};
    double ar2[] = {3.5,8.7,2.1,9.9,7.3,5.4,6.8,8.7,1.9};
    string ar3[] = {"oranges","bananas","apples","pineapples"};
    cout << "Before sorting: " << endl;
    print_array(ar1,9);
    print_array(ar2,9);
    print_array(ar3,4);


    sort(ar1,9);
    sort(ar2,9);
    sort(ar3,4);
    cout << " ==========================" << endl;

    cout << "After sorting: " << endl;
    print_array(ar1,9);
    print_array(ar2,9);
    print_array(ar3,4);

	return 0;
}
