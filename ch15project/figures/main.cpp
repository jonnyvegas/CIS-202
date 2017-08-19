#include <iostream>
#include "figure.h"
#include "rectangle.h"
#include "triangle.h"
//#include "figure.cpp"
//#include "rectangle.cpp"
//#include "triangle.cpp"

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
