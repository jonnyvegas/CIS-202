#include<iostream>
#include<math.h>

using namespace std;

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
    Polynomial();
    Polynomial(int the_coefficient);
    Polynomial(int the_coefficient, int the_power);
    Polynomial(const Polynomial& right_side);
    ~Polynomial();
    void input();
    void output();
    bool empty() const;
    int evaluate(int the_variable);
    friend Polynomial operator +(const Polynomial& first, const Polynomial& second);
    friend Polynomial operator -(const Polynomial& first, const Polynomial& second);
    friend Polynomial operator *(const Polynomial& first, const Polynomial& second);
    void operator =(const Polynomial& right_side);
private:
    PolyNodePtr head;
};

Polynomial::Polynomial()
{
    PolyNodePtr temp;
    temp = new PolyNode;
    temp->power = 0;
    temp->coefficient = 0;
    temp->link = NULL;
    head = temp;
}

Polynomial::Polynomial(int the_coefficient)
{
    PolyNodePtr temp;
    temp = new PolyNode;
    temp -> power = 0;
    temp -> coefficient = the_coefficient;
    temp -> link = NULL;
    head = temp;
}

Polynomial::Polynomial(int the_coefficient, int the_power)
{
    PolyNodePtr temp;
    temp = new PolyNode;
    temp->power = the_power;
    temp->coefficient = the_coefficient;
    temp->link = NULL;
    head = temp;
}

Polynomial::Polynomial(const Polynomial& right_side)
{
    PolyNodePtr temp, temp2;
    int num_of_items = 0;
    bool first_coefficient = true;
    for(temp = right_side.head; temp != NULL; temp = temp->link)
    {
        num_of_items++;
    }
    //cout << "Number of items: " << num_of_items << endl;
    do
    {
        temp = right_side.head;
        for(int i = num_of_items; i > 1; i--)
        {
            temp = temp->link;
        }
        if(first_coefficient)
        {
            temp2 = new PolyNode;
            temp2->coefficient = temp->coefficient;
            temp2->power = temp->power;
            temp2->link = NULL;
            head = temp2;
            first_coefficient = false;
        }
        else
        {
            temp2 = new PolyNode;
            temp2->coefficient = temp->coefficient;
            temp2->power = temp->power;
            temp2->link = head;
            head = temp2;
        }
        num_of_items--;
    }while(num_of_items > 0);
}

Polynomial::~Polynomial()
{
    while(!empty())
    {
        PolyNodePtr temp_ptr = head;
        head = head->link;
        delete temp_ptr;
    }
}

bool Polynomial::empty() const
{
    return (head == NULL);
}

void Polynomial::input()
{
    PolyNodePtr temp;
    bool first = true;
    bool negative = false;
    char next;
    int param1 = 0, count = 0, param2 = 0;
    cin.get(next);
    while(next != '\n')
    {
        if(isdigit(next))
        {
            if(count == 0)//first parameter
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
                param2 = next - '0';
                if(first)
                {
                    temp = new PolyNode;
                    temp->coefficient = param1;
                    temp->power = param2;
                    temp->link = NULL;
                    head = temp;
                    first = false;
                }
                else
                {
                    temp = new PolyNode;
                    temp->coefficient = param1;
                    temp->power = param2;
                    temp->link = head;
                    head = temp;
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
                temp = new PolyNode;
                temp->coefficient = param1;
                temp->power = 0;
                temp->link = NULL;
                head = temp;
                first = false;
            }
            else
            {
                temp = new PolyNode;
                temp->coefficient = param1;
                temp->power = 0;
                temp->link = head;
                head = temp;
            }
        }
        cin.get(next);
    }
    if(next == '\n')
    {
        if(first)
        {
            temp = new PolyNode;
            temp->coefficient = param1;
            temp->power = 0;
            temp->link = NULL;
            head = temp;
            first = false;
        }
        else
        {
            temp = new PolyNode;
            temp->coefficient = param1;
            temp->power = 0;
            temp->link = head;
            head = temp;
        }
    }
}

void Polynomial::output()
{
    int num_of_terms = 0;
    bool negative = false, last = false, first = true, next_to_last = false;
    cout << "The polynomial is: ";
    PolyNodePtr temp;
    for(temp = head; temp->link != NULL; temp = temp->link)
    {
        num_of_terms++;
    }
    if(temp->link == NULL)
    {
        num_of_terms++;
    }
    do
    {
        temp = head;
        for(int i = num_of_terms; i > 1; i--)//step through until we are at the term we want to print
        {
            temp = temp->link;
        }
        if(temp -> coefficient != 0)
        {
            cout << temp->coefficient;
        }
        if(temp -> power == 0 && temp -> coefficient == 0)//the input was 0 for the last term.
        {
            cout << temp->coefficient;
        }
        if(temp->power != 0 && temp -> coefficient != 0)
        {
            cout << "x^" << temp->power;
        }
        if(num_of_terms == 1)
        {
            last = true;
        }
        temp = head;
        for(int i = num_of_terms - 1; i > 1; i--)
        {
            temp = temp -> link;
        }
        if(temp->coefficient < 0)//next number is negative
        {
            negative = true;
        }
        else
        {
            negative = false;
        }
        if ((negative == false) && (last == false))//next number is not negative and we are not on the last #.
        {
            cout << "+";
        }
        num_of_terms--;
    }while(num_of_terms != 0);
    cout << endl;
}

