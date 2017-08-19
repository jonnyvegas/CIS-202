//Name: Jonathan Villegas
//Assignment: The class Figure is the base class. You should add only Rectangle and
//Triangle classes derived from Figure. Each class has stubs for member
//functions erase and draw. Each of these member functions outputs a
//message telling what function has been called and what the class of the
//calling object is. Since these are just stubs, they do nothing more than
//output this message.
//Date: 3/11/14
//Email: jonathan.e.villegas@gmail.com
//Filename: figure.cpp

#include <iostream>
#include "figure.h"
using namespace std;
namespace villegasfigures
{
     void Figure::draw()
    {
        cout << "Drawing a figure..." << endl;
    }

    void Figure::erase()
    {
        cout << "Erasing the figure..." << endl;
    }

    void Figure::center()
    {
        erase();
        draw();
    }
}
