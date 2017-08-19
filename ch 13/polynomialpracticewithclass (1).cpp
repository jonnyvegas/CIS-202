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
    int param1 = 0, count = 0;
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
                cin.get(next);
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
    }
}

void Polynomial::output(Polynomial *&the_head)
{
    int count = 0;
    cout << "You entered: ";
    PolyPtr temp;
    for(temp = the_head; temp->get_link() != NULL; temp = temp->get_link())
    {
        //cout << "coefficient: " << temp->get_coefficient() << " power: " << temp->get_power() << endl;
        count++;
    }
    if(temp->get_link() == NULL)
    {
        //cout << "coefficient: " << temp->get_coefficient() << " power: " << temp->get_power() << endl;
        count++;
    }
    //cout << "number of terms: " << count << endl;
    int num_of_terms = count;
    do
    {
        temp = the_head;
        for(int i = num_of_terms; i > 1; i--)
        {
            temp = temp->get_link();
        }
        cout << temp->get_coefficient();
        if(temp->get_power() == 0)
        {
            //print nothing;
        }
        else
        {
            cout << "x^" << temp->get_power();
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

void head_insert(int the_coefficient, int the_power, PolyPtr& head)
{
    PolyPtr temp;
    temp = new Polynomial(the_coefficient, the_power, head);
    head = temp;
}

void head_insert(int the_coefficient, PolyPtr& head)
{
    PolyPtr temp;
    temp = new Polynomial(the_coefficient, head);
    head = temp;
}

int main()
{
    PolyPtr head;
    Polynomial p1;
    int the_x, ans = 0;
    p1.input(head);
    p1.output(head);
    cout << "Please enter an x: ";
    cin >> the_x;
    ans = p1.evaluate(the_x, head);
    cout << "The answer is: " << ans;
    return 0;
}
