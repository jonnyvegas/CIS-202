//Name: Jonathan Villegas
//Assignment: Assume proper includes have been executed,
//but no using directive or declaration. Write a
//definition of an iterator for a vector of ints
//that is initialized to point to the first member of the vector vec.
//Date: 5/29/14
//Email: jonathan.e.villegas@gmail.com
//Filename: final2.cpp

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(10);
    vec.push_back(15);
    vec.push_back(20);
    vec.push_back(25);
    vec.push_back(30);
    vec.push_back(35);
    vec.push_back(40);
    vec.push_back(45);
    vec.push_back(50);
    std::vector<int>::iterator iter = vec.begin();
    std::cout << *iter << std::endl;
}
