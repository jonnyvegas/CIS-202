//Name: Jonathan Villegas
//Description:  Write a program that prompts for and
//fetches data and builds a vector of student records,
//then sorts the vector by name, calculates the maximum and minimum
//grades, and the class average, then prints this summarizing data along with
//a class roll with grades
//Date: 5/6/14
//Email: jonathan.e.villegas@gmail.com
//File: studentscores.cpp

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Student
{
public:
    Student();
    Student(int the_score, string the_name);
    void set_score(int the_score);
    void set_name(string the_name);
    int get_score() const;
    string get_name() const;
    friend ostream& operator<<(ostream& os, Student& the_student);
    friend bool operator<(const Student& left_side, const Student& right_side);
private:
    int score;
    string name;
};

Student::Student()
{
    score = 0;
    name = "none";
}

Student::Student(int the_score, string the_name)
{
    score = the_score;
    name = the_name;
}

void Student::set_score(int the_score)
{
    score = the_score;
}

void Student::set_name(string the_name)
{
    name = the_name;
}

int Student::get_score() const
{
    return score;
}

string Student::get_name() const
{
    return name;
}

bool operator <(const Student& left_side, const Student& right_side)
{
    return (left_side.get_score() < right_side.get_score());
}

ostream& operator<<(ostream& os, Student& the_student)
{
    os << "Name: " << the_student.get_name() << " Score: " << the_student.get_score();
    return os;
}

int main()
{
    vector<Student> students;
    vector<Student>::iterator iter;
    Student the_student;
    string input_name;
    int the_score;
    cout << "Please enter the students name and score (When finished, enter done): " << endl;
    do
    {
        cout << "Please enter name: ";
        cin >> input_name;
        cout << "Please enter the score: ";
        cin >> the_score;
        if(input_name != "done")
        {
            the_student.set_name(input_name);
            the_student.set_score(the_score);
            students.push_back(the_student);
        }
    }while(input_name != "done");
    for (iter = students.begin(); iter != students.end(); iter++)
    {
        cout << *iter << endl;
    }
    sort(students.begin(), students.end());
    cout << "Sorted: " << endl;
    for (iter = students.begin(); iter != students.end(); iter++)
    {
        cout << *iter << endl;
    }
    return 0;
}
