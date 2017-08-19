/*
Name: Jonathan Villegas
Filename: deleterepeats.h
Description: Write a function template for a function called delete_repeats
that deletes any duplicate elements in an array and gives the appropriate size
for the partially filled array. The array is adjusted accordingly after delete_repeats
has run.
e-mail address: jonathan.e.villegas@gmail.com
Date: 4/13/14
*/

#ifndef DELETEREPEATS_H_INCLUDED
#define DELETEREPEATS_H_INCLUDED

template <class BaseType>
void delete_repeats(BaseType a[], int &size);
//Precondition: Array has been filled with values and size given.
//Postcondition: Repeated values in array are deleted and size is
//appropriate for size of array.

#endif // DELETEREPEATS_H_INCLUDED
