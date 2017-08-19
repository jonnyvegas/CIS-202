#include <iostream>
using namespace std;

class Rational
{
public:
    Rational(); //default constructor / set num to 0 and denom to 1
    Rational(int num1, int num2);
    friend bool operator ==(Rational& first, Rational& second);
    friend Rational operator *(const Rational& first, const Rational& second);
    friend istream& operator >>(istream& ins, Rational& number);
    friend ostream& operator <<(ostream& outs, const Rational& number);
    void input();
    void output();
private:
    int numerator;
    int denominator;
};

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

Rational operator *(const Rational& first, const Rational& second)
{
    Rational temp;
    temp.numerator = first.numerator * second.numerator;
    temp.denominator = first.denominator * second.denominator;
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

int main()
{
    Rational first;
    Rational second;
    Rational third;

    cout << "Please enter the first fraction: ";
    cin >> first;
    cout << "Please enter the second fraction: ";
    cin >> second;

    cout << "First fraction: " << first << endl;
    cout << "Second fraction: " << second << endl;

    if (first == second)
        cout << first << " is equal to " << second << ".";
    else
        cout << first << " does not equal " << second << ".";
    third = first * second;
    cout << first << " times " << second << " equals " << third << endl;

    return 0;
}
