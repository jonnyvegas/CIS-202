#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Book
{
public:
    Book();
    string get_title();
    string get_author() const;
    string get_date();
    void set_title(string the_title);
    void set_author(string the_author);
    void set_date(string the_date);
    friend ostream& operator<<(ostream& os, Book& the_book);
    friend bool operator<(const Book& left_side, const Book& right_side);
private:
    string title;
    string author;
    string date;
};

Book::Book()
{
    title = "No title yet";
    author = "No author yet";
    date = "No date yet";
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
            the_book.set_author(the_author);
            the_book.set_title(the_title);
            the_book.set_date(the_date);
            book_vector.push_back(the_book);
        }
        else if(choice == 2)
        {
            sort(book_vector.begin(), book_vector.end());
            for(iter = book_vector.begin(); iter != book_vector.end(); iter++)
            {
                cout << *iter << endl;
            }
        }
        else if(choice == 3)
        {
            cout << "Quitting..." << endl;
        }
        else
        {
            cout << "You have entered an invalid choice!!! Please try again." << endl;
            choice = 4;
        }
    }while(choice != 3);
    return 0;
}
