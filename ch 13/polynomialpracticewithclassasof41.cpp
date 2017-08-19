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
    void set_coefficient(int the_coefficient);
    void set_power(int the_power);
    void set_link(Polynomial* the_link);
    friend Polynomial operator +(const Polynomial& first, const Polynomial& second);
    friend Polynomial operator -(const Polynomial& first, const Polynomial& second);
    friend Polynomial operator *(const Polynomial& first, const Polynomial& second);
private:
    int coefficient;
    int power;
    Polynomial *next;
};
typedef Polynomial* PolyPtr;
PolyPtr head, second_head, third_head;

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
                count++;
            }
            else//count is 1. Set second parameter.
            {
                int param2 = next - '0';
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
        else if(next == '\n')
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
        }
        cin.get(next);
    }
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
    }
}

void Polynomial::output(Polynomial *&the_head)
{
    int count = 0;
    bool negative = false, last = false, first = true, next_to_last = false;
    cout << "The polynomial is: ";
    PolyPtr temp;
    for(temp = the_head; temp->get_link() != NULL; temp = temp->get_link())
    {
        count++;
    }
    if(temp->get_link() == NULL)
    {
        count++;
    }
    int num_of_terms = count;
    do
    {
        temp = the_head;
        for(int i = num_of_terms; i > 1; i--)//step through until we are at the term we want to print
        {
            temp = temp->get_link();
        }
        if(temp->get_coefficient() < 0)
        {
            negative = true;
            //cout << "Negative true. " ;
        }
        else
        {
            negative = false;
            //cout << "Negative false. ";
        }
        if(temp -> get_coefficient() != 0)
        {
            cout << temp->get_coefficient();
        }
        if(temp -> get_power() == 0 && temp -> get_coefficient() == 0)//the input was 0 for the last term.
        {
            cout << temp->get_coefficient();
        }
        if(temp->get_power() != 0 && temp -> get_coefficient() != 0)
        {
            cout << "x^" << temp->get_power();
        }
        if(num_of_terms == 1)
        {
            last = true;
        }
        else
        {
            last = false;
        }
        if(num_of_terms == 2)
        {
            next_to_last = true;
        }
        else
        {
            next_to_last = false;
        }
        if(num_of_terms == count)
        {
            first = true;
        }
        else
        {
            first = false;
        }
        if(first == true)
        {
            temp = the_head;
            for(int i = num_of_terms; i > 2; i--)
            {
                temp = temp -> get_link();
            }
            if(temp->get_coefficient() < 0)
            {
                negative = true;
                //cout << "Negative true." ;
            }
            else
            {
                negative = false;
                //cout << "Negative false." ;
            }
        }
        if ((negative == false) && (last == false))
        {
            cout << "+";
        }
        if((negative == true) && (next_to_last == true))
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

void Polynomial::set_coefficient(int the_coefficient)
{
    coefficient = the_coefficient;
}

void Polynomial::set_power(int the_power)
{
    power = the_power;
}

void Polynomial::set_link(Polynomial* the_link)
{
    next = the_link;
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

Polynomial operator +(const Polynomial& first, const Polynomial& second)
{
    PolyPtr temp, temp2, temp3;
    int count1 = 0, count2 = 0, num_of_terms1, num_of_terms2;
    bool first_coefficient = true;
    for (temp = head; temp != NULL; temp = temp -> get_link())
    {
        count1++;
    }
    for (temp2 = second_head; temp2 != NULL; temp2 = temp2 -> get_link())
    {
        count2++;
    }
    num_of_terms1 = count1;
    num_of_terms2 = count2;
    do
    {
        if(num_of_terms1 == num_of_terms2)
        {
            temp = head;
            temp2 = second_head;
            for(int i = num_of_terms1; i > 1; i--)
            {
                temp = temp -> get_link();
            }
            for(int i = num_of_terms2; i > 1; i--)
            {
                temp2 = temp2 -> get_link();
            }
            if(temp->get_power() == temp2->get_power())
            {
                if(first_coefficient)
                {
                    third_head = new Polynomial(temp->get_coefficient() + temp2->get_coefficient(),
                                                temp->get_power(), NULL);
                    first_coefficient = false;
                    temp3 = third_head;
                }
                else
                {
                    head_insert(temp->get_coefficient() + temp2->get_coefficient(), temp->get_power(), third_head);
                    temp3 = third_head;
                }
            }
            else if(temp->get_power() > temp2 -> get_power())
            {
                if(first_coefficient)
                {
                    third_head = new Polynomial(temp -> get_coefficient(), temp -> get_power(), NULL);
                    first_coefficient = false;
                    temp3 = third_head;
                    head_insert(temp2->get_coefficient(), temp2->get_power(), third_head);
                    temp3 = third_head;
                }
                else
                {
                    head_insert(temp->get_coefficient(), temp->get_power(), third_head);
                    temp3 = third_head;
                    head_insert(temp2->get_coefficient(), temp2->get_power(), third_head);
                    temp3 = third_head;
                }
            }
            else
            {
                if(first_coefficient)
                {
                    third_head = new Polynomial(temp2 -> get_coefficient(), temp2 -> get_power(), NULL);
                    first_coefficient = false;
                    temp3 = third_head;
                    head_insert(temp->get_coefficient(), temp->get_power(), third_head);
                    temp3 = third_head;
                }
                else
                {
                    head_insert(temp2->get_coefficient(), temp2->get_power(), third_head);
                    temp3 = third_head;
                    head_insert(temp->get_coefficient(), temp->get_power(), third_head);
                    temp3 = third_head;
                }
            }
            num_of_terms1--;
            num_of_terms2--;
        }
        else if(num_of_terms1 > num_of_terms2)//first polynomial has more terms.
        {
            temp = head;
            temp2 = second_head;
            for(int i = num_of_terms1; i > 1; i--)
            {
                temp = temp -> get_link();
            }
            if(first_coefficient)
            {
                third_head = new Polynomial(temp->get_coefficient(), temp->get_power(), NULL);
                    first_coefficient = false;
                    temp3 = third_head;
            }
            else
            {
                 head_insert(temp->get_coefficient(), temp->get_power(), third_head);
                 temp3 = third_head;
            }
            num_of_terms1--;
        }
        else //num_of_terms2 is larger
        {
            temp = head;
            temp2 = second_head;
            for(int i = num_of_terms2; i > 1; i--)
            {
                temp2 = temp2 -> get_link();
            }
            if(first_coefficient)
            {
                third_head = new Polynomial(temp2->get_coefficient(), temp2->get_power(), NULL);
                first_coefficient = false;
                temp3 = third_head;
            }
            else
            {
                 head_insert(temp2->get_coefficient(), temp2->get_power(), third_head);
                 temp3 = third_head;
            }
            num_of_terms2--;
        }
    }while(num_of_terms1 > 0 && num_of_terms2 > 0);
}

int main()
{
    Polynomial p1, p2;
    int the_x, ans = 0;
    p1.input(head);
    p1.output(head);
    /*
    cout << "Please enter an x to evaluate: ";
    cin >> the_x;
    cin.ignore(1);//must ignore or \n will be passed to the function.
    ans = p1.evaluate(the_x, head);
    cout << "The answer is: " << ans << endl;
    */
    p2.input(second_head);
    p2.output(second_head);
    /*
    cout << "Please enter an x to evaluate: ";
    cin >> the_x;
    cin.ignore(1);//must ignore or \n will be passed to the function.
    ans = p2.evaluate(the_x, second_head);
    cout << "The answer is: " << ans << endl;
    */
    Polynomial p3;

    p3 = p1 + p2;
    p3.output(third_head);
    return 0;
}
