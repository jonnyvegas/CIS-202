#ifndef PASSWORD_H_INCLUDED
#define PASSWORD_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

namespace
{
    bool isValid();
}

namespace Authenticate
{
    void inputPassword();
    string getPassword();
}

#endif // PASSWORD_H_INCLUDED
