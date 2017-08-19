//
// File: ch9_highscore_jv.cpp
// Description: This program keeps a table of 5 high scores
// using parallel arrays and outputs the score to the screen
// as many times as the user desires. The score and name will
// be put in the correct place of the high score table.
// Created: 2/17/14
// Author: Jonathan Villegas
// e-mail: jonathan.e.villegas@gmail.com
//
#include <string>
#include <cstring>
#include <iostream>

typedef int* intPtr;
typedef std::string* strPtr;

void newLine();
//Prints a new line to the screen.

void displayEntries(std::string* namePtr, int* scorePtr, int sizeOfArr);
//Displays all the entries of the name and score arrays.

void message();
//Displays a greeting to the screen.

void inputInfo(std::string& inputName, int& inputScore);
//After the name and score are input, they are stored.

void compareScores(std::string* namePtr, int* scorePtr,
                   std::string inputName, int inputScore);
//Determines if the function is on the table. If so, indexOfLargest
//is called to figure out where in the array the score belongs.

int indexOfLargest (int* scorePtr, int inputScore);
//Returns the index of the largest number for compareScores.

void lowToHigh(int* scorePtr, int indexOfEntry, std::string* namePtr);
//Arranges the array in the correct order.

char loop();
//Loop to continue reading in scores.

void message2();
//Last printout of the scoreboard.

int main()
{
    using namespace std;

    int sizeOfArr = 5;
    string name[5] = { "Jonny", "Jonny", "Jonny", "Jonny", "Jonny" };
    int score[5] = { 1000, 1000, 1000, 1000, 1000 };

    string inputName;
    int inputScore;
    char ans;
    strPtr namePtr;
    intPtr scorePtr;

    scorePtr = score;
    namePtr = name;

    do
    {
    displayEntries(namePtr, scorePtr, sizeOfArr);
    message();
    inputInfo(inputName, inputScore);
    compareScores(namePtr, scorePtr, inputName, inputScore);
    displayEntries(namePtr, scorePtr, sizeOfArr);
    ans = loop();
    }while(ans == 'y' || ans == 'Y');

    message2();
    displayEntries(namePtr, scorePtr, sizeOfArr);

    return 0;
}

void newLine()
{
    using namespace std;

    cout << endl;
}

void displayEntries(std::string* namePtr, int* scorePtr, int sizeOfArr)
{
    using namespace std;

    newLine();
    cout << " Name     Score" << endl;
    cout << "================" << endl;
    for (int i = 0; i < sizeOfArr; i++)
    {
        cout << " " << namePtr[i] << "    " << scorePtr[i] << endl;
    }
}

void message()
{
    using namespace std;

    newLine();
    cout << "Please enter your name (no spaces) and your score: ";
}

void inputInfo(std::string& inputName, int& inputScore)
{
    using namespace std;

    cin >> inputName;
    cin >> inputScore;
}

void compareScores(std::string* namePtr, int* scorePtr,
                    std::string inputName, int inputScore)
{
    using namespace std;

    int indexOfNextLargest;

    if (inputScore >= scorePtr[4]) //If the score is bigger
    {                              //than the smallest entry, it belongs.

        indexOfNextLargest = indexOfLargest(scorePtr, inputScore);
        lowToHigh(scorePtr, indexOfNextLargest, namePtr);

        scorePtr[indexOfNextLargest] = inputScore;  //Sets the correct entry of the score array
        namePtr[indexOfNextLargest] = inputName;    //and the name array after being arranged.

        newLine();
        cout << "Your score was added to the list." << endl;
        newLine();
    }

    else                          //Entry does not belong.
    {
        newLine();
        cout << "Your score was not worthy of the list. Better luck next time!!" << endl;
        newLine();
    }
}

int indexOfLargest(int* scorePtr, int inputScore)
{
    int indexOfMax = 4; //Starting at the bottom of the score array.

    for (int index = 4; index >= 0; index--)
    {
        if (inputScore >= scorePtr[index]) //If the score is large enough, the index where it belongs
        {                                  //will be returned.
            indexOfMax = index;
        }
    }

    return indexOfMax;
}

void lowToHigh(int* scorePtr, int indexOfEntry, std::string* namePtr)
{
    using namespace std;

    for (int i = 4; i > indexOfEntry; i--)  //Arrange the array in correct order
    {                                       //with the largest limit given by
        scorePtr[i] = scorePtr[i - 1];      //index returned by the IndexOfLargest.
        namePtr[i] = namePtr[i - 1];
    }

}

char loop()
{
    using namespace std;

    char ans;

    newLine();
    cout << "Would you like to add an entry? (Y or N): ";
    cin >> ans;

    return ans;
}

void message2()
{
    using namespace std;

    newLine();
    cout << "Final score table:" << endl;
}
