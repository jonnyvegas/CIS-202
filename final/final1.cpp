//Name: Jonathan Villegas
//Assignment: Declare a stack template container
//to hold values of type double using the list container.
//Write the necessary include and using statements.
//Mention any appropriate cautions about syntax.
//Date: 5/29/14
//Email: jonathan.e.villegas@gmail.com
//Filename: final1.cpp

#include <iostream>
#include <list>
using namespace std;

template <class T>
class Stack
{
public:
    //Constructor
    Stack();
    //Is the stack empty?
    bool isEmpty();
    //Push an item on the stack
    void push(T item);
    //Pop the item off of the stack
    T pop();
    int get_size();
private:
    list<T> the_list;
    int size;
};

template <class T>
Stack<T>::Stack()
{
    size = 0;
}

template <class T>
bool Stack<T>::isEmpty()
{
    return the_list.empty();
}

template <class T>
void Stack<T>::push(T item)
{
    the_list.push_front(item);
    size = size + 1;
}

template <class T>
T Stack<T>::pop()
{
    if(isEmpty())
    {
        cout << "Error. Popping on an empty stack." << endl;
        T the_num = -1;
        return the_num;
    }
    else
    {
        T the_num;
        the_num = the_list.front();
        the_list.pop_front();
        size--;
        return the_num;
    }

}

template <class T>
int Stack<T>::get_size()
{
    return size;
}

int main()
{
    Stack<double> the_stack;

    the_stack.push(2.5);
    the_stack.push(23.5);
    the_stack.push(42.0);
    the_stack.push(86.2);
    the_stack.push(1.4);
    the_stack.push(8.9);
    the_stack.push(1002.3);
    the_stack.push(5684.1);
    the_stack.push(32);
    the_stack.push(24.0);
    the_stack.push(56.3);
    double the_num;
    int size = the_stack.get_size();
    for(int i = 0; i < size; i++)
    {
        the_num = the_stack.pop();
        cout << the_num << endl;
    }


    return 0;
}
