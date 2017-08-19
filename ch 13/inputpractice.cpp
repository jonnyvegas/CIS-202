#include <iostream>
#include <math.h>
using namespace std;

class Polynomial
{
public:
    Polynomial();
    Polynomial(int the_constant, Polynomial *the_link);
    Polynomial(int the_coefficient, int the_power, Polynomial *the_link);
    Polynomial(const Polynomial& polynomial_object);
    void set_data(int the_coefficient, int the_power);
    void set_data(int the_constant);
    void set_link(Polynomial *the_link);
    int get_coefficient();
    int get_power();
    Polynomial* get_link();
    void input();
    void output();
    int evaluate(int the_x, Polynomial *head);
private:
    int coefficient;
    int power;
    Polynomial *link;
};
typedef Polynomial* PolyPtr;


Polynomial::Polynomial() : coefficient(0), power(0), link(NULL)
{

}

Polynomial::Polynomial(int the_constant, Polynomial *the_link) : coefficient(the_constant), power(0), link(the_link)
{

}

Polynomial::Polynomial(int the_coefficient, int the_power, Polynomial *the_link) :
    coefficient(the_coefficient), power(the_power), link(the_link)
{

}

void Polynomial::set_data(int the_coefficient, int the_power)
{
    coefficient = the_coefficient;
    power = the_power;
}

void Polynomial::set_data(int the_constant)//Overloaded function
{
    coefficient = the_constant;
    power = 0;
}

void head_insert(int the_coefficient, int the_power, PolyPtr& head);

void head_insert(int the_coefficient, int the_power, PolyPtr& head)
{
    PolyPtr temp;
    temp = new Polynomial(the_coefficient, the_power, head);
    head = temp;
}

void Polynomial::set_link(Polynomial *the_link)
{
    link = the_link;
}

int Polynomial::get_coefficient()
{
    return coefficient;
}

int Polynomial::get_power()
{
    return power;
}

Polynomial* Polynomial::get_link()
{
    return link;
}

void Polynomial::input()
{
    //temporarily blank.
}

void Polynomial::output()
{
    //temporarily blank
}

int Polynomial::evaluate(int the_x, Polynomial *head)
{
    PolyPtr temp;
    temp = head;
    int sum = 0;
    for (temp = head; temp != NULL; temp = temp->get_link())
    {
        int new_num;
        new_num = (temp->get_coefficient() * pow(the_x, temp -> get_power()));
        sum = sum + new_num;
    }
    return sum;
}

int main()
{
    PolyPtr head, temp;
    bool first = true;
    bool negative = false;
    char next;
    int param1 = 0, count = 0, total = 0;//total number of items in list.
    cout << "Please enter some text: ";
    while(next != '\n')
    {
        cin.get(next);
        if(isdigit(next))
        {
            if(count == 0)
            {
                param1 = next - '0';
                if(negative)
                {
                    param1 = param1 * -1;
                    negative = false;
                }
                cout << "param1: " << param1 << endl;
                count++;
                total++;
                cin.get(next);
                if(next == '\n')
                {
                    if(first)
                    {
                        head = new Polynomial(param1, NULL);
                    }
                    else
                    {
                        head = new Polynomial(param1, head);
                    }
                    cout << "only one parameter for this call." << endl;
                }
            }
            else
            {
                int param2 = next - '0';
                cout << "param2: " << param2 << endl;
                if(first)
                {
                    head = new Polynomial(param1, param2, NULL);
                    first = false;
                }
                else
                {
                    head_insert(param1, param2, head);
                }
                count = 0;
            }
        }
        else if(next == '-')
        {
            negative = true;
        }
        else if (next == '+')
        {
            negative = false;
        }
    }
    PolyPtr iter;
    count = 1;
    for (iter = head; iter != NULL; iter = iter -> get_link())//ptint out the list
    {
        cout << "Number: " << count << " " << iter->get_coefficient()
             << "x^"  << iter -> get_power() << endl;
        count++;
    }
    cout <<"total number of items: " << total << endl;
    int input, some_num;
    cout << "Enter x: ";
    cin >> input;
    temp = head;
    some_num = temp->evaluate(input, head);
    cout << "Evaluation at " << input << " = " << some_num;

    return 0;
}
