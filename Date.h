#pragma once
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

class Date {
private:
	int _year;
	int _month;
	int _day;
public:
	Date(int year=2024, int month=3, int day=7);
	Date& operator=(const Date& d);
	void operator+=(int x);
	void operator-=(int x);
	void Print();
};

