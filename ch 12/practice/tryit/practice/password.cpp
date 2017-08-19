//Name: Jonathan Villegas
//Assignment: Write a program that uses the unnamed namespace in two
//separate files with the same function name and make the username
//and password verification work. 8 letters for username 8 letters
//and a number for password.
//Date: 4/13/14
//Email: jonathan.e.villegas@gmail.com
//filename: password.cpp


#include <iostream>
#include <string>
#include "password.h"
using namespace std;

namespace
{
    string password;
    bool isValid()
    {
      bool hasDigit = false;
      int length = password.size();//get length of password
      for (int count = 0; count < length; count++)
      {
        if(isdigit(password[count]))//Step through array of characters checking for digit.
        {
            hasDigit = true;
        }
      }
      if(hasDigit && password.size() == 9)
        return true;
      else //Does not meet password requirements.
        return false;
    }
}

namespace Authenticate
{
    void inputPassword()
    {
        do
        {
            cout << "Enter your password (at least 8 characters " << "and at least one non-letter)" << endl;
            cin >> password ;
        } while (!isValid());
    }

    string getPassword()
    {
        return password;
    }
}
