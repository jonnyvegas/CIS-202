//Name: Jonathan Villegas
//Assignment: Write a program that uses the unnamed namespace in two
//separate files with the same function name and make the username
//and password verification work. 8 letters for username 8 letters
//and a number for password.
//Date: 4/13/14
//Email: jonathan.e.villegas@gmail.com
//filename: user.cpp

#include <iostream>
#include <string>
#include "user.h"
using namespace std;

namespace
{
    string username;
    bool isValid()
    {
        return (username.size() == 8);
    }
}

namespace Authenticate
{
    void inputUserName()
    {
        do
        {
            cout << "Enter your username (8 letters only)" << endl;
            cin >> username;
        } while (!isValid());
    }
    string getUserName()
    {
        return username;
    }
}

