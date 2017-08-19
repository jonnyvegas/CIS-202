//Name: Jonathan Villegas
//Description:  In this project you are to create a database of books that are stored using a
//vector. Keep track of the author, title, and publication date of each book.
//Your program should have a main menu that allows the user to select
//from the following: Add a book’s author, title, and date, Print an
//alphabetical list of the books sorted by author, and Quit.
//Date: 5/10/14
//Email: jonathan.e.villegas@gmail.com
//File: books.h

#ifndef BOOKS_H_INCLUDED
#define BOOKS_H_INCLUDED

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
namespace villegasbooks
{
    class Book
    {
    public:
        //Constructor
        Book();
        //Accessors
        string get_title();
        string get_author() const;
        string get_date();
        //Mutators
        void set_title(string the_title);
        void set_author(string the_author);
        void set_date(string the_date);
        //Overloaded operators
        friend ostream& operator<<(ostream& os, Book& the_book);
        friend bool operator<(const Book& left_side, const Book& right_side);
    private:
        string title;
        string author;
        string date;
    };
}
#endif // BOOKS_H_INCLUDED
