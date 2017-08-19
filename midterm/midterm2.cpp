/*Create two classes, A and B, with default constructors that
announce themselves. Inherit a new class called C from A, and
create a member object of B in C, but do not create a constructor
for C. Create an object of class C and observe the results. (15 points)*/
#include <iostream>
using namespace std;

class A
{
public:
    A();
};

class B
{
public:
    B();
};

class C : public A
{
public:
    B object_of_B;
};

A::A()
{
    cout << "Calling A's default constructor..." << endl;
}

B::B()
{
    cout << "Calling B's default constructor... " << endl;
}

int main()
{
    C object_of_c;

    return 0;
}
