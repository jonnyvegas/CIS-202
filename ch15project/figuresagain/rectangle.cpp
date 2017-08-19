//Name: Jonathan Villegas
//Assignment: The class Figure is the base class. You should add only Rectangle and
//Triangle classes derived from Figure. Each class has stubs for member
//functions erase and draw. Each of these member functions outputs a
//message telling what function has been called and what the class of the
//calling object is. Since these are just stubs, they do nothing more than
//output this message.
//Date: 3/11/14
//Email: jonathan.e.villegas@gmail.com
//Filename: rectangle.cpp

#include <iostream>
#include "figure.h"
#include "rectangle.h"
using namespace std;
namespace villegasfigures
{
    void Rectangle::draw()
    {
        cout << "Drawing a rectangle..." << endl;
    }

    void Rectangle::erase()
    {
        cout << "Erasing the rectangle..." << endl;
    }

    void Rectangle::center()
    {
        erase();
        draw();
    }
}
