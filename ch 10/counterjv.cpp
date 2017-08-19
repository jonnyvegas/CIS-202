//
// File: counterjv.cpp
// Description: Simulate a little red clicking counter that has
// 4 different spaces for ones, tens, dollars, and tens of dollars.
// Simulate a clicker that clicks up to 9 times in each place, and if
// a number goes higher than 9, the appropriate integer will be increased.
// This also provides a boolean that returns if the count goes higher than
// $99.99.
// Created: 2/24/14
// Author: Jonathan Villegas
// mail: jonathan.e.villegas@gmail.com
//
#include <iostream>
using namespace std;

class Counter
{
public:
    Counter(); //default constructor
    void greeting();

    void reset();    //Reset to 00.00
    void incr1();    //Increase the ones position
    void incr10();   //Increase the tens position
    void incr100();  //Increase the hundreds position
    void incr1000(); //Increase the thousands position

    void display();  //Displays in the format $00.00.
    bool overflow(); //Returns true if overflow error in counter

private:
    int units;
    int tens;
    int dollars;
    int tensDollars;
    bool overflowStatus;
};

Counter::Counter() //Default constructor / Max value 99.99
{
    overflowStatus = false;
    units = 0;
    tens = 0;
    dollars = 0;
    tensDollars = 0;
}

void Counter::greeting()
{
    cout << "This program will imitate a hand counter by" << endl;
    cout << "allowing you to input a number 1-9" << endl;
    cout << "in a position of your choice in the form $00.00" << endl;
    cout << "and will add the numbers in the correct position." << endl;
    cout << endl;
}

void Counter::reset()
{
    overflowStatus = false;
    units = 0;
    tens = 0;
    dollars = 0;
    tensDollars = 0;
}

void Counter::incr1()
{
    overflowStatus = false;
    if (units < 9)
        units = units + 1;
    else
    {
        units = 0;              //If the units are more than 10, a 0 goes
        if (tens < 9)           //in the units and the tens will be increased by 1.
            tens = tens + 1;    //All functions work similar using the appropriate place
        else                    //for the number.
        {
            tens = 0;
            if (dollars < 9)
                dollars = dollars + 1;
            else
            {
                dollars = 0;
                if (tensDollars < 9)
                    tensDollars = tensDollars + 1;
                else
                    overflowStatus = true;
            }
        }
    }
}

void Counter::incr10()
{
    overflowStatus = false;
    if(tens < 9)
        tens = tens + 1;
    else
    {
        tens = 0;
        if (dollars < 9)
            dollars = dollars + 1;
        else
        {
            dollars = 0;
            if (tensDollars < 9)
                tensDollars = tensDollars + 1;
            else
                overflowStatus = true;
        }
    }
}

void Counter::incr100()
{
    overflowStatus = false;
    if (dollars < 9)
        dollars = dollars + 1;
    else
    {
        dollars = 0;
        if (tensDollars < 9)
            tensDollars = tensDollars + 1;
        else
            overflowStatus = true;
    }
}

void Counter::incr1000()
{
    overflowStatus = false;
    if (tensDollars < 9)
        tensDollars = tensDollars + 1;
    else
        overflowStatus = true;
}

void Counter::display()
{
    cout << "$" << tensDollars << dollars << "." << tens << units;
}

bool Counter::overflow()
{
    return overflowStatus;
}

int main()
{
    Counter groceryCounter;
    int input;
    char choice, ans;
    groceryCounter.greeting();
    do
    {
        cout << endl;
        cout << "Please enter your choice:" << endl;
        cout << "A for cents " << endl;
        cout << "S for ten cents " << endl;
        cout << "D for dollars " << endl;
        cout << "F for ten dollars " << endl;
        cout << "Or, press R to reset the counter: ";
        cin >> choice;

        switch(choice)
        {
        case 'A':
        case 'a':
            {
                cout << "Please enter a number between 1 and 9: ";
                cin >> input;
                if (input > 0 && input < 10)
                {
                    for (int i = 0; i < input; i++)
                        groceryCounter.incr1();
                }
                else
                    cout << "Invalid entry! Try again..." << endl;   //Number was not between 1-9.
            }
            break;
        case 'S':
        case 's':
            {
                cout << "Please enter a number between 1 and 9: ";
                cin >> input;
                if (input > 0 && input < 10)
                {
                    for (int i = 0; i < input; i++)
                        groceryCounter.incr10();
                }
                else
                    cout << "Invalid entry! Try again..." << endl;
            }
            break;
        case 'D':
        case 'd':
            {
                cout << "Please enter a number between 1 and 9: ";
                cin >> input;
                if (input > 0 && input < 10)
                {
                    for (int i = 0; i < input; i++)
                        groceryCounter.incr100();
                }
                else
                    cout << "Invalid entry! Try again..." << endl;
            }
            break;
        case 'F':
        case 'f':
            {
                cout << "Please enter a number between 1 and 9: ";
                cin >> input;
                if (input > 0 && input < 10)
                {
                    for (int i = 0; i < input; i++)
                        groceryCounter.incr1000();
                }
                else
                    cout << "Invalid entry! Try again..." << endl;
            }
            break;
        case 'R':
        case 'r':
            {
                cout << "Resetting counter to $00.00" << endl;
                groceryCounter.reset();
            }
            break;
        default:
            {
                cout << "Invalid entry!!! Please try again." << endl;
            }
            break;
        }
        cout << endl;
        cout << "Counter value: ";
        groceryCounter.display();
        cout << endl;
        if(groceryCounter.overflow())
        {
            cout << "Overflow error! Resetting counter...";
            groceryCounter.reset();
            groceryCounter.display();
            cout << endl;
        }
        cout << endl;
        cout << "Would you like to continue? (Y/N): ";
        cin >> ans;
    } while (ans != 'n' && ans != 'N');

    cout << "Final counter value: ";
    groceryCounter.display();
    return 0;
}
