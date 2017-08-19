/*
Name: Jonathan Villegas
Filename: stacktemplate.cpp
Description: Write a template version of a stack class. Use a type parameter for the type
of data that is stored in the stack. Use dynamic arrays to allow the stack to
grow to hold any number of items.
e-mail address: jonathan.e.villegas@gmail.com
Date: 4/13/14
*/

#include <iostream>
#include "stacktemplate.h"
using namespace std;

template <class BaseType>
Stack<BaseType>::Stack(int number_of_elements)
{
    max_size = number_of_elements;
    top = -1;//In a dynamic array, -1 means the end of the array.
    stack = new BaseType[number_of_elements];//Points to a new dynamic array.
    current_size = 0;
}

template <class BaseType>
Stack<BaseType>::Stack(const Stack& the_stack)
{
    max_size = the_stack.max_size;
    top = the_stack.top;
    stack = new BaseType[max_size];
    current_size = the_stack.current_size;
    for(int i = 0; i < max_size; i++)
    {
        stack[i] = the_stack[i];
    }
}

template <class BaseType>
Stack<BaseType>::~Stack()
{
    delete [] stack;
}

template <class BaseType>
bool Stack<BaseType>::empty()
{
    return (top == -1);  //top == -1 if there are no elements in the array.
}

template <class BaseType>
void Stack<BaseType>::push(BaseType new_item)
{
    if(current_size == max_size)  //Array needs to grow bigger.
    {
        int temp_size = max_size * 2;  //Array size doubled.
        BaseType *temp;
        temp = new BaseType[temp_size];
        for(int i = 0; i < max_size; i++)  //Copies elements into new array.
        {
            temp[i] = stack[i];
        }
        max_size = temp_size;
        stack = temp;
        stack[++top] = new_item;
        current_size++;
    }
    else
    {
        stack[++top] = new_item;//First index will be 0 since top starts at -1. Must be incremented first.
        current_size++;
    }
}

template <class BaseType>
BaseType Stack<BaseType>::pop()
{
    if(!empty())
    {
        BaseType temp;
        temp = stack[top--];
        return temp;
    }
    else
    {
        cout << "Error. Stack is empty.";
    }
}
