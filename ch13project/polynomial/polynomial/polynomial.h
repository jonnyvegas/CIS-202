//Name: Jonathan Villegas
//Assignment: Design and implement a class whose objects represent polynomials. The
//polynomial will be implemented as a linked list. Each node will contain an int value
//for the power of x and an int value for the corresponding coefficient. The
//class operations should include addition, subtraction, multiplication, and
//evaluation of a polynomial. Overload the operators +, -, and * for
//addition, subtraction, and multiplication
//Date: 4/13/14
//Email: jonathan.e.villegas@gmail.com
//filename: polynomial.h

#ifndef POLYNOMIAL_H_INCLUDED
#define POLYNOMIAL_H_INCLUDED
#include <iostream>
using namespace std;

namespace villegaspolynomial
{
    //Structure for a polynomial
    struct PolyNode
    {
        int coefficient;
        int power;
        PolyNode *link;
    };
    typedef PolyNode *PolyNodePtr;

    class Polynomial
    {
    public:
        //Constructors:
        Polynomial();
        Polynomial(int the_coefficient);
        Polynomial(int the_coefficient, int the_power);
        Polynomial(const Polynomial& right_side);
        //Destructor:
        ~Polynomial();
        //Input and ouput functions
        void input();
        void output();
        //empty returns true if there is no polynomial.
        bool empty() const;
        //Returns an int after plugging in the_variable into the polynomial and evaluating.
        int evaluate(int the_variable);
        //Operators:
        friend Polynomial operator +(const Polynomial& first, const Polynomial& second);
        friend Polynomial operator -(const Polynomial& first, const Polynomial& second);
        friend Polynomial operator *(const Polynomial& first, const Polynomial& second);
        void operator =(const Polynomial& right_side);
    private:
        PolyNodePtr head;
    };
}
#endif // POLYNOMIAL_H_INCLUDED
