//Name: Jonathan Villegas
//Assignment: Write a program that uses the class SalariedEmployeein Display 15.4. Your
//program is to define a class called Administrator, which is to be derived
//from the class SalariedEmployee.
//Date: 3/15/14
//Email: jonathan.e.villegas@gmail.com
//filename: main.cpp

#include <iostream>
#include <string>
#include "administrator.h"

using namespace std;
using namespace villegasadministrator;

int main()
{
    Administrator admin("C. Montgomery Burns", "132456798", 1000000.00, "The Boss",
                        "Springfield Nuclear Power Plant", "Smithers (Not Burns' real supervisor)");
    admin.print_data();
    admin.print_check();
    return 0;
}
