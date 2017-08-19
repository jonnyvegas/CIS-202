//Name: Jonathan Villegas
//Assignment: Define a class for rational numbers. A rational number is a number that
//can be represented as the quotient of two integers. Represent rational numbers as two values
//of type int, one for the numerator and one for the denominator.
//Also include functions to add, subtract, multiply, and divide the numbers.
//Date: 4/3/14
//Email: jonathan.e.villegas@gmail.com
//filename: rational.h

#ifndef RATIONAL_H_INCLUDED
#define RATIONAL_H_INCLUDED

#include <iostream>
using namespace std;

namespace villegasrational
{
    using namespace std;
    class Rational
    {
    public:
        Rational(); //default constructor / set num to 0 and denom to 1
        Rational(int num1, int num2); //Allows input with a / as the fraction part
        friend bool operator ==(Rational& first, Rational& second);
        friend bool operator <(Rational& first, Rational& second);
        friend bool operator >(Rational& first, Rational& second);
        friend bool operator <=(Rational& first, Rational& second);
        friend bool operator >=(Rational& first, Rational& second);
        friend Rational operator +(const Rational& first, const Rational& second);
        friend Rational operator -(const Rational& first, const Rational& second);
        friend Rational operator *(const Rational& first, const Rational& second);
        friend Rational operator /(const Rational& first, const Rational& second);
        friend istream& operator >>(istream& ins, Rational& number);
        friend ostream& operator <<(ostream& outs, const Rational& number);
        //Accessors
        int get_numerator();
        int get_denominator();
        //Mutators
        void set_numerator(int the_numerator);
        void set_denominator(int the_denominator);
    private:
        int numerator;
        int denominator;
    };

    void reduce(Rational& number);
}


#endif // RATIONAL_H_INCLUDED
