//Name: Jonathan Villegas
//Assignment: The class Figure is the base class. You should add only Rectangle and
//Triangle classes derived from Figure. Each class has stubs for member
//functions erase and draw. Each of these member functions outputs a
//message telling what function has been called and what the class of the
//calling object is. Since these are just stubs, they do nothing more than
//output this message.
//Date: 3/11/14
//Email: jonathan.e.villegas@gmail.com
//Filename: main.cpp

#include <iostream>
#include "figure.h"
#include "rectangle.h"
#include "triangle.h"


using namespace std;
using namespace villegasfigures;

int main()
{
    Triangle tri;
    tri.draw();
    cout << "Triangle calling center..." << endl;
    tri.center();

    Rectangle rect;
    rect.draw();
    cout << "Rectangle calling center..." << endl;
    rect.center();
    return 0;
}
