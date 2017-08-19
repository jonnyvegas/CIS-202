/*
Name: Jonathan Villegas
Filename: findposition.h
Description: Write a function template for a function that has parameters for a partially
filled array and for a value of the base type of the array. If the value is in
the partially filled array, then the function returns the index of the first
indexed variable that contains the value. If the value is not in the array,
the function returns -1.
Date: 4/13/14
e-mail address: jonathan.e.villegas@gmail.com
*/

#ifndef FINDPOSITION_H_INCLUDED
#define FINDPOSITION_H_INCLUDED

#include <iostream>

template<class BaseType>
int find_item(BaseType a[], BaseType the_item, int the_size);
//Precondition: The user is ready to enter the number or letter to find.
//Postcondition: Returns the position of the item found if found in the array,
//else it returns -1 if it is not found.

#endif // FINDPOSITION_H_INCLUDED
