#include <iostream>
#include "practice.h"
using namespace std;

int main()
{
    SomeClass class1(4);
    class1.change_number(1);
    class1.print_number();
    cin.get();
    return 0;
}
