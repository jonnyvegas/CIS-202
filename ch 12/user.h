#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

namespace
{
    bool isValid();
}

namespace Authenticate
{
    void inputUserName();
    string getUserName();
}
#endif // USER_H_INCLUDED
