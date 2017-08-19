#include <iostream>
#include <string>
using namespace std;

class Employee
{
public:
    Employee( );
    Employee(string the_name, string the_ssn);
    string get_name( ) const;
    string get_ssn( ) const;
    double get_net_pay( ) const;
    void set_name(string new_name);
    void set_ssn(string new_ssn);
    void set_net_pay(double new_net_pay);
    void print_check( ) const;
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
    double get_salary( ) const;
    void set_salary(double new_salary);
    void print_check( );
protected:
    double salary;//weekly
};

class Doctor : public SalariedEmployee
{
public:
    Doctor();
    Doctor(string the_name, string the_ssn,
                  double the_weekly_salary, string the_specialty,
                  double the_fee);
    Doctor& operator =(const Doctor& right_side);
    Doctor(const Doctor& doctor_object);
    string get_specialty() const;
    double get_fee() const;
    void set_specialty(string new_specialty);
    void set_fee(double new_fee);
    void print_data();

private:
    string specialty;
    double fee;
};

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

Doctor::Doctor() : SalariedEmployee(), specialty("none_yet"), fee(0.0)
{

}

Doctor::Doctor(string the_name, string the_ssn,
                  double the_weekly_salary, string the_specialty,
                  double the_fee) : SalariedEmployee(the_name, the_ssn, the_weekly_salary),
                  specialty(the_specialty), fee(the_fee)
{}

Doctor& Doctor::operator =(const Doctor& right_side)
{
    SalariedEmployee::operator=(right_side);
    set_name(right_side.get_name());
    set_ssn(right_side.get_ssn());
    set_salary(right_side.get_salary());
    specialty = right_side.specialty;
    fee = right_side.fee;
}

Doctor::Doctor(const Doctor& doctor_object) : SalariedEmployee(doctor_object),
                    specialty(doctor_object.specialty), fee(doctor_object.fee)
{}

void Doctor::set_specialty(string new_specialty)
{
    specialty = new_specialty;
}

void Doctor::set_fee(double new_fee)
{
    fee = new_fee;
}

string Doctor::get_specialty() const
{
    return specialty;
}

double Doctor::get_fee() const
{
    return fee;
}

void Doctor::print_data()
{
    cout << "Name : " << get_name() << endl;
    cout << "SSN# " << get_ssn() << endl;
    cout << "Salary pay: " << get_salary() << endl;
    cout << "Specialty: " << get_specialty() << endl;
    cout << "Fee: " << get_fee() << endl;
}

int main()
{
    Doctor dr1("Dr. Buttz", "5684235884", 100000.00, "Proctology", 25.00);
    Doctor dr2("Dr. Cheeks", "512554510", 10000.00, "Foot Fungus", 15.00);
    dr1.print_data();
    dr2.print_data();
    Doctor dr3(dr1);
    dr3.print_data();
    dr1.print_data();
    dr2.print_data();
    dr1 = dr2;
    dr2.print_data();
    dr1.print_data();
    cout << "SSN Dr 1:" << dr1.get_ssn();
    return 0;
}
