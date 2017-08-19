//
// File: rationalclassjv.cpp
// Description: This program has a class that can use
// overloaded operators to output, input, and
// test if two fractions are equal.
// Created: 2/25/14
// Author: Jonathan Villegas
// mail: jonathan.e.villegas@gmail.com
//

#include <iostream>
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
    int get_numerator();
    int get_denominator();
    void set_numerator(int the_numerator);
    void set_denominator(int the_denominator);
private:
    int numerator;
    int denominator;
};

void reduce(Rational& number);

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
    int temp_num1, temp_denom1, temp_num2, temp_denom2;
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
    int temp_num1, temp_denom1, temp_num2, temp_denom2;
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
    if(number.get_numerator() < 0 && number.get_denominator() < 0)
    {
        number.set_denominator(number.get_denominator() * -1);
        number.set_numerator(number.get_numerator() * -1);
    }
    else if (number.get_denominator() < 0 && number.get_numerator() >= 0)
    {
        number.set_numerator(number.get_numerator() * -1);
        number.set_denominator(number.get_denominator() * -1);
    }
}

int main()
{
    Rational first;
    Rational second;
    Rational third;

    cout << "Please enter the first fraction: ";
    cin >> first;
    reduce(first);
    cout << "Please enter the second fraction: ";
    cin >> second;
    reduce(second);

    cout << "First fraction: " << first << endl;
    cout << "Second fraction: " << second << endl;

    if (first == second)
        cout << first << " is equal to " << second << "." << endl;
    else
        cout << first << " does not equal " << second << "." << endl;
    if(first < second)
        cout << first << " less than " << second << "." << endl;
    else
        cout << first << " is not less than " << second << "." << endl;
    if(first <= second)
        cout << first << " less than or equal to " << second << "." << endl;
    else
        cout << first << " is not less than or equal to " << second << "." << endl;
    if(first > second)
        cout << first << " greater than " << second << "." << endl;
    else
        cout << first << " is not greater than " << second << "." << endl;
    if(first >= second)
        cout << first << " greater than or equal to " << second << "." << endl;
    else
        cout << first << " is not greater than or equal to " << second << "." << endl;
    third = first * second;
    reduce(third);
    cout << first << " times " << second << " equals " << third << endl;
    Rational fourth;
    fourth = first + second;
    reduce(fourth);
    cout << first << " plus " << second << " equals " << fourth << endl;
    Rational fifth;
    fifth = first - second;
    reduce(fifth);
    cout << first << " minus " << second << " equals " << fifth << endl;
    Rational sixth;
    sixth = first / second;
    reduce(sixth);
    cout << first << " divided by " << second << " equals " << sixth << endl;
    return 0;
}
