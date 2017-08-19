//Name: Jonathan Villegas
//Description:  In this project you are to create a database of books that are stored using a
//vector. Keep track of the author, title, and publication date of each book.
//Your program should have a main menu that allows the user to select
//from the following: Add a book’s author, title, and date, Print an
//alphabetical list of the books sorted by author, and Quit.
//Date: 5/10/14
//Email: jonathan.e.villegas@gmail.com
//File: books.cpp

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "books.h"
using namespace std;

namespace villegasbooks
{
    Book::Book()
    {
        title = "No title yet.";
        author = "No author yet.";
        date = "No date yet.";
    }

    string Book::get_title()
    {
        return title;
    }

    string Book::get_author() const
    {
        return author;
    }

    string Book::get_date()
    {
        return date;
    }

    void Book::set_title(string the_title)
    {
        title = the_title;
    }

    void Book::set_author(string the_author)
    {
        author = the_author;
    }

    void Book::set_date(string the_date)
    {
        date = the_date;
    }

    bool operator <(const Book& left_side, const Book& right_side)
    {
        return (left_side.get_author() < right_side.get_author());
    }

    ostream& operator<<(ostream& os, Book& the_book)
    {
        os << the_book.get_author() << ".   " << the_book.get_title()
           << ".    " << the_book.get_date() << ".";
        return os;
    }
}
