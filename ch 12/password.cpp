#include <iostream>
#include <string>
#include "password.h"
using namespace std;

namespace
{
    string password;
    bool isValid()
    {
        return (password.size() == 9);
    }
}

namespace Authenticate
{
    void inputPassword()
    {
        do
        {
            cout << "Enter your password (at least 8 characters " <<
            "and at least one non-letter)" << endl;
            cin >> password ;
        } while (!isValid());
    }

    string getPassword()
    {
        return password;
    }
}
