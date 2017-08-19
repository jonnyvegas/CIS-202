#include <iostream>
using namespace std;

template <class BaseType>
class Stack
{
public:
    Stack(int number_of_elements);
    Stack(const Stack& the_stack);
    ~Stack();
    bool empty();
    void push(BaseType new_item);
    BaseType pop();
private:
    BaseType *stack;
    int top;
    int max_size;
    int current_size;
};

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
    return (top == -1);
}

template <class BaseType>
void Stack<BaseType>::push(BaseType new_item)
{
    if(current_size == max_size)
    {
        cout << "Making larger..." << endl;
        int temp_size = max_size * 2;
        cout << "New size: " << temp_size << endl;
        BaseType *temp;
        temp = new BaseType[temp_size];
        for(int i = 0; i < max_size; i++)
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
        cout << "Adding element " << new_item << endl;
        stack[++top] = new_item;//First index will be 0.
        current_size++;
        cout << "Current size: " << current_size << endl;
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
    while(!a.empty())
    {
        num = a.pop();
        cout << num << " ";
    }
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
    while(!b.empty())
    {
        ch = b.pop();
        cout << ch << " ";
    }
    return 0;
}
