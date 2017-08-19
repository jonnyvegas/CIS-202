//Name: Jonathan Villegas
//Description:  Write a program that allows the user to enter any number of student names
//and their scores. The program should then display the student names and
//scores according to the ascending order of scores.
//Date: 5/6/14
//Email: jonathan.e.villegas@gmail.com
//File: studentScores.h

#ifndef STUDENTSCORES_H_INCLUDED
#define STUDENTSCORES_H_INCLUDED

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

namespace villegasstudents
{
    class Student
    {
    public:
        //Constructors:
        Student();
        Student(int the_score, string the_name);
        //Mutators:
        void set_score(int the_score);
        void set_name(string the_name);
        //Accessors:
        int get_score() const;
        string get_name() const;
        //Overloaded operators:
        friend ostream& operator<<(ostream& os, Student& the_student);
        friend bool operator<(const Student& left_side, const Student& right_side);
    private:
        int score;
        string name;
    };
}
#endif // STUDENTSCORES_H_INCLUDED
