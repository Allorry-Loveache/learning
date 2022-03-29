#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
using namespace std;

class Date {
private:
	int _year;
	int _month;
	int _day;
public:
	void menu();
	Date(int year=2024, int month=3, int day=7);
	void set(int& year, int& month, int& day);
	Date& operator=(const Date& d);
	void operator+=(int x);
	void operator-=(int x);
	void Print();
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);
	int cmp(int& year, int& month, int& day);
	bool judge(int& year, int& month, int& day);
};
