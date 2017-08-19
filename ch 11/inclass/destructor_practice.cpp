#include <iostream>
using namespace std;

class SomeClass
{
public:
    SomeClass();
    ~SomeClass();
    void someFunction();
};

SomeClass::SomeClass()
{
    cout << "In constructor" << endl;
}

SomeClass::~SomeClass()
{
    cout << "In destructor" << endl;
}

void SomeClass::someFunction()
{
    SomeClass class3;
}

int main()
{
    SomeClass item1, item2;
    item1.someFunction();
    return 0;
}
