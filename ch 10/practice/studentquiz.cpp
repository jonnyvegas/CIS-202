//
// File: studentquizjv.cpp
// Description: This program takes two quiz scores,
// both out of 10, a midterm, and a final, both
// out of 100. The program outputs a grade based on
// the averages with the final being 50%, the midterm
// 25%, and each quiz worth 12.5% of the grade. The program
// will then output the grade based on the average of the scores.
// Created: 2/22/14
// Author: Jonathan Villegas
// mail: jonathan.e.villegas@gmail.com
//

#include <iostream>

struct Student
{
    double quiz1;
    double quiz2;
    double midterm;
    double finalTest;
    double finalTotal;
    char grade;
};

void getGrades(Student& theStudent);  //Input the grades
void printGrades(Student& theStudent);//Print out the grades
void totalGrade(Student& theStudent); //Get the total grade
void letterGrade(Student theStudent); //Print the letter grade.

int main()
{
    Student student1;

    getGrades(student1);
    printGrades(student1);
    totalGrade(student1);
    letterGrade(student1);

    return 0;
}

void getGrades(Student& theStudent)
{
    using namespace std;

    cout << "Please enter the grade for quiz 1 (out of 10): ";
    cin >> theStudent.quiz1;
    cout << "Please enter the grade for quiz 2 (out of 10): ";
    cin >> theStudent.quiz2;
    cout << "Please enter your midterm grade (out of 100): ";
    cin >> theStudent.midterm;
    cout << "Please enter your final test grade (out of 100): ";
    cin >> theStudent.finalTest;
}

void printGrades(Student& theStudent)
{
    using namespace std;

    theStudent.quiz1 = theStudent.quiz1 * 10.0;  //To make out of 100
    cout << "Your quiz 1 score is: " << theStudent.quiz1 << endl;
    theStudent.quiz2 = theStudent.quiz2 * 10.0;
    cout << "Your quiz 2 score is: " << theStudent.quiz2 << endl;
    cout << "Your midterm score is: " << theStudent.midterm << endl;
    cout << "Your final score is: " << theStudent.finalTest << endl;
    cout << endl;
}

void totalGrade(Student& theStudent)
{
    using namespace std;

    theStudent.quiz1 = theStudent.quiz1 * .125;  //Each quiz is worth 12.5% because they total 25%.
    theStudent.quiz2 = theStudent.quiz2 * .125;
    theStudent.midterm = theStudent.midterm * .25;
    theStudent.finalTest = theStudent.finalTest * .50;
    theStudent.finalTotal = (theStudent.quiz1 + theStudent.quiz2
                  + theStudent.midterm + theStudent.finalTest);
    cout << "Your final point average is: " << theStudent.finalTotal << endl;
    cout << endl;
}

void letterGrade(Student theStudent)
{
    using namespace std;

    if (theStudent.finalTotal >= 90)
        cout << "Your grade is an A! Great job." << endl;
    else if (theStudent.finalTotal < 90 && theStudent.finalTotal >= 80)
        cout << "Your grade is a B! Good job." << endl;
    else if (theStudent.finalTotal < 80 && theStudent.finalTotal >= 70)
        cout << "Your grade is a C! You passed..." << endl;
    else if (theStudent.finalTotal < 70 && theStudent.finalTotal >= 60)
        cout << "Your grade is a D. Study more!" << endl;
    else //Grade was below a 59.
        cout << "Your grade is an F. You must retake the course. "
             << "See you in the summer!!!" << endl;
}
