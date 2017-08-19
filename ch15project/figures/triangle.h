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
