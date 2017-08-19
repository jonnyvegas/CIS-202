//Name: Jonathan Villegas
//Description:  Write a program in which you declare a dequeto store values of type double,
//read in 10 doublenumbers and store them in the deque. Then call the generic
//sort function to sort the numbers in the dequeand display the results.
//Date: 5/6/14
//Email: jonathan.e.villegas@gmail.com
//File: dequesort.cpp

#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
    deque<double> the_deck;
    deque<double>::iterator iter;
    double the_num = 0;
    cout << "Please enter 10 numbers and push enter after each: ";

    for(int i = 0; i < 10; i++)
    {
        cin >> the_num;
        the_deck.push_back(the_num);
    }

    cout << "You entered: ";
    for(iter = the_deck.begin(); iter != the_deck.end(); iter++)
    {
        cout << *iter << " ";
    }

    sort(the_deck.begin(), the_deck.end());
    cout << endl;
    cout << "The numbers your entered sorted: ";
    for(iter = the_deck.begin(); iter != the_deck.end(); iter++)
    {
        cout << *iter << " ";
    }
    return 0;
}
