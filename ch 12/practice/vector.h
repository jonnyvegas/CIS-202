#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

//Name: Jonathan Villegas
//Assignment: Create a class called VectorDouble that acts
//as though vectors were not defined in C++. Must have push_back,
//add_element, capacity, size, overloading of ==, =,
//and output and input operators.
//Date: 3/3/14
//Email: jonathan.e.villegas@gmail.com
#include <iostream>
using namespace std;

class VectorDouble
{
public:
    VectorDouble(); //Default constructor
    VectorDouble(int size);
    VectorDouble(const VectorDouble& vector_object);
    ~VectorDouble(); //Destructor

    void operator =(const VectorDouble& right_side);
    friend bool operator ==(const VectorDouble& vector1, const VectorDouble& vector2);

    void add_element(double num);
    void push_back(int myInt);
    int capacity();
    int size();
    void reserve(int num);
    void resize(int num);

    double value_at(int elementNumber);
    void change_value_at(double newAmount, int elementNumber);

    friend ostream& operator <<(ostream& outs, const VectorDouble& the_array);
private:
    double *value;
    int max_count;
    int count;
};


#endif // VECTOR_H_INCLUDED
