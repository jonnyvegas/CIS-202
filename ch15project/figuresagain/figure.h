//Name: Jonathan Villegas
//Assignment: The class Figure is the base class. You should add only Rectangle and
//Triangle classes derived from Figure. Each class has stubs for member
//functions erase and draw. Each of these member functions outputs a
//message telling what function has been called and what the class of the
//calling object is. Since these are just stubs, they do nothing more than
//output this message.
//Date: 3/11/14
//Email: jonathan.e.villegas@gmail.com
//Filename: figure.h

#ifndef FIGURE_H_INCLUDED
#define FIGURE_H_INCLUDED
namespace villegasfigures
{
    class Figure
    {
    public:
        virtual void draw();//draw a figure
        virtual void erase();//erase the figure
        virtual void center();//erase and draw the figure in the center
    private:
        int middle;
    };
}


#endif // FIGURE_H_INCLUDED
