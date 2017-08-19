//Name: Jonathan Villegas
//Assignment: Assume proper includes have been executed,
//but not using directive or declaration. Write a
//definition of an iterator for a vector named vec
//of int values. Write a for loop that will display the
//contents vec on the screen, separated by spaces. Use iterators for the loop control.
//Date: 5/29/14
//Email: jonathan.e.villegas@gmail.com
//Filename: final3.cpp

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
    for(iter = vec.begin(); iter != vec.end(); iter++)
    {
        std::cout << *iter << " ";
    }
}
