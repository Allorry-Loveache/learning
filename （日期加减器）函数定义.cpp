#include "Date.h"
int a[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
Date::Date(int year, int month, int day) {
	_year = year;
	_month = month;
	_day = day;
}
void Date::operator+=(int x) {
	_day += x;
	while (_day >= 28) {
		if (_month == 2) {
			if (_year % 400 == 0 || _year % 100 != 0 && _year % 4 == 0) {
				if (_day <= 29) continue;
				else _day -= 29, _month++;
			}
			else {
				if (_day <= a[_month]) continue;
				else _day -= a[_month++];
			}
		}

		else _day -= a[_month++];

		if (_month > 12) _month = 1, _year++;
	}
}

void Date::operator-=(int x)
{
	while (x) {
		if (x >= _day) {
			_month--;
			if (_month == 0) _month = 12, _year--;
			if (_month == 2) {
				if (_year % 400 == 0 || _year % 100 != 0 && _year % 4 == 0) {
					x -= _day, _day = 29;
				}
				else x -= _day, _day = 28;
			}

			else x -= _day, _day = a[_month];
		}
		else _day -= x, x = 0;

	}
}

void Date::Print() {
	cout << _year << '/' << _month << '/' << _day << endl;
}
