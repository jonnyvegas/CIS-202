//Name: Jonathan Villegas
//Assignment: Create a class called VectorDouble that acts
//as though vectors were not defined in C++. Must have push_back,
//add_element, capacity, size, overloading of ==, =,
//and output and input operators.
//Date: 3/3/14
//Email: jonathan.e.villegas@gmail.com

#include <iostream>
using namespace std;

class VectorDouble
{
public:
    VectorDouble();
    VectorDouble(int size);//Constructors
    VectorDouble(const VectorDouble& vector_object);//Copy constructor
    ~VectorDouble(); //Destructor

    void operator =(const VectorDouble& right_side);
    friend bool operator ==(const VectorDouble& vector1, const VectorDouble& vector2);

    void add_element(double num);//Adds an element to an array and checks capacity. If too small, capacity is doubled.
    void push_back(int myInt);//Adds an element, does not check for capacity
    int capacity();//Maximum number of elements in array
    int size();//Number of elements in array
    void reserve(int num);//Make sure the array is at least num elements large
    void resize(int num);//Change the size of the array

    double value_at(int elementNumber);//Returns the value of the array at that elementNumber
    void change_value_at(double newAmount, int elementNumber);//Puts the newAmount in the place of the elementNumber

    friend ostream& operator <<(ostream& outs, const VectorDouble& the_array);
private:
    double *value;
    int max_count;
    int count;
};

VectorDouble::VectorDouble() : max_count(50)
{
    value = new double[max_count];
    count = 0;
}

VectorDouble::VectorDouble(int size) : max_count(size)
{
    value = new double[max_count];
    count = 0;
}

VectorDouble::VectorDouble(const VectorDouble& vector_object)
{
    max_count = vector_object.max_count;
    value = new double[max_count];
    count = vector_object.count;
    for (int i = 0; i <= count; i++)
        value[i] = vector_object.value[i];
}

VectorDouble::~VectorDouble()
{
    delete [] value;
}

void VectorDouble::operator =(const VectorDouble& right_side)
{
    max_count = right_side.max_count;
    count = right_side.count;
    value = new double[max_count];
    for (int i = 0; i <= right_side.count; i++)
        value[i] = right_side.value[i];
}

bool operator ==(const VectorDouble& vector1, const VectorDouble& vector2)
{
    bool compare;

    if(vector1.count == vector2.count)
    {
        for (int i = 0; i <= vector1.count; i++)
        {
            if (vector1.value[i] == vector2.value[i])
                compare = true;
            else
                compare = false;
        }
    }
    else
    {
        compare = false;
    }
    return ((vector1.count == vector2.count) && (compare));
}

void VectorDouble::add_element(double num)
{
    if (count == max_count)//Size is max
    {
        int new_count = max_count * 2;
        double *value2 = new double[new_count];
        for (int i = 0; i <= max_count; i++)
        {
            value2[i] = value[i];
        }
        value = new double[new_count];
        for (int j = 0; j <= max_count; j++)
        {
            value[j] = value2[j];
        }
        max_count = max_count * 2;
        value[count] = num;
        count = count + 1;
    }
    else //There is enough room in the array
    {
        value[count] = num;
        count = count + 1;
    }
}

void VectorDouble::push_back(int myInt)
{
    value[count] = myInt;
    count = count + 1;
}

int VectorDouble::capacity()
{
    return max_count;
}

int VectorDouble::size()
{
    return count;
}

void VectorDouble::reserve(int num)
{
    max_count = num;
}

void VectorDouble::resize(int num)
{
    count = num;
}

double VectorDouble::value_at(int elementNumber)
{
    return value[elementNumber];
}

void VectorDouble::change_value_at(double newAmount, int elementNumber)
{
    value[elementNumber] = newAmount;
}

ostream& operator <<(ostream& outs, const VectorDouble& the_array)
{
    for (int i = 0; i < the_array.count; i++)  //Will output all elements of array to screen
        outs << the_array.value[i] << endl;
    return outs;
}

int main()
{
    VectorDouble vector1(2), vector2;

    cout << vector2.capacity() << endl;

    vector1.push_back(5);
    vector1.add_element(2);
    vector1.add_element(42);
    vector1.add_element(8);
    vector1.add_element(24);
    vector1.add_element(16);
    vector1.add_element(32);
    vector1.add_element(34);
    vector1.add_element(13);

    cout << "vector 1: " << endl;
    cout << vector1 << endl;

    cout << "vector 2: " << endl;
    cout << vector2 << endl;

    vector2 = vector1;

    if (vector1 == vector2)
        cout << "equal" << endl;
    else
        cout << "not" << endl;

    cout << vector1.value_at(3) << endl;
    vector1.change_value_at(5.5, 3);
    cout << vector1.value_at(3) << endl;
    vector2.add_element(92.4);

    if (vector1 == vector2)
        cout << "equal" << endl;
    else
        cout << "not" << endl;

    //vector1 = vector2;
    if (vector1 == vector2)
        cout << "equal" << endl;
    else
        cout << "not" << endl;

    VectorDouble vector3(vector2);
    if (vector3 == vector2)
        cout << "equal" << endl;
    else
        cout << "not" << endl;
    vector3.add_element(5.5);
    return 0;
}