int Polynomial::evaluate(int the_variable)
{
    PolyNodePtr temp;
    int sum = 0;
    for (temp = head; temp != NULL; temp = temp->link)
    {
        int new_num;
        new_num = (temp->coefficient * pow(the_variable, temp->power));
        sum = sum + new_num;
    }
    return sum;
}

Polynomial operator +(const Polynomial& first, const Polynomial& second)
{
    Polynomial third;
    PolyNodePtr temp, temp2, temp3;
    int num_of_terms1 = 0, num_of_terms2 = 0;
    bool first_coefficient = true;
    for (temp = first.head; temp != NULL; temp = temp->link)
    {
        num_of_terms1++;
    }
    for (temp2 = second.head; temp2 != NULL; temp2 = temp2->link)
    {
        num_of_terms2++;
    }
    do
    {
        if(num_of_terms1 == num_of_terms2)
        {
            temp = first.head;
            temp2 = second.head;
            for(int i = num_of_terms1; i > 1; i--)
            {
                temp = temp->link;
            }
            for(int i = num_of_terms2; i > 1; i--)
            {
                temp2 = temp2->link;
            }
            if(temp->power == temp2->power)
            {
                if(first_coefficient)
                {
                    temp3 = new PolyNode;
                    temp3->coefficient = (temp->coefficient + temp2->coefficient);
                    temp3->power = (temp->power);
                    temp3->link = NULL;
                    first_coefficient = false;
                    third.head = temp3;
                }
                else
                {
                    temp3 = new PolyNode;
                    temp3->coefficient = (temp->coefficient + temp2->coefficient);
                    temp3->power = (temp->power);
                    temp3->link = third.head;
                    third.head = temp3;
                }
            }
            else if(temp->power > temp2->power)
            {
                if(first_coefficient)
                {
                    temp3 = new PolyNode;
                    temp3->coefficient = temp->coefficient;
                    temp3->power = temp->power;
                    temp3->link = NULL;
                    third.head = temp3;
                    first_coefficient = false;

                    temp3 = new PolyNode;
                    temp3->coefficient = temp2->coefficient;
                    temp3->power = temp2->power;
                    temp3->link=third.head;
                    third.head = temp3;
                }
                else
                {
                    temp3 = new PolyNode;
                    temp3->coefficient = temp->coefficient;
                    temp3->power = temp->power;
                    temp3->link = third.head;
                    third.head = temp3;

                    temp3 = new PolyNode;
                    temp3->coefficient = temp2->coefficient;
                    temp3->power = temp2->power;
                    temp3->link = third.head;
                    third.head = temp3;
                }
            }
            else
            {
                if(first_coefficient)
                {
                    temp3 = new PolyNode;
                    temp3->coefficient = temp2->coefficient;
                    temp3->power = temp2->power;
                    temp3->link = NULL;
                    third.head = temp3;
                    first_coefficient = false;

                    temp3 = new PolyNode;
                    temp3->coefficient = temp->coefficient;
                    temp3->power = temp->power;
                    temp3->link = third.head;
                    third.head = temp3;
                }
                else
                {
                    temp3 = new PolyNode;
                    temp3->coefficient = temp2->coefficient;
                    temp3->power = temp2->power;
                    temp3->link = third.head;
                    third.head = temp3;

                    temp3 = new PolyNode;
                    temp3->coefficient = temp->coefficient;
                    temp3->power = temp->power;
                    temp3->link = third.head;
                    third.head = temp3;
                }
            }
            num_of_terms1--;
            num_of_terms2--;
        }
        else if(num_of_terms1 > num_of_terms2)//first polynomial has more terms.
        {
            temp = first.head;
            temp2 = second.head;
            for(int i = num_of_terms1; i > 1; i--)//get first number in list.
            {
                temp = temp->link;
            }
            if(first_coefficient)//The first coefficient in the list.
            {
                temp3 = new PolyNode;
                temp3->coefficient = temp->coefficient;
                temp3->power = temp->power;
                temp3->link = NULL;
                third.head = temp3;
                first_coefficient = false;
            }
            else
            {
                temp3 = new PolyNode;
                temp3->coefficient = temp->coefficient;
                temp3->power = temp->power;
                temp3->link = third.head;
                third.head = temp3;
            }
            num_of_terms1--;
        }
        else //num_of_terms2 is larger
        {
            temp = first.head;
            temp2 = second.head;
            for(int i = num_of_terms2; i > 1; i--)
            {
                temp2 = temp2->link;
            }
            if(first_coefficient)//We are creating the first coefficient
            {
                temp3 = new PolyNode;
                temp3->coefficient = temp2->coefficient;
                temp3->power = temp2->power;
                temp3->link = NULL;
                third.head = temp3;
                first_coefficient = false;
            }
            else
            {
                temp3 = new PolyNode;
                temp3->coefficient = temp2->coefficient;
                temp3->power = temp2->power;
                temp3->link = third.head;
                third.head = temp3;
            }
            num_of_terms2--;
        }
    }while(num_of_terms1 > 0 && num_of_terms2 > 0);
    return third;
}

