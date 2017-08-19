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
