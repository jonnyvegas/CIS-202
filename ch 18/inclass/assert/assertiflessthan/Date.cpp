//Name: Jonathan Villegas
//Assignment: Download the Date class and header and the unit test.
//Write a template version of the unit test and implement an assertIf_NE function as well.
//Date: 4/22/14
//Email: jonathan.e.villegas@gmail.com
//File: Date.cpp
#include "Date.h"
Date::Date()
{
}

Date::Date(int m,int d)
{
}

Date::Date(std::string d)
{
}

void Date::setYear(int y)
{
	year = y;
}

int Date::getYear()
{
	return year;
}

std::string Date::format(std::string s)
{
	std::string str("m/d/y");
	return str;
}
