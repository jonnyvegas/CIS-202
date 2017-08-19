#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED
#include "figure.h"
namespace villegasfigures
{
    class Rectangle : public Figure
    {
    public:
        virtual void draw();//draw the rectangle
        virtual void erase();//erase the rectangle
        virtual void center();//erase the rectangle and draw in the center
    private:
        double length;
        double width;
        int middle;
    };
}


#endif // RECTANGLE_H_INCLUDED
