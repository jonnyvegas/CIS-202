//Name: Jonathan Villegas
//Assignment: Modify the definition of 11.8
//to have overloaded operators of <, >, <=, and >=.
//Also implement a function that returns a member of type Money
//in the amount of 10% of the calling object
//Date: 3/3/14
//Email: jonathan.e.villegas@gmail.com


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
using namespace std;

//Class for amounts of money in U.S. currency.
class Money
{
public:
    friend Money operator +(const Money& amount1, const Money& amount2);
    friend Money operator -(const Money& amount1, const Money& amount2);
    friend Money operator -(const Money& amount);
    friend bool operator ==(const Money& amount1, const Money& amount2);
    friend bool operator <(const Money& amount1, const Money& amount2);
    friend bool operator <=(const Money& amount1, const Money& amount2);
    friend bool operator >(const Money& amount1, const Money& amount2);
    friend bool operator >=(const Money& amount1, const Money& amount2);

    Money(long dollars, int cents);
    Money(long dollars);
    Money( );

    double get_value( ) const;

    Money percent(int percent_figure) const;
    //Returns a percentage of the money amount in the
    //calling object. For example, if percent_figure is 10,
    //then the value returned is 10% of the amount of
    //money represented by the calling object.

    friend istream& operator >>(istream& ins, Money& amount);
    //Overloads the >> operator so it can be used to input values of type Money.
    //Notation for inputting negative amounts is as in -$100.00.
    //Precondition: If ins is a file input stream, then ins has already been
    //connected to a file.

    friend ostream& operator <<(ostream& outs, const Money& amount);
    //Overloads the << operator so it can be used to output values of type Money.
    //Precedes each output value of type Money with a dollar sign.
    //Precondition: If outs is a file output stream,
    //then outs has already been connected to a file.
private:
    long all_cents;
};

int digit_to_int(char c);
//Used in the definition of the overloaded input operator >>.
//Precondition: c is one of the digits '0' through '9'.
//Returns the integer for the digit; for example, digit_to_int('3') returns 3.

Money operator +(const Money& amount1, const Money& amount2)
{
    Money temp;
    temp.all_cents = amount1.all_cents + amount2.all_cents;
    return temp;
}

Money operator -(const Money& amount1, const Money& amount2)
{
    Money temp;
    temp.all_cents = amount1.all_cents - amount2.all_cents;
    return temp;
}

Money operator -(const Money& amount)
{
    Money temp;
    temp.all_cents = -amount.all_cents;
    return temp;
}

bool operator ==(const Money& amount1, const Money& amount2)
{
    return (amount1.all_cents == amount2.all_cents);
}

bool operator <(const Money& amount1, const Money& amount2)
{
    return (amount1.all_cents < amount2.all_cents);
}

bool operator <=(const Money& amount1, const Money& amount2)
{
    return ((amount1.all_cents < amount2.all_cents)
            || (amount1.all_cents == amount2.all_cents));
}

bool operator >(const Money& amount1, const Money& amount2)
{
    return (amount1.all_cents > amount2.all_cents);
}

bool operator >=(const Money& amount1, const Money& amount2)
{
    return ((amount1.all_cents > amount2.all_cents)
            || (amount1.all_cents == amount2.all_cents));
}

Money::Money(long dollars, int cents)
{
    if(dollars*cents < 0) //If one is negative and one is positive


{
        cout << "Illegal values for dollars and cents.\n";
        exit(1);
    }
    all_cents = dollars*100 + cents;
}

Money::Money(long dollars) : all_cents(dollars*100)
{
    //Body intentionally blank.
}

Money::Money( ) : all_cents(0)
{
    //Body intentionally blank.
}

double Money::get_value( ) const
{
    return (all_cents * 0.01);
}

Money Money::percent(int percent_figure) const
{
    Money temp;
    double temp_figure;
    temp_figure = percent_figure * 0.01;
    temp.all_cents = all_cents;
    temp.all_cents = temp.all_cents * temp_figure;
    return temp;
}

//Uses iostream, cctype, cstdlib:
istream& operator >>(istream& ins, Money& amount)
{
    char one_char, decimal_point,
         digit1, digit2; //digits for the amount of cents
    long dollars;
    int cents;
    bool negative;//set to true if input is negative.

    ins >> one_char;
    if (one_char == '-')
    {
        negative = true;
        ins >> one_char; //read '$'
    }
    else
        negative = false;
    //if input is legal, then one_char == '$'

    ins >> dollars >> decimal_point >> digit1 >> digit2;

    if ( one_char != '$' || decimal_point != '.'
         || !isdigit(digit1) || !isdigit(digit2) )
    {
        cout << "Error illegal form for money input\n";
        exit(1);
    }

    cents = digit_to_int(digit1)*10 + digit_to_int(digit2);

    amount.all_cents = dollars*100 + cents;
    if (negative)
        amount.all_cents = -amount.all_cents;


return ins;
}

//Uses cstdlib and iostream:
ostream& operator <<(ostream& outs, const Money& amount)
{
    long positive_cents, dollars, cents;
    positive_cents = labs(amount.all_cents);
    dollars = positive_cents/100;
    cents = positive_cents%100;

    if (amount.all_cents < 0)
        outs << "-$" << dollars << '.';
    else
        outs << "$" << dollars << '.';

    if (cents < 10)
        outs << '0';
    outs << cents;

    return outs;
}
int main( )
{
    Money amount;
    ifstream in_stream;
    ofstream out_stream;

    in_stream.open("infile.dat");
    if (in_stream.fail( ))
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }

    out_stream.open("outfile.dat");
    if (out_stream.fail( ))
    {
        cout << "Output file opening failed.\n";
        exit(1);
    }


    in_stream >> amount;
    out_stream << amount
              << " copied from the file infile.dat.\n";
    cout << amount
         << " copied from the file infile.dat.\n";

    Money amount1(30,75), amount2(100,10);

    if(amount1 < amount2)
        cout << amount1 << " less than " << amount2 << endl;
    else
        cout << amount1 << " not less than " << amount2 << endl;

    if(amount1 <= amount2)
        cout << amount1 << " less than or equal to " << amount2 << endl;
    else
        cout << amount1 << " not less than or equal to " << amount2 << endl;

    if(amount1 > amount2)
        cout << amount1 << " greater than " << amount2 << endl;
    else
        cout << amount1 << " not greater than " << amount2 << endl;

    if(amount1 >= amount2)
        cout << amount1 << " greater than or equal to " << amount2 << endl;
    else
        cout << amount1 << " not greater than or equal to " << amount2 << endl;

    Money amount3;
    amount3 = amount2.percent(10);
    cout << amount3 << endl;

    in_stream.close( );
    out_stream.close( );

    return 0;
}

int digit_to_int(char c)
{
    return (static_cast<int>(c) - static_cast<int>('0') );
}
