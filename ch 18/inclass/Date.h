#ifndef DATE_H
#define DATE_H
#include<string>

class Date
{
	int day,month,year,hour,minute;

	public:
		Date();
		Date(int,int);
		Date(std::string);
	
		void setYear(int);
		int getYear();
		std::string format(std::string);
};
#endif
