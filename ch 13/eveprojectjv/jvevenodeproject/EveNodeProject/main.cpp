#include <iostream>
#include "eve.h"
using namespace std;
using namespace villegaseve;

int main()
{
    int suitors;
    char ans;
    Node a_node;
    cout << "This program will eliminate every third suitor from a total" << endl;
    cout << "number of suitors until only one is left." << endl;
    cout << "That suitor will win Eve's heart!" << endl;
    do
    {
        cout << endl;
        cout << "Please enter the number of suitors you would like to test: ";
        cin >> suitors;


        a_node.getSuitor(suitors);
        cout << "Would you like to test another number of suitors? (Y/N): ";
        cin >> ans;
    }while (ans != 'n' && ans != 'N');

    return 0;
}
