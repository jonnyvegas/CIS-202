/*Create a three-level hierarchy of classes with default constructors,
along with destructors, both of which announce themselves to cout.
Verify that for an object of the most derived type, all three
constructors and destructors are automatically called.
Explain the order in which the calls are made. (15 points)
*/
#include <iostream>
using namespace std;

class FirstClass
{
public:
    FirstClass();
    ~FirstClass();
};

class SecondClass : public FirstClass
{
public:
    SecondClass();
    ~SecondClass();
};

class ThirdClass : public SecondClass
{
public:
    ThirdClass();
    ~ThirdClass();
};

FirstClass::FirstClass()
{
    cout << "Calling FirstClass default constructor... " << endl;
}

FirstClass::~FirstClass()
{
    cout << "Calling FirstClass destructor... " << endl;
}

SecondClass::SecondClass()
{
    cout << "Calling SecondClass default constructor... " << endl;
}

SecondClass::~SecondClass()
{
    cout << "Calling SecondClass destructor... " << endl;
}

ThirdClass::ThirdClass()
{
    cout << "Calling ThirdClass default constructor... " << endl;
}

ThirdClass::~ThirdClass()
{
    cout << "Calling ThirdClass destructor... " << endl;
}

int main()
{
    ThirdClass third_class_object;
    return 0;
}
