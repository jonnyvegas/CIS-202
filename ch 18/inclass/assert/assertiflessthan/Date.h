//Name: Jonathan Villegas
//Assignment: Download the Date class and header and the unit test.
//Write a template version of the unit test and implement an assertIf_NE function as well.
//Date: 4/22/14
//Email: jonathan.e.villegas@gmail.com
//File: Date.h
#ifndef DATE_H
#define DATE_H
#include<string>

class Date
{
	int day,month,year,hour,minute;

	public:
	    //Constructors
		Date();
		Date(int,int);
		Date(std::string);
        //Mutator
		void setYear(int);
		//Accessor
		int getYear();
		//Returns a string with the date formatted
		std::string format(std::string);
};
#endif
