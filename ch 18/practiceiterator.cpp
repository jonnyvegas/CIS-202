#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(5);
    v.push_back(20);
    v.push_back(8);
    v.push_back(17);
    v.push_back(3);

    vector<int>::iterator p = v.begin();
    cout << "First element is: " << *p << endl;
    cout << "Going forward two: " << *(p + 2) << endl;
    cout << "Back one: " << *(p + 1) << endl;
    p = v.begin();
    cout << "Beginning: " << *p << endl;
}
