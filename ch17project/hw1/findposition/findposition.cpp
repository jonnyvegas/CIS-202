/*
Name: Jonathan Villegas
Filename: findposition.cpp
Description: Write a function template for a function that has parameters for a partially
filled array and for a value of the base type of the array. If the value is in
the partially filled array, then the function returns the index of the first
indexed variable that contains the value. If the value is not in the array,
the function returns -1.
Date: 4/13/14
e-mail address: jonathan.e.villegas@gmail.com
*/

#include <iostream>
#include "findposition.h"

template<class BaseType>
int find_item(BaseType a[], BaseType the_item, int the_size)
{
    for(int i = 0; i < the_size; i++)
    {
        if(a[i] == the_item) //item was found in the array
        {
            return i;  //return index found.
        }
    }
    return -1;  //index was not found, return -1.
}
