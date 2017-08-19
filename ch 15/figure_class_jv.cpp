#include <iostream>
using namespace std;

class Figure
{
public:
    virtual void draw();
    virtual void erase();
    virtual void center();
private:
    int middle;
};

class Rectangle : public Figure
{
public:
    virtual void draw();
    virtual void erase();
    virtual void center();
private:
    double length;
    double width;
    int middle;
};

class Triangle : public Figure
{
public:
    virtual void draw();
    virtual void erase();
    virtual void center();
private:
    double height;
    double base;
    char type;
    int middle;
};

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
