//
// File: ch9_highscore_jv.cpp
// Description: This program keeps a table of 5 high scores
// using parallel arrays and outputs the score to the screen
// as many times as the user desires. The score and name will
// be put in the correct place of the high score table.
// Created: 2/17/14
// Author: Jonathan Villegas
// mail: jonathan.e.villegas@gmail.com
//

#include <iostream>
#include <string>

int main()
{
    using namespace std;

    string names[5];
    string userName;
    const int MAX_SCORES = 5;
    int arrScore[MAX_SCORES];
    int score;
    char ans = 'Y';

    cout << "This program will have you input your name and a score" << endl;
    cout << "to compare to a score list. If your score is higher" << endl;
    cout << "than the lowest score, your score will be input on the list." << endl;
    cout << "HIGH SCORES:" << endl;
    for (int i = 0; i < MAX_SCORES; i++)
    {
        arrScore[i] = 1000;//make the first 5 entries for score 1000
        names[i] = "Jonny";//initialize the first 5 entries to Jonny
        cout << names[i] << " ";
        cout << arrScore[i] << endl;
    }
    cout << endl;
    do
    {
        cout << "Please enter your name and your score: ";
        cin >> userName >> score;

        if (score >= arrScore[0])
        {
            arrScore[0] = score;
            names[0] = userName;
        }
        else if (score >= arrScore[1])
        {
            arrScore[1] = score;
            names[1] = userName;
        }
        else if (score >= arrScore[2])
        {
            arrScore[2] = score;
            names[2] = userName;
        }
        else if (score >= arrScore[3])
        {
            arrScore[3] = score;
            names[3] = userName;
        }
        else if (score >= arrScore[4])
        {
            arrScore[4] = score;
            names[4] = userName;
        }
        else
        {
            cout << "Sorry, your score was not high enough to make it onto the list." << endl;
        }
        cout << endl;
        cout << "New high scores: ";
        cout << endl;
        for (int j = 0; j < MAX_SCORES; j++)
        {
            cout << names[j] << " ";
            cout << arrScore[j] << endl;
        }
        cout << "Would you like to input another entry? (Y/N): ";
        cin >> ans;
    }while((ans == 'y')||(ans == 'Y'));

    return 0;
}
