/* Assignment: 3
Campus: Ashdod
Author:oz ben zaken, ID: 204015614 */

#pragma once
#ifndef DATE_H
#define DATE_H
#include <stdexcept>
#include <iostream>
using namespace std;
class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date(int day = 0, int month = 0, int year = 0): day(day), month(month), year(year){}  //c'tor
	Date(const Date& temp):day(temp.day), month(temp.month), year(temp.year) {}  //coppy c'tor

	//get functions
	int getDay()const{ return day; }
	int getMonth()const{ return month; }
	int getYear()const{ return year; }

	//set functions
	void setDay(int day){ this->day = day; }
	void setMonth(int month){ this->month = month; }
	void setYear(int year){ this->year = year; }
	
	//operator = that replicate the parmeter date and put it in the parameter that called te function
	const Date& operator=(const Date& temp){ day = temp.day; month = temp.month; year = temp.year; return *this; }

	//operator == that return true if the dates are exacly alike
	bool operator==(Date temp){ if (day == temp.day && month == temp.month && year == temp.year) return true; else return false; }

	//print function which friend ostream
	friend ostream& operator<<(ostream& out, const Date& temp){ out << temp.getDay() << "/" << temp.getMonth() << "/" << temp.getYear(); return out; }

	//cin function which friend istream
	friend istream& operator>>(istream& in, Date& temp);

	//function that returns true if year from the date that called the function is leaped year
	bool isLeapYear() const;

	//function that returns the number of dayes in the corrent mounth
	int getNumOfDaysInMonth();


	~Date();//d'tor
};

#endif