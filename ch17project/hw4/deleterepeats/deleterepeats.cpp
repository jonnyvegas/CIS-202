/*
Name: Jonathan Villegas
Filename: deleterepeats.cpp
Description: Write a function template for a function called delete_repeats
that deletes any duplicate elements in an array and gives the appropriate size
for the partially filled array. The array is adjusted accordingly after delete_repeats
has run.
e-mail address: jonathan.e.villegas@gmail.com
Date: 4/13/14
*/

#include <iostream>
#include "deleterepeats.h"
template <class BaseType>
void delete_repeats(BaseType a[], int &size)
{
    for(int i = 0; i < size; i++) //Starting at the first
    {
        for(int j = i + 1; j < size; j++) //Starting at the second
        {
            if (a[i] == a[j]) //If the two elements are equal is a repeat.
            {
                for(int k = j; k < size; k++) //K equals the current element
                {
                    a[k] = a[k+1]; //Current element equal to the next element in the array.
                }
                size--;
            }
        }
    }
}
