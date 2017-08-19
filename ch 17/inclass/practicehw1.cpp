#include <iostream>
using namespace std;

template<class BaseType>
int find_item(BaseType a[], BaseType the_item, int the_size)
{
    for(int i = 0; i < the_size; i++)
    {
        if(a[i] == the_item)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6};
    int the_index;
    int the_num;
    cout << "Please enter the number to find: ";
    cin >> the_num;
    the_index = find_item(a, the_num, 6);
    if(the_index != -1)
        cout << the_num << " Found in position: " << the_index << endl;
    else //the_index == -1
        cout << the_num << " Not found in the array." << endl;

    char b[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    char the_letter;
    cout << "Please enter the letter to find: ";
    cin >> the_letter;
    the_index = find_item(b, the_letter, 10);
    if(the_index != -1)
        cout << the_letter << " Found in position: " << the_index << endl;
    else //the_index == -1
        cout << the_letter << " Not found in the array." << endl;

    return 0;
}
