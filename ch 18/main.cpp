#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "studentInfoHeader.h"
using namespace std;
using namespace villegasstudentinfo;

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

int main()
{
    vector<StudentInfo>::iterator iter;
    string the_name;
    int the_grade, the_min = 1000, the_max = 0;
    double total = 0, num_of_students = 0;
    StudentInfo students_info;
    vector<StudentInfo> student_vector;
    cout << "Enter names and grades. Enter 'done' when finished." << endl;
    do
    {
        cout << "Please enter the student's first name (no spaces): ";
        cin >> the_name;
        cout << "Please enter their grade (in number form): ";
        cin >> the_grade;
        if(the_name != "done")
        {
            students_info.name = the_name;
            students_info.grade = the_grade;
            student_vector.push_back(students_info);
            if(students_info.grade > the_max)
            {
                the_max = students_info.grade;
            }
            if(students_info.grade < the_min)
            {
                the_min = students_info.grade;
            }
            total += students_info.grade;
        }
    }while(the_name != "done");
    for(iter = student_vector.begin(); iter != student_vector.end(); iter++)
    {
        num_of_students++;
    }
    cout << endl;
    cout << "The minimum grade: " << the_min << endl;
    cout << "The maximum grade: " << the_max << endl;
    cout << "The average grade: " << total / num_of_students << endl;
    cout << endl;

    sort(student_vector.begin(), student_vector.end());

    cout << "Class roll with scores: " << endl;
    for(iter = student_vector.begin(); iter != student_vector.end(); iter++)
    {
        cout << *iter << endl;
    }
    return 0;
}
