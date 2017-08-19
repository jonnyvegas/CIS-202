//Name: Jonathan Villegas
//Description:  In this project you are to create a database of books that are stored using a
//vector. Keep track of the author, title, and publication date of each book.
//Your program should have a main menu that allows the user to select
//from the following: Add a book’s author, title, and date, Print an
//alphabetical list of the books sorted by author, and Quit.
//Date: 5/10/14
//Email: jonathan.e.villegas@gmail.com
//File: main.cpp
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "books.h"
using namespace std;
using namespace villegasbooks;

int main()
{
    int choice = 0;
    string the_author, the_title, the_date;
    Book the_book;
    vector<Book> book_vector;
    vector<Book>::iterator iter;
    cout << "Please enter a choice from the menu: " << endl;
    do
    {
        cout << "1. Add new book" << endl;
        cout << "2. Print listing sorted by author" << endl;
        cout << "3. Quit" << endl;
        cout << "Please enter your choice: ";
        cin >> choice;
        cin.ignore(1);
        if(choice == 1)
        {
            cout << "Adding a new book..." << endl;

            cout << "Please enter the title: ";
            getline(cin, the_title);

            cout << "Please enter the author: ";
            getline(cin, the_author);

            cout << "Please enter the year published: ";
            getline(cin, the_date);
            //set the book's information
            the_book.set_author(the_author);
            the_book.set_title(the_title);
            the_book.set_date(the_date);
            //add book to the vector
            book_vector.push_back(the_book);
        }
        else if(choice == 2)
        {
            sort(book_vector.begin(), book_vector.end());
            //Output all books in book_vector
            for(iter = book_vector.begin(); iter != book_vector.end(); iter++)
            {
                cout << *iter << endl;
            }
        }
        else if(choice == 3)
        {
            cout << "Quitting..." << endl;
        }
        else//choice was not 1, 2, or 3.
        {
            cout << "You have entered an invalid choice!!! Please try again." << endl;
            //change choice to 4 to avoid ending loop.
            choice = 4;
        }
    }while(choice != 3);
    return 0;
}
