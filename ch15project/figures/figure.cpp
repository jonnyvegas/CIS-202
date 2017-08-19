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
