#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include "studentInfoHeader.h"
namespace villegasstudentinfo
{
    //Operator to output the studentInfo.
    ostream& operator<<(ostream& os, StudentInfo& the_student)
    {
        os << "Name: " << the_student.name << " Grade: " << the_student.grade;
        return os;
    }
    //Overloaded operator to get students in ABC order.
    bool operator <(const StudentInfo& left_side, const StudentInfo& right_side)
    {
        return (left_side.name < right_side.name);
    }
}
