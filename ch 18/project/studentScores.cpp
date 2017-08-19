//Name: Jonathan Villegas
//Description:  Write a program that allows the user to enter any number of student names
//and their scores. The program should then display the student names and
//scores according to the ascending order of scores.
//Date: 5/6/14
//Email: jonathan.e.villegas@gmail.com
//File: studentScores.cpp

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include "studentScores.h"

using namespace std;

namespace villegasstudents
{
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
}
