//Name: Jonathan Villegas
//Assignment: Write a program that uses the unnamed namespace in two
//separate files with the same function name and make the username
//and password verification work. 8 letters for username 8 letters
//and a number for password.
//Date: 4/13/14
//Email: jonathan.e.villegas@gmail.com
//filename: main.cpp

#include <iostream>
#include <string>
#include "user.h"
#include "password.h"
using namespace std;
using namespace Authenticate;

int main()
{
    inputUserName();
    inputPassword();
    cout << endl;
    cout << "Your username is: " << getUserName() << endl;
    cout << "and your password is: " << getPassword() << endl;
    return 0;
}
