#include <iostream>
#include <math.h>
using namespace std;

struct PolyFrame
{
    int coefficient;
    int power;
    PolyFrame *link;
};
typedef PolyFrame* PolyFramePtr;

class Polynomial
{
public:
    Polynomial();
    Polynomial(int the_coefficient, Polynomial *next);
    Polynomial(int the_coefficient, int the_power, Polynomial *next);
private:
    PolyFramePtr head1;
    PolyFramePtr head2
};

Polynomial::Polynomial() : coefficient(0), power(0), link(NULL)
{

}

Polynomial::Polynomial(int the_coefficient, PolyNode *next) : coefficent(the_coefficient), power(0), link(next)
{

}

Polynomial::Polynomial(int the_coefficient, int the_power)

int main()
{

    return 0;
}
