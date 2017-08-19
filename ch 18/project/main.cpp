//Name: Jonathan Villegas
//Description:  Write a program that allows the user to enter any number of student names
//and their scores. The program should then display the student names and
//scores according to the ascending order of scores.
//Date: 5/6/14
//Email: jonathan.e.villegas@gmail.com
//File: main.cpp

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include "studentScores.h"

using namespace std;
using namespace villegasstudents;

int main()
{
    vector<Student> students;
    vector<Student>::iterator iter;
    Student the_student;
    string input_name;
    int the_score;

    cout << "Please enter the students name and score (When finished, enter done)" << endl;

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

    cout << "Sorted by score: " << endl;
    for (iter = students.begin(); iter != students.end(); iter++)
    {
        cout << *iter << endl;
    }
    return 0;
}
