#include <iostream>
#include <string>
#include <list>
using namespace std;

int main()
{
    list<string> list_of_names;
    list_of_names.push_back("Tony");
    list_of_names.push_front("Jimmy");
    list_of_names.push_back("Paulie");
    list_of_names.push_front("Henry");
    list_of_names.push_back("Silvio");
    list_of_names.push_front("Paulie Walnuts");

    list<string>::iterator iter;
    for(iter = list_of_names.begin(); iter != list_of_names.end(); iter++)
    {
        cout << "Name: " << *iter << endl;
    }
    for(iter = list_of_names.begin(); iter != list_of_names.end(); iter++)
    {
        *iter = "Tommy Salami";
    }
    for(iter = list_of_names.begin(); iter != list_of_names.end(); iter++)
    {
        cout << "Name: " << *iter << endl;
    }
    cout << "The number of names contained is: " << list_of_names.size() << endl;
}