Polynomial operator -(const Polynomial& first, const Polynomial& second)
{
    Polynomial third;
    PolyNodePtr temp, temp2, temp3;
    int num_of_terms1 = 0, num_of_terms2 = 0;
    bool first_coefficient = true;
    for (temp = first.head; temp != NULL; temp = temp->link)
    {
        num_of_terms1++;
    }
    for (temp2 = second.head; temp2 != NULL; temp2 = temp2->link)
    {
        num_of_terms2++;
    }
    do
    {
        if(num_of_terms1 == num_of_terms2)
        {
            temp = first.head;
            temp2 = second.head;
            for(int i = num_of_terms1; i > 1; i--)
            {
                temp = temp->link;
            }
            for(int i = num_of_terms2; i > 1; i--)
            {
                temp2 = temp2->link;
            }
            if(temp->power == temp2->power)
            {
                if(first_coefficient)
                {
                    temp3 = new PolyNode;
                    temp3->coefficient = (temp->coefficient - temp2->coefficient);
                    temp3->power = (temp->power);
                    temp3->link = NULL;
                    first_coefficient = false;
                    third.head = temp3;
                }
                else
                {
                    temp3 = new PolyNode;
                    temp3->coefficient = (temp->coefficient - temp2->coefficient);
                    temp3->power = temp->power;
                    temp3->link = third.head;
                    third.head = temp3;
                }
            }
            else if(temp->power > temp2->power)
            {
                if(first_coefficient)
                {
                    temp3 = new PolyNode;
                    temp3->coefficient = temp->coefficient;
                    temp3->power = temp->power;
                    temp3->link = NULL;
                    third.head = temp3;
                    first_coefficient = false;

                    temp3 = new PolyNode;
                    temp3->coefficient = (temp2->coefficient) * -1;
                    temp3->power = temp2->power;
                    temp3->link=third.head;
                    third.head = temp3;
                }
                else
                {
                    temp3 = new PolyNode;
                    temp3->coefficient = temp->coefficient;
                    temp3->power = temp->power;
                    temp3->link = third.head;
                    third.head = temp3;

                    temp3 = new PolyNode;
                    temp3->coefficient = (temp2->coefficient) * -1;
                    temp3->power = temp2->power;
                    temp3->link = third.head;
                    third.head = temp3;
                }
            }
            else
            {
                if(first_coefficient)
                {
                    temp3 = new PolyNode;
                    temp3->coefficient = (temp2->coefficient) * -1;
                    temp3->power = temp2->power;
                    temp3->link = NULL;
                    third.head = temp3;
                    first_coefficient = false;

                    temp3 = new PolyNode;
                    temp3->coefficient = temp->coefficient;
                    temp3->power = temp->power;
                    temp3->link = third.head;
                    third.head = temp3;
                }
                else
                {
                    temp3 = new PolyNode;
                    temp3->coefficient = (temp2->coefficient) * -1;
                    temp3->power = temp2->power;
                    temp3->link = third.head;
                    third.head = temp3;

                    temp3 = new PolyNode;
                    temp3->coefficient = temp->coefficient;
                    temp3->power = temp->power;
                    temp3->link = third.head;
                    third.head = temp3;
                }
            }
            num_of_terms1--;
            num_of_terms2--;
        }
        else if(num_of_terms1 > num_of_terms2)//first polynomial has more terms.
        {
            temp = first.head;
            temp2 = second.head;
            for(int i = num_of_terms1; i > 1; i--)
            {
                temp = temp->link;
            }
            if(first_coefficient)
            {
                temp3 = new PolyNode;
                temp3->coefficient = temp->coefficient;
                temp3->power = temp->power;
                temp3->link = NULL;
                third.head = temp3;
                first_coefficient = false;
            }
            else
            {
                temp3 = new PolyNode;
                temp3->coefficient = temp->coefficient;
                temp3->power = temp->power;
                temp3->link = third.head;
                third.head = temp3;
            }
            num_of_terms1--;
        }
        else //num_of_terms2 is larger aka second list is larger
        {
            temp = first.head;
            temp2 = second.head;
            for(int i = num_of_terms2; i > 1; i--)
            {
                temp2 = temp2->link;
            }
            if(first_coefficient)
            {
                temp3 = new PolyNode;
                temp3->coefficient = (temp2->coefficient) * -1;
                temp3->power = temp2->power;
                temp3->link = NULL;
                third.head = temp3;
                first_coefficient = false;
            }
            else
            {
                temp3 = new PolyNode;
                temp3->coefficient = (temp2->coefficient) * -1;
                temp3->power = temp2->power;
                temp3->link = third.head;
                third.head = temp3;
            }
            num_of_terms2--;
        }
    }while(num_of_terms1 > 0 && num_of_terms2 > 0);
    return third;
}

