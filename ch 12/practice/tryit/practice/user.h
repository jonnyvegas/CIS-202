//Name: Jonathan Villegas
//Assignment: Write a program that uses the unnamed namespace in two
//separate files with the same function name and make the username
//and password verification work. 8 letters for username 8 letters
//and a number for password.
//Date: 4/13/14
//Email: jonathan.e.villegas@gmail.com
//filename: user.h


#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

namespace
{
    bool isValid();//returns true if username is 8 letters. Else returns false.
}

namespace Authenticate
{
    void inputUserName();//input username.
    string getUserName();//returns username.
}
#endif // USER_H_INCLUDED
