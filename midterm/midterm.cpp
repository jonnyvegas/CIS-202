//Given Car.cpp:
//: C14:Car.cpp // Public composition
#include <iostream>
using namespace std;

class Vehicle
{
public:
    Vehicle(char the_type, double the_top_speed);
    double get_top_speed();
    void transport() const {};
    void cease_transport() const {};
    char get_type();
    void some_other_function() {};//function to be named later.
protected:
    double top_speed;
    char type;
};

class Engine
{
 public:
     void start() const {};
     void rev() const {};
     void stop() const {}
 };

class Wheel
{
 public:
    void inflate(int psi) const {}
};

class Window
{
 public:
     void rollup() const {};
     void rolldown() const {}
};

class Door
{
public:
     Window window;
     void open() const {};
     void close() const {}
};

class Car : public Vehicle
{
 public:
    Car(char the_type, double the_top_speed);
    Engine engine;
    Wheel wheel[4];
    Door left, right; // 2-door
};

Vehicle::Vehicle(char the_type, double the_top_speed)
{
    type = the_type;
    top_speed = the_top_speed;
    cout << "Calling vehicle's constructor... " << endl;
    cout << "Type: " << type << " Top Speed: " << top_speed << endl;
}

double Vehicle::get_top_speed()
{
    return top_speed;
}

Car::Car(char the_type, double the_top_speed) : Vehicle(the_type,the_top_speed)
{
    cout << "Calling car's constructor..." << endl;
}

int main()
{
    char type = 'a';
    Car car(type, 175.8);
    car.left.window.rollup();
    car.wheel[0].inflate(72);
}

/*
Modify Car.cpp so that it also inherits from a class called Vehicle,
placing appropriate member functions in Vehicle (that is, make up some
member functions). Add a nondefault constructor to Vehicle, which you
must call inside Car’s constructor. (15 points)
*/
