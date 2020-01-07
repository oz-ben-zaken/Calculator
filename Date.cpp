/* Assignment: 3
Campus: Ashdod
Author:oz ben zaken, ID: 204015614 */

#include "Date.h"

typedef enum{ YANUAR = 1, FEBRUAR, MERCH, APRIL, MAY, YUNY, YULY, AOGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER }months;

//function that returns true if year from the date that called the function is leaped year
bool Date::isLeapYear()const
{
	if ((this->year % 400 == 0) || (this->year % 4 == 0 && this->year % 100 != 0))
		return true;

	return false;
}

//function that returns the number of dayes in the corrent mounth
int Date::getNumOfDaysInMonth()
{
	switch (this->month)
	{
	case YANUAR:
		return 31;
		break;
	case FEBRUAR:
		if (this->isLeapYear() == true)
			return 29;
		else
			return 28;
		break;
	case MERCH:
		return 31;
		break;
	case APRIL:
		return 30;
		break;
	case MAY:
		return 31;
		break;
	case YUNY:
		return 30;
		break;
	case YULY:
		return 31;
		break;
	case AOGUST:
		return 31;
		break;
	case SEPTEMBER:
		return 30;
		break;
	case OCTOBER:
		return 31;
		break;
	case NOVEMBER:
		return 30;
		break;
	case DECEMBER:
		return 31;
		break;
	}
	return 0; // shouldnt get here
}

//cin function which friend istream
istream& operator >> (istream& in, Date& temp)
{
	int integer;
	cout << "enter the year: ";
	in >> integer;
	temp.setYear(integer);
	cout << "enter the month: ";
	in >> integer;
	temp.setMonth(integer);
	cout << "enter the day: ";
	in >> integer;
	temp.setDay(integer);
	if (temp.getYear() < 2000 || temp.getMonth() < 1 || temp.getMonth() > 12)
		throw temp;
	if (temp.getDay() < 1 && temp.getDay() > temp.getNumOfDaysInMonth())
		throw temp;
	return in;
}

Date::~Date(){} //d'tor
