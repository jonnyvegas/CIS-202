//Name: Jonathan Villegas
//Assignment: Give the definition of a class named Doctor whose objects are records for a
//clinic’s doctors. This class will be a derived class of the class SalariedEmployee
//given in Display 15.4.
//Date: 3/11/14
//Email: jonathan.e.villegas@gmail.com

#ifndef DOCTOR_ANCESTOR_PROJECT_JV_H_INCLUDED
#define DOCTOR_ANCESTOR_PROJECT_JV_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;
namespace villegasdoctor
{
    class Employee
    {
    public:
        //Constructors
        Employee( );
        Employee(string the_name, string the_ssn);

        string get_name( ) const;//Returns the name
        string get_ssn( ) const; //Returns the social security #
        double get_net_pay( ) const;//Returns the net pay
        void set_name(string new_name);
        //Precondition: new_name is a string the user enters.
        //Postcondition: The name is set to the variable new_name.
        void set_ssn(string new_ssn);
        //Precondition: new_ssn is a string the user enters.
        //Postcondition: The ssn is set to the variable new_ssn.
        void set_net_pay(double new_net_pay);
        //Precondition: new_net_pay is a double the user enters.
        //Postcondition: The net_pay is set to the variable new_net_pay.
        void print_check( ) const;//prints check
    private:
        string name;
        string ssn;
        double net_pay;
    };

    class SalariedEmployee : public Employee
    {
    public:
        SalariedEmployee( );
        SalariedEmployee (string the_name, string the_ssn,
                                  double the_weekly_salary);
        double get_salary( ) const;//returns salary
        void set_salary(double new_salary);
        //Precondition: new_salary is a double the user enters.
        //Postcondition: The salary is set to the variable new_salary.
        void print_check( );//prints the check.
    protected:
        double salary;//weekly
    };

    class Doctor : public SalariedEmployee
    {
    public:
        //Constructors:
        Doctor();
        Doctor(string the_name, string the_ssn,
                      double the_weekly_salary, string the_specialty,
                      double the_fee);

        Doctor& operator =(const Doctor& right_side);//overloaded = operator
        Doctor(const Doctor& doctor_object);//Copy constructor
        string get_specialty() const;//returns specialty
        double get_fee() const;//returns fee
        void set_specialty(string new_specialty);
        //Precondition: new_specialty is a double the user enters.
        //Postcondition: The net_pay is set to the variable new_net_pay.
        void set_fee(double new_fee);
        //Precondition: new_net_pay is a double the user enters.
        //Postcondition: The net_pay is set to the variable new_net_pay.
        void print_data();//prints the Doctor's data to the screen

    private:
        string specialty;
        double fee;
    };
}

#endif // DOCTOR_ANCESTOR_PROJECT_JV_H_INCLUDED
