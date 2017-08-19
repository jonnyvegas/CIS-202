/*
Name: Jonathan Villegas
Filename: main.cpp
Description: Write a template version of a stack class. Use a type parameter for the type
of data that is stored in the stack. Use dynamic arrays to allow the stack to
grow to hold any number of items.
e-mail address: jonathan.e.villegas@gmail.com
Date: 4/13/14
*/

#include <iostream>
#include "stacktemplate.h"
#include "stacktemplate.cpp"

using namespace std;

int main()
{
    int the_size, num = 0;
    cout << "Enter size: ";
    cin >> the_size;
    Stack<int> a(the_size);
    cout << "Enter a series of numbers, ending with -1." << endl;
    while(num != -1)
    {
        cout << "Enter a number: ";
        cin >> num;
        if(num != -1)
            a.push(num);
    }
    cout << "Backwards, that is: ";
    while(!a.empty())
    {
        num = a.pop();
        cout << num << " ";
    }
    cout << endl;

    char ch;
    cout << "Enter size: ";
    cin >> the_size;
    Stack<char> b(the_size);
    cout << "Enter a series of letters, ending with a number." << endl;
    while(!isdigit(ch))
    {
        cout << "Enter a letter: ";
        cin >> ch;
        if(!isdigit(ch))
            b.push(ch);
    }
    cout << "Backwards, that is: ";
    while(!b.empty())
    {
        ch = b.pop();
        cout << ch << " ";
    }
    return 0;
}
