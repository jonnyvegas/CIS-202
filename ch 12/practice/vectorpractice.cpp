//Name: Jonathan Villegas
//Assignment: Create a class called VectorDouble that acts
//as though vectors were not defined in C++. Must have push_back,
//add_element, capacity, size, overloading of ==, =,
//and output and input operators.
//Date: 3/3/14
//Email: jonathan.e.villegas@gmail.com

#include <iostream>
#include "vector.h"

VectorDouble::VectorDouble() : max_count(50)
{
    value = new double[max_count];
    count = 0;
}

VectorDouble::VectorDouble(int size) : max_count(size)
{
    value = new double[max_count];
    count = 0;
}

VectorDouble::VectorDouble(const VectorDouble& vector_object)
{
    max_count = vector_object.max_count;
    value = new double[max_count];
    count = vector_object.count;
    for (int i = 0; i <= count; i++)
        value[i] = vector_object.value[i];
}

VectorDouble::~VectorDouble()
{
    delete [] value;
}

void VectorDouble::operator =(const VectorDouble& right_side)
{
    max_count = right_side.max_count;
    count = right_side.count;
    value = new double[max_count];
    for (int i = 0; i <= right_side.count; i++)
        value[i] = right_side.value[i];
}

bool operator ==(const VectorDouble& vector1, const VectorDouble& vector2)
{
    bool compare;

    if(vector1.count == vector2.count)
    {
        for (int i = 0; i <= vector1.count; i++)
        {
            if (vector1.value[i] == vector2.value[i])
                compare = true;
            else
                compare = false;
        }
    }
    else
    {
        compare = false;
    }
    return ((vector1.count == vector2.count) && (compare));
}

void VectorDouble::add_element(double num)
{
    if (count == max_count)
    {
        int new_count = max_count * 2;
        double *value2 = new double[new_count];
        for (int i = 0; i <= max_count; i++)
        {
            value2[i] = value[i];
        }
        value = new double[new_count];
        for (int j = 0; j <= max_count; j++)
        {
            value[j] = value2[j];
        }
        max_count = max_count * 2;
        value[count] = num;
        count = count + 1;
    }
    else
    {
        value[count] = num;
        count = count + 1;
    }
}

void VectorDouble::push_back(int myInt)
{
    value[count] = myInt;
    count = count + 1;
}

int VectorDouble::capacity()
{
    return max_count;
}

int VectorDouble::size()
{
    return count;
}

void VectorDouble::reserve(int num)
{
    max_count = num;
}

void VectorDouble::resize(int num)
{
    count = num;
}

double VectorDouble::value_at(int elementNumber)
{
    return value[elementNumber];
}

void VectorDouble::change_value_at(double newAmount, int elementNumber)
{
    value[elementNumber] = newAmount;
}

ostream& operator <<(ostream& outs, const VectorDouble& the_array)
{
    for (int i = 0; i < the_array.count; i++)  //Will output all elements of array to screen
        outs << the_array.value[i] << endl;
    return outs;
}
