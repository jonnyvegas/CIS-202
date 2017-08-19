//Name: Jonathan Villegas
//Assignment: The class Figure is the base class. You should add only Rectangle and
//Triangle classes derived from Figure. Each class has stubs for member
//functions erase and draw. Each of these member functions outputs a
//message telling what function has been called and what the class of the
//calling object is. Since these are just stubs, they do nothing more than
//output this message.
//Date: 3/11/14
//Email: jonathan.e.villegas@gmail.com
//Filename: triangle.h

#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED
#include "figure.h"
namespace villegasfigures
{
    class Triangle : public Figure
    {
    public:
        virtual void draw();//draw the triangle
        virtual void erase();//erase the triangle
        virtual void center();//erase the triangle and draw in the center.
    private:
        double height;
        double base;
        char type;
        int middle;
    };
}


#endif // TRIANGLE_H_INCLUDED
