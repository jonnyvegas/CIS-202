#include <iostream>
#include "practice.h"

using namespace std;


SomeClass::SomeClass(int num)
{
    some_number = num;
}

void SomeClass::print_number()
{
    cout << "The number is: " << some_number;
}

void SomeClass::change_number(int num)
{
    some_number = num;
}
