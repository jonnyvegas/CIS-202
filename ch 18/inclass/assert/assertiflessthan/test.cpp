//Name: Jonathan Villegas
//Assignment: Download the Date class and header and the unit test.
//Write a template version of the unit test and implement an assertIf_NE function as well.
//Date: 4/22/14
//Email: jonathan.e.villegas@gmail.com
//File: test.cpp

#include <iostream>
#include <cassert>

#include "Date.h"

using namespace std;
template <class T>
void assertIf_GT(T,T);

template <class T>
void assertIf_LT(T,T);

template <class T>
void assertIf_NE(T,T);

int main(){
	Date d;

	d.setYear(-1);
	assertIf_NE(0, 1);
	assertIf_GT(d.getYear(),0);
	assertIf_LT(0,d.getYear());
	return 0;
}
//Assert if greater than.
template <class T>
void assertIf_GT(T a,T b)
{
	assert(a > b);
}
//Assert if less than.
template <class T>
void assertIf_LT(T a,T b)
{
	assert(a < b);
}
//Assert if not equal.
template <class T>
void assertIf_NE(T a, T b)
{
    assert(a != b);
}
