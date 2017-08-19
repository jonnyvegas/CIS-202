//Name: Jonathan Villegas
//Assignment: Write a program that uses the unnamed namespace in two
//separate files with the same function name and make the username
//and password verification work. 8 letters for username 8 letters
//and a number for password.
//Date: 4/13/14
//Email: jonathan.e.villegas@gmail.com
//filename: password.h

#ifndef PASSWORD_H_INCLUDED
#define PASSWORD_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

namespace
{
    bool isValid();//returns true if password is 1 number and 8 letters. Else returns false.
}

namespace Authenticate
{
    void inputPassword();//input the password.
    string getPassword();//returns password.
}

#endif // PASSWORD_H_INCLUDED
