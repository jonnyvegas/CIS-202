/*
Name: Jonathan Villegas
Filename: stacktemplate.cpp
Description: Write a template version of a stack class. Use a type parameter for the type
of data that is stored in the stack. Use dynamic arrays to allow the stack to
grow to hold any number of items.
e-mail address: jonathan.e.villegas@gmail.com
Date: 4/13/14
*/

#ifndef STACKTEMPLATE_H_INCLUDED
#define STACKTEMPLATE_H_INCLUDED

template <class BaseType>
class Stack
{
public:
    Stack(int number_of_elements); //Constructor.
    Stack(const Stack& the_stack); //Copy Constructor.
    ~Stack(); //Destructor.
    bool empty(); //Returns true if stack is empty
    void push(BaseType new_item); //Pushes item onto stack
    BaseType pop(); //Pops item off stack and returns an element of BaseType.
private:
    BaseType *stack;
    int top;
    int max_size;
    int current_size;
};

#endif // STACKTEMPLATE_H_INCLUDED
