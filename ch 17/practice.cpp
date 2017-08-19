#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    srand(time(0));//This is so that it will generate random numbers. Otherwise it'd just do the same #s every time.
    int r;
    for (int i = 0; i < 5; i++)
    {
        r = rand() %75 + 1;
        cout << r << " ";
    }
    r = rand() % 15 + 1;
    cout << "MEGA " << r << endl;

}
