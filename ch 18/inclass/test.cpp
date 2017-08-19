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
	assertIf_GT(d.getYear(),0);
	assertIf_LT(0,d.getYear());
	return 0;
}

template <class T>
void assertIf_GT(T a,T b)
{
	assert(a > b);
}

template <class T>
void assertIf_LT(T a,T b)
{
	assert(a < b);
}

template <class T>
void assertIf_NE(T a, T b)
{
    assert(a != b);
}
