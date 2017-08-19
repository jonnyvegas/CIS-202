//
// File: employeerecordjv.cpp
// Description: Write a definition for a structure type for
//records consisting of a person’s wage rate, accrued vacation
//(in whole days), and status (hourly or salaried). Represent
//the status as one of the two character values ‘H’ and ‘S’.
//Call the type EmployeeRecord.
// Created: 2/17/14
// Author: Jonathan Villegas
// mail: jonathan.e.villegas@gmail.com
//

struct EmployeeRecord
{
    double wage_rate;
    int hours;
    char status;  //Represented as either H or S.
};
