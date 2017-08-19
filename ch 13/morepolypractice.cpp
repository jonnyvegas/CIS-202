#include <iostream>
#include <math.h>

using namespace std;

class Polynomial
{
public:
    Polynomial();
    Polynomial(int the_constant, Polynomial* the_link);
    Polynomial(int the_coefficient, int the_power, Polynomial* the_link);
    void set_coefficient(int the_coefficient);
    void set_power(int the_power);
    void set_link(Polynomial* the_link);
    int get_coefficient();
    int get_power();
    Polynomial* get_link();
    void input();
    void output();
    int evaluation(int the_x);
private:
    int coefficient;
    int power;
    Polynomial *link;
};
typedef Polynomial PolyPtr;

Polynomial::Polynomial() : coefficient(0), power(0), link(NULL)
{

}

Polynomial::Polynomial(int the_constant, Polynomial* the_link) : coefficient(the_constant), power(0), link(the_link)
{

}

Polynomial::Polynomial(int the_coefficient, int the_power, Polynomial* the_link) : coefficient(the_coefficient), power(the_power), link(the_link)
{

}

void Polynomial::input()
{
    int poly1, poly2;
    char next;
    cout << "Please enter a polynomial: ";
    cin >> next;
    while(next == '\n')
    {
        cin.get(next);
        if(isdigit(next))
        {

        }
    }
}

void Polynomial::output()
{

}

void Polynomial::evaluation()
{

}

void head_insert(int the_coefficient, int the_power, PolyPtr& head)
{
    PolyPtr temp;
    temp = new Polynomial(the_coefficient, the_power, head);
    head = temp;
}

int main()
{

    return 0;
}
