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
