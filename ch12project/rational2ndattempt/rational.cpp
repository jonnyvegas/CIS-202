//Name: Jonathan Villegas
//Assignment: Define a class for rational numbers. A rational number is a number that
//can be represented as the quotient of two integers. Represent rational numbers as two values
//of type int, one for the numerator and one for the denominator.
//Also include functions to add, subtract, multiply, and divide the numbers.
//Date: 4/3/14
//Email: jonathan.e.villegas@gmail.com
//filename: rational.cpp

#include <iostream>
#include "rational.h"
using namespace std;

namespace villegasrational
{
    using namespace std;
    Rational::Rational() : numerator(0), denominator(1)
    {
        //intentionally empty
    }

    Rational::Rational(int num1, int num2)
    {
        numerator = num1;
        denominator = num2;
    }

    bool operator == (Rational& first, Rational& second)
    {
        return (first.numerator * second.denominator) ==
            (second.numerator * first.denominator);
    }

    bool operator <(Rational& first, Rational& second)
    {
        int temp1, temp2;
        temp1 = first.numerator * second.denominator;
        temp2 = second.numerator * first.denominator;
        return (temp1 < temp2);
    }

    bool operator >(Rational& first, Rational& second)
    {
        int temp1, temp2;
        temp1 = first.numerator * second.denominator;
        temp2 = second.numerator * first.denominator;
        return (temp1 > temp2);
    }

    bool operator <=(Rational& first, Rational& second)
    {
        int temp1, temp2;
        temp1 = first.numerator * second.denominator;
        temp2 = second.numerator * first.denominator;
        return (temp1 <= temp2);
    }

    bool operator >=(Rational& first, Rational& second)
    {
        int temp1, temp2;
        temp1 = first.numerator * second.denominator;
        temp2 = second.numerator * first.denominator;
        return (temp1 >= temp2);
    }

    Rational operator +(const Rational& first, const Rational& second)
    {
        int temp_num1, temp_denom1, temp_num2;
        temp_num1 = first.numerator * second.denominator;
        temp_denom1 = first.denominator * second.denominator;
        temp_num2 = second.numerator * first.denominator;

        Rational temp;
        temp.numerator = temp_num1 + temp_num2;
        temp.denominator = temp_denom1;
        return temp;
    }

    Rational operator -(const Rational& first, const Rational& second)
    {
        int temp_num1, temp_denom1, temp_num2;
        temp_num1 = first.numerator * second.denominator;
        temp_denom1 = first.denominator * second.denominator;
        temp_num2 = second.numerator * first.denominator;

        Rational temp;
        temp.numerator = temp_num1 - temp_num2;
        temp.denominator = temp_denom1;
        return temp;
    }

    Rational operator *(const Rational& first, const Rational& second)
    {
        Rational temp;
        temp.numerator = first.numerator * second.numerator;
        temp.denominator = first.denominator * second.denominator;
        return temp;
    }

    Rational operator /(const Rational& first, const Rational& second)
    {
        Rational temp;
        temp.numerator = first.numerator * second.denominator;
        temp.denominator = first.denominator * second.numerator;
        return temp;
    }

    istream& operator >>(istream& ins, Rational& number)
    {
        char one_char;
        ins >> number.numerator >> one_char >> number.denominator;
        return ins;
    }

    ostream& operator <<(ostream& outs, const Rational& number)
    {
        outs << number.numerator << "/" << number.denominator;
        return outs;
    }

    int Rational::get_numerator()
    {
        return numerator;
    }

    int Rational::get_denominator()
    {
        return denominator;
    }

    void Rational::set_numerator(int the_numerator)
    {
        numerator = the_numerator;
    }

    void Rational::set_denominator(int the_denominator)
    {
        denominator = the_denominator;
    }

    void reduce(Rational& number)
    {
        for (int i = number.get_numerator() * number.get_denominator(); i > 1; i--)
        {
            if ((number.get_numerator() % i == 0) && (number.get_denominator() % i == 0))
            {
                number.set_numerator(number.get_numerator() / i);
                number.set_denominator(number.get_denominator() / i);
            }
        }
        if(number.get_numerator() < 0 && number.get_denominator() < 0)//Both are negative. Rational is positive.
        {
            number.set_denominator(number.get_denominator() * -1);//Denominator positive
            number.set_numerator(number.get_numerator() * -1);//Numerator positive
        }
        else if (number.get_denominator() < 0 && number.get_numerator() >= 0)//denominator is negative and numerator is positive.
        {
            number.set_numerator(number.get_numerator() * -1);//numerator negative
            number.set_denominator(number.get_denominator() * -1);//denominator positive
        }
        //else the numerator is negative, which is fine.
    }
}
