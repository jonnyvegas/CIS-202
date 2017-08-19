//Name: Jonathan Villegas
//Description:  Write a program that prompts for and
//fetches data and builds a vector of student records,
//then sorts the vector by name, calculates the maximum and minimum
//grades, and the class average, then prints this summarizing data along with
//a class roll with grades
//Date: 5/6/14
//Email: jonathan.e.villegas@gmail.com
//File: studentInfoVector.cpp

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct StudentInfo
{
    string name;
    int grade;
};
//Overloaded operator to properly display to screen.
ostream& operator<<(ostream& os, StudentInfo& the_student)
{
    os << "Name: " << the_student.name << " Grade: " << the_student.grade;
    return os;
}
//Overloaded operator to get ABC order properly.
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
        getline(cin, the_name);
        cout << "Please enter their grade (in number form): ";
        cin >> the_grade;
        cin.ignore(1);
        if(the_name != "done")
        {
            students_info.name = the_name;
            students_info.grade = the_grade;
            //Adding to the student vector
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
    //Get the total number of students.
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