Polynomial operator *(const Polynomial& first, const Polynomial& second)
{
    Polynomial third;
    PolyNodePtr temp, temp2, temp3;
    int num_of_terms1 = 0, num_of_terms2 = 0, count1 = 0, count2 = 0;
    bool first_coefficient = true, second_list_done = false;
    for (temp = first.head; temp != NULL; temp = temp->link)
    {
        count1++;
    }
    for (temp2 = second.head; temp2 != NULL; temp2 = temp2->link)
    {
        count2++;
    }
    num_of_terms1 = count1;
    num_of_terms2 = count2;
    do
    {
        temp = first.head;
        temp2 = second.head;
        for(int i = num_of_terms1; i > 1; i--)
        {
            temp = temp->link;
        }

        for(int i = num_of_terms2 ; i > 1; i--)
        {
            temp2 = temp2->link;
        }
        num_of_terms2--;
        if(first_coefficient)
        {
            temp3 = new PolyNode;
            temp3->coefficient = (temp->coefficient * temp2->coefficient);
            temp3->power = (temp->power + temp2->power);
            temp3->link = NULL;
            third.head = temp3;
            first_coefficient = false;
        }
        else
        {
            temp3 = new PolyNode;
            temp3->coefficient = (temp->coefficient * temp2->coefficient);
            temp3->power = (temp->power + temp2->power);
            temp3->link = third.head;
            third.head = temp3;
        }
        if(num_of_terms2 == 0)
        {
            num_of_terms1--;
            num_of_terms2 = count2;
        }
    }while(num_of_terms1 > 0);
    return third;
}

void Polynomial::operator =(const Polynomial& right_side)
{
    PolyNodePtr temp, temp2;
    int num_of_items = 0;
    bool first_coefficient = true;
    for(temp = right_side.head; temp != NULL; temp = temp->link)
    {
        num_of_items++;
    }
    //cout << "Number of items: " << num_of_items << endl;
    do
    {
        temp = right_side.head;
        for(int i = num_of_items; i > 1; i--)
        {
            temp = temp->link;
        }
        if(first_coefficient)
        {
            temp2 = new PolyNode;
            temp2->coefficient = temp->coefficient;
            temp2->power = temp->power;
            temp2->link = NULL;
            head = temp2;
            first_coefficient = false;
        }
        else
        {
            temp2 = new PolyNode;
            temp2->coefficient = temp->coefficient;
            temp2->power = temp->power;
            temp2->link = head;
            head = temp2;
        }
        num_of_items--;
    }while(num_of_items > 0);
}

int main()
{
    Polynomial p1, p2, p3;
    cout << "Please enter a polynomial: ";
    p1.input();
    p1.output();
    cout << "Please enter another polynomial: ";
    p2.input();
    p2.output();
    p3 = p1 + p2;
    cout << "Added together: " << endl;
    p3.output();
    p3 = p1 - p2;
    cout << "Subtracted: " << endl;
    p3.output();
    p3 = p1 * p2;
    cout << "Multiplied: " << endl;
    p3.output();
    int v1, v2, ans1, ans2;
    cout << "Please enter an integer to evaluate for x for the 1st: ";
    cin >> v1;
    cin.ignore(1);
    ans1 = p1.evaluate(v1);
    cout << "The answer to the 1st with " << v1 << " plugged in is: " << endl;
    cout << ans1 << endl;
    cout << "Please enter an integer to evaluate for x for the 2nd: ";
    cin >> v2;
    cin.ignore(1);
    ans2 = p2.evaluate(v2);
    cout << "The answer to the 2nd with " << v2 << " plugged in is: " << endl;
    cout << ans2 << endl;

    return 0;
}
