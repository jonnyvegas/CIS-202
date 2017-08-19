//Name: Jonathan Villegas
//Assignment: Give the definition of a class named Doctor whose objects are records for a
//clinic’s doctors. This class will be a derived class of the class SalariedEmployee
//given in Display 15.4.
//Date: 3/11/14
//Email: jonathan.e.villegas@gmail.com

#include <iostream>
#include <string>
#include "doctor_ancestor_project_jv.h"

using namespace std;
using namespace villegasdoctor;

int main()
{
    Doctor dr1("Dr. Julius Hibbert", "5684235884", 100000.00, "Family Practice", 25.00);
    Doctor dr2("Dr. Nick Riviera", "869451237", 10000.00, "Anything you need!", 2.00);
    cout << "Doctor 1: " << endl;
    dr1.print_data();
    cout << endl;
    cout << "Doctor 2: " << endl;
    dr2.print_data();
    cout << endl;
    Doctor dr3(dr1);
    cout << "Doctor 3 (copy of Doctor 1):" << endl;
    dr3.print_data();
    cout << endl;
    cout << "Doctor 1: " << endl;
    dr1.print_data();
    cout << endl;
    cout << "Doctor 2: " << endl;
    dr2.print_data();
    cout << endl;
    dr1 = dr2;
    cout << "Doctor 2 and Doctor 1 are equal." << endl;
    cout << "Doctor 2: " << endl;
    dr2.print_data();
    cout << endl;
    cout << "Doctor 1: " << endl;
    dr1.print_data();
    cout << "SSN Dr 1:" << dr1.get_ssn();
    return 0;
}
