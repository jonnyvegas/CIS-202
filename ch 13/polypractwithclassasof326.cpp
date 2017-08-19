#include <iostream>
#include <math.h>

using namespace std;

class Polynomial
{
public:
    Polynomial();
    Polynomial(int the_coefficient, Polynomial *the_link);
    Polynomial(int the_coefficient, int the_power, Polynomial *the_link);
    ~Polynomial();
    void input(Polynomial *&the_head);
    void output(Polynomial *&the_head);
    int evaluate(int the_variable, Polynomial *&the_head);
    int get_coefficient();
    int get_power();
    Polynomial* get_link();
private:
    int coefficient;
    int power;
    Polynomial *next;
};
typedef Polynomial* PolyPtr;

PolyPtr head, second_head;

Polynomial::Polynomial() : coefficient(0), power(0), next(NULL)
{}

Polynomial::Polynomial(int the_coefficient, Polynomial *the_link) : coefficient(the_coefficient), power(0), next(the_link)
{}

Polynomial::Polynomial(int the_coefficient, int the_power, Polynomial *the_link) : coefficient(the_coefficient), power(the_power), next(the_link)
{}

Polynomial::~Polynomial()
{}

void head_insert(int the_coefficient, int the_power, PolyPtr& head);

void head_insert(int the_coefficient, PolyPtr& head);

void Polynomial::input(Polynomial *&the_head)
{
    PolyPtr temp;
    bool first = true;
    bool negative = false;
    char next;
    int param1, count = 0;
    cout << "Please enter a polynomial: ";
    cin.get(next);
    while(next != '\n')
    {
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
                if(next == '\n')
                {
                    if(first)
                    {
                        the_head = new Polynomial(param1, NULL);
                        first = false;
                    }
                    else
                    {
                        head_insert(param1, the_head);
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
                    the_head = new Polynomial(param1, param2, NULL);
                    first = false;
                }
                else
                {
                    head_insert(param1, param2, the_head);
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
        cin.get(next);
    }
}

void Polynomial::output(Polynomial *&the_head)
{
    int count = 0;
    cout << "You entered: ";
    PolyPtr temp;
    cout << "declaring pointer..." << endl;
    for(temp = the_head; temp->get_link() != NULL; temp = temp->get_link())
    {
        cout << "coefficient: " << temp->get_coefficient() << endl;
        cout << "counting next link..." << endl;
        count++;
        cout << "count is: " << count << endl;
    }
    if(temp->get_link() == NULL)
    {
        cout << "counting null link..." << endl;
        count++;
        cout << "count is: " << count << endl;
    }
    int num_of_terms = count;
    cout << "Setting num of terms..." << endl;
    cout << "Number of terms: " << num_of_terms << endl;
    do
    {
        temp = the_head;
        for(int i = num_of_terms; i > 1; i--)
        {
            temp = temp->get_link();
        }
        cout << temp->get_coefficient();
        if(temp->get_power() != 0)
        {
           cout << "x^" << temp->get_power();
        }
        if(temp->get_link() != NULL)
        {
            cout << temp->get_coefficient();
        }
        if(num_of_terms == 1)
        {
            //print nothing.
        }
        else
        {
            cout << "+";
        }
        num_of_terms--;
    }while(num_of_terms != 0);
    cout << endl;
}

int Polynomial::evaluate(int the_variable, Polynomial *&the_head)
{
    PolyPtr temp;
    int sum = 0;
    for (temp = the_head; temp != NULL; temp = temp->get_link())
    {
        int new_num;
        new_num = (temp->get_coefficient() * pow(the_variable, temp -> get_power()));
        sum = sum + new_num;
    }
    return sum;
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
    return next;
}

void head_insert(int the_coefficient, int the_power, Polynomial *&the_head)
{
    PolyPtr temp;
    temp = new Polynomial(the_coefficient, the_power, the_head);
    the_head = temp;
}

void head_insert(int the_coefficient, Polynomial *&the_head)
{
    PolyPtr temp;
    temp = new Polynomial(the_coefficient, the_head);
    the_head = temp;
}

int main()
{
    Polynomial p1, p2;
    PolyPtr head, second_head;
    int the_x, ans = 0;
    p1.input(head);
    p1.output(head);
    p2.input(second_head);
    p2.output(second_head);
    return 0;
}
