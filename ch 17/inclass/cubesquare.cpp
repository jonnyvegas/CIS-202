#include <iostream>
using namespace std;

template <class T>
T cube (T& var)
{
    return var*var*var;
}

template <class T>
T square (T& var)
{
    return var*var;
}

int main()
{
    int var1;
    double var2;
    cout << "Please enter a number with no decimal: ";
    cin >> var1;
    cout << "Please enter a number with a decimal: ";
    cin >> var2;
    cout << var1 << " cubed is: " << cube(var1) << endl;
    cout << var2 << " cubed is: " << cube(var2) << endl;
    cout << var1 << " squared is: " << square(var1) << endl;
    cout << var2 << " squared is: " << square(var2) << endl;

    return 0;
}
