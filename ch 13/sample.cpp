#include<iostream>
#include<iomanip>
#include<ctype>
class node
{
public :
    int coeff;
    int power;
    node *next;
};
class polynomial
{
private :
    node *head;
public :
    polynomial()
    {
        head=NULL;
    }
    ~polynomial();
    void read();
    void display();
    void add(polynomial &p1,polynomial &p2);
    void addnodeatend(int coef,int power);
};
void polynomial::add(polynomial &p1,polynomial &p2)
{
    node *ptr1,*ptr2;
    int powe;
    int coef;
    ptr1=p1.head;
    ptr2=p2.head;
    while((ptr1!=NULL)&&(ptr2!=NULL))
    {
        if(ptr1->power > ptr2->power)
        {
            coef=ptr1->coeff;
            powe=ptr1->power;
            ptr1=ptr1->next;
        }
        else if(ptr1->power < ptr2->power)
        {
            coef=ptr2->coeff;
            powe=ptr1->power;
            ptr2=ptr2->next;
        }
        else
        {
            coeff=ptr1->coeff+ptr2->coeff;
            powe=ptr1->power;
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        if(coef!=0)
            addnodeatend(coef,powe);
    }
        if(ptr1==NULL)
        {
            for(;ptr2!=NULL;pt2=ptr2->next)
                addnodeatend(ptr2->coeff,ptr2->power);
        }
        else if(ptr2==NULL)
        {
            for(;pt1!=NULL;ptr1=ptr1->next)
                addnodeatend(ptr1->coeff,ptr1->power);
        }
}
void polynomial::addnodeatend(int coef,int power)
{
    node *ptr1,*ptr2;
    ptr1=new node;
    ptr1->coeff=coef;
    ptr1->power=powe;
    ptr1->next=NULL;
    if(head==NULL)
    {
        head=ptr1;
    }
    else
    {
        ptr2=head;
        while(ptr2->next!=NULL)
        {
            ptr2=ptr2->next;
        }
        ptr2->next=ptr1;
    }
}
void polynomial::read()
{
    char ch;
    int coef,powe;
    cout<<"\nEnter the terms in descending order of power";
    while(1)
    {
        cout<<"\nEnter the degree of x :";
        cin>>powe;
        cout<<"\nEnter the coefficient :";
        cin>>coef;
        addnodeatend(coef,powe);
        cout<<"\nAny more term (Y/N) ? :";
        cin>>ch;
        if(toupper(ch)=='Y')
            continue;
        else
            break;
    }
}
void polynomial::display()
{
    if(head!=NULL)
        cout<<head->coeff<<"x^"<<head->power;
    node *ptr=head;
    for(ptr=ptr->next;ptr!=NULL;ptr=ptr->next)
    {
        if(ptr->coeff!=0)
        {
            if(ptr->coeff>0)
                cout<<"+";
            if(ptr->coeff<0)
            {
                cout<<"-";
                ptr->coeff=-ptr->coeff;
            }
            if(ptr->power==0)
                cout<<ptr->coeff;
            else if(ptr->power==1)
                cout<<ptr->coeff<<"x";
            else
                cout<<ptr->coeff<<"x^"<<ptr->power;
        }
    }
}
polynomial::~polynomial()
{
    node *temp,*ptr=head;
    while(ptr!=0)
    {
        temp=ptr;
        ptr=ptr->next;
        delete temp;
    }
}
void main()
{
    polynomial poly1,poly2,poly3;
    cout<<"\nPolynomial to add two polynomials:";
    cout<<"\n++++++++++++++++++++++++++++++++++++\n\n";
    cout<<"Enter first polynomial\n";
    poly1.read();
    cout<<"\n\nEnter second polynomial\n";
    poly2.read();
    poly3.add(poly1,poly2);
    cout<<"\nSum of polynomials\n\n";
    poly1.display();
    cout<<"\n\nand\n\n";
    poly2.display();
    cout<<"\n\nis\n\n";
    poly3.display();
}
