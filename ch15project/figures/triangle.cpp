#include <iostream>
#include "figure.h"
#include "triangle.h"

using namespace std;

namespace villegasfigures
{
    void Triangle::draw()
    {
        cout << "Drawing a triangle..." << endl;
    }

    void Triangle::erase()
    {
        cout << "Erasing the triangle..." << endl;
    }

    void Triangle::center()
    {
        erase();
        draw();
    }
}
