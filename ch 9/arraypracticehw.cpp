#include <iostream>

typedef int* intArrayPtr;

void greeting();
void sizeOfArrays(int& size1, int& size2, int& larger, int& size3);
void fillArray(int a[], int size, int larger);
void addArrays(int a1[], int size1, int a2[], int size2, int a3[], int size3);
char loop();

int main()
{
    int size1 = 0, size2 = 0, size3 = 0, larger = 0;
    intArrayPtr a1, a2, a3;
    char ans;

    greeting();

    do
    {
    sizeOfArrays(size1, size2, larger, size3);

    a1 = new int[larger];
    a2 = new int[larger];

    fillArray(a1, size1, larger);
    fillArray(a2, size2, larger);

    a3 = new int[larger];

    addArrays(a1, size1, a2, size2, a3, size3);
    ans = loop();
    } while (ans != 'n' && ans != 'N');
    return 0;
}

void greeting()
{
    using namespace std;

    cout << "Hello! This program will take two numbers of a length" << endl;
    cout << "of your choosing and will output the result." << endl;
    cout << endl;
}

void sizeOfArrays(int& size1, int& size2, int& larger, int& size3)
{
    using namespace std;

    cout << "Please enter the size of array 1: ";
    cin >> size1;
    cout << "Please enter the size of array 2: ";
    cin >> size2;

    if (size1 >= size2)
    {
        size3 = size1;
        larger = size1;
    }
    else
    {
        size3 = size2;
        larger = size2;
    }

}

void fillArray(int a[], int size, int larger)
{
    using namespace std;

    char digitArr[size];
    char next;

    cout << "Please enter a number of length " << size << ": ";

    cin.get(next);
    if (next == '\n')       //The new character would be carried over from the last iteration
        cin.get(next);      //this has system pause to get next chars after the loop.

    int i = 0;
    while (isdigit(next) && i < size) //Loop to fill digitArr with chars
    {
        digitArr[i] = next;
        i++;    //increments to let know how many elements in array. This is passed to sizeOfArr.
        cin.get(next);
    }
    int  j = 0;

    while (j < size)
    {
        i--;
        a[j] = digitArr[i] - '0'; //Conversion from char to int leaves ASCII 48.
        j++;
    }
    if (size < larger)
    {
        for(int i = size; i < larger; i++)
            a[i] = 0;
    }
}

void addArrays(int a1[], int size1, int a2[], int size2, int a3[], int size3)
{
    using namespace std;

    int carry = 0;

    for (int i = 0; i < size3; i++)
    {
        a3[i] = a1[i] + a2[i] + carry;
        if (a3[i] > 9)
        {
            carry = 1;
            a3[i] = a3[i] - 10;
        }
        else
            carry = 0;
    }
    cout << endl;
    cout << "The answer is: ";
    if (carry == 1)
    {
        a3[size3] = carry;
        for (int j = size3; j >= 0; j--) //Must be output backward for the loop
            cout << a3[j];
    }
    else
    {
        for (int j = size3 - 1; j >= 0; j--) //Must be output backward for the loop
            cout << a3[j];
    }
    cout << endl;
}

char loop()
{
    using namespace std;

    char ans;

    cout << "Would you like to add again? (Y/N): ";
    cin >> ans;
    return ans;
}
