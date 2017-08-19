//Name: Jonathan Villegas
//Assignment: Write a program that uses the class SalariedEmployeein Display 15.4. Your
//program is to define a class called Administrator, which is to be derived
//from the class SalariedEmployee.
//Date: 3/15/14
//Email: jonathan.e.villegas@gmail.com
//filename: admin_ancestor.cpp

#include <iostream>
#include <string>
#include "administrator.h"

using namespace std;
namespace villegasadministrator
{
    Employee::Employee( ) : name("No name yet"), ssn("No number yet"), net_pay(0)
    {
        //deliberately empty
    }

    Employee::Employee(string the_name, string the_number)
       : name(the_name), ssn(the_number), net_pay(0)
    {
        //deliberately empty
    }

    string Employee::get_name( ) const
    {
        return name;
    }

    string Employee::get_ssn( ) const
    {
        return ssn;
    }

    double Employee::get_net_pay( ) const
    {
        return net_pay;
    }

    void Employee::set_name(string new_name)
    {
        name = new_name;
    }
    void Employee::set_ssn(string new_ssn)
    {
        ssn = new_ssn;
    }

    void Employee::set_net_pay (double new_net_pay)
    {
        net_pay = new_net_pay;
    }

    void Employee::print_check( ) const
    {
        cout << "\nERROR: print_check FUNCTION CALLED FOR AN \n"
             << "UNDIFFERENTIATED EMPLOYEE. Aborting the program.\n"
             << "Check with the author of the program about this bug.\n";
    }

    SalariedEmployee::SalariedEmployee( ) : Employee( ), salary(0)
    {
        //deliberately empty
    }
    SalariedEmployee::SalariedEmployee(string the_name, string the_number,
                                  double the_weekly_salary)
                     : Employee(the_name, the_number), salary(the_weekly_salary)
    {
        //deliberately empty
    }

    double SalariedEmployee::get_salary( ) const
    {
        return salary;
    }

    void SalariedEmployee::set_salary(double new_salary)
    {
        salary = new_salary;
    }

    void SalariedEmployee::print_check( )
    {
        set_net_pay(salary);
        cout << "\n__________________________________________________\n";
        cout << "Pay to the order of " << get_name( ) << endl;
        cout << "The sum of " << get_net_pay( ) << " Dollars\n";
        cout << "_________________________________________________\n";
        cout << "Check Stub NOT NEGOTIABLE \n";
        cout << "Employee Number: " << get_ssn( ) << endl;
        cout << "Salaried Employee. Regular Pay: "
             << salary << endl;
        cout << "_________________________________________________\n";
    }

    void Administrator::set_supervisor(string the_supervisor)
    {
        supervisor = the_supervisor;
    }

    void Administrator::input_data()
    {
        cout << "Please enter the Administrator's title: ";
        getline(cin, title);
        cout << "Please enter the area of responsibility: ";
        getline(cin, area);
        cout << "Please enter the name of the Supervisor: ";
        getline(cin, supervisor);
    }

    void Administrator::print_data()
    {
        cout << "Name: " << get_name() << endl;
        cout << "SSN: " << get_ssn() << endl;
        cout << "Administrator title: " << title << endl;
        cout << "Area of responsibility: " << area << endl;
        cout << "Supervisor: " << supervisor << endl;
        cout.setf(ios::showpoint);
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << "Annual salary: $" << salary << endl;
    }

    void Administrator::print_check()
    {
        set_net_pay(salary);
        cout << "\n__________________________________________________\n";
        cout << "Pay to the order of " << get_name( ) << endl;
        cout << "The sum of " << get_net_pay( ) << " Dollars\n";
        cout << "_________________________________________________\n";
        cout << "Check Stub NOT NEGOTIABLE \n";
        cout << "Employee Number: " << get_ssn( ) << endl;
        cout << "Salaried Employee. Administrator. Regular Pay: "
             << salary << endl;
        cout << "_________________________________________________\n";
    }

    Administrator::Administrator( ) : SalariedEmployee( ), title("no title yet"),
                                    area("no area yet"), supervisor("no supervisor yet")
    {
        //intentionally empty
    }

    Administrator::Administrator(string the_name, string the_ssn,
                      double the_weekly_salary, string the_title,
                      string the_area, string the_supervisor)
                     : SalariedEmployee(the_name, the_ssn, the_weekly_salary),
                     title(the_title), area(the_area), supervisor(the_supervisor)
    {
        //intentionally empty
    }
}

