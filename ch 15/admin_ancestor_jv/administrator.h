//Name: Jonathan Villegas
//Assignment: Write a program that uses the class SalariedEmployeein Display 15.4. Your
//program is to define a class called Administrator, which is to be derived
//from the class SalariedEmployee.
//Date: 3/15/14
//Email: jonathan.e.villegas@gmail.com
//filename: administrator.h

#ifndef ADMINISTRATOR_H_INCLUDED
#define ADMINISTRATOR_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

namespace villegasadministrator
{
    class Employee
    {
    public:
        //Constructors
        Employee( );
        Employee(string the_name, string the_ssn);
        string get_name( ) const;//returns name
        string get_ssn( ) const;//returns ssn
        double get_net_pay( ) const;//returns net pay
        void set_name(string new_name);
        //Precondition: user enters a string called new_name.
        //Postcondition: name is set to new_name.
        void set_ssn(string new_ssn);
        //Precondition: user enters a string called new_ssn.
        //Postcondition: ssn is set to new_ssn.
        void set_net_pay(double new_net_pay);
        //Precondition: user enters a double called new_net_pay.
        //Postcondition: net_pay is set to new_net_pay.
        void print_check( ) const;
    private:
        string name;
        string ssn;
        double net_pay;
    };

    class SalariedEmployee : public Employee
    {
    public:
        //Constructors
        SalariedEmployee( );
        SalariedEmployee (string the_name, string the_ssn,
                                  double the_weekly_salary);

        double get_salary( ) const;//returns salary.
        void set_salary(double new_salary);
        //Precondition: user enters a double called new_salary.
        //Postcondition: salary is set to new_salary.
        void print_check( );//prints check.
    protected:
        double salary;//weekly
    };

    class Administrator : public SalariedEmployee
    {
    public:
        //Constructors
        Administrator();
        Administrator(string the_name, string the_ssn,
                      double the_weekly_salary, string the_title,
                      string the_area, string the_supervisor);

        void set_supervisor(string the_supervisor);
        //Precondition: user enters a string called the_supervisor.
        //Postcondition: supervisor is set to the_supervisor.
        void input_data();//Let user input data.
        void print_data();//Output the data.
        void print_check();//print the check.
    private:
        string title;
        string area;
        string supervisor;
    };
}


#endif // ADMINISTRATOR_H_INCLUDED
