#ifndef RATIONAL_H_INCLUDED
#define RATIONAL_H_INCLUDED

#include <iostream>
using namespace std;

namespace villegasrational
{
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
        int get_numerator();
        int get_denominator();
        void set_numerator(int the_numerator);
        void set_denominator(int the_denominator);
    private:
        int numerator;
        int denominator;
    };

    void reduce(Rational& number);
}

#endif // RATIONAL_H_INCLUDED
