#include "Date.h"
int a[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

void Date::menu() {
	printf("***************************\n");
	printf("***  1.设置日期   *********\n");
	printf("***  2.加上天数   *********\n");
	printf("***  3.减去天数   *********\n");
	printf("***  4.计算日期差值   *****\n");
	printf("***  5.退出       *********\n");
	printf("***************************\n");
	printf("目前日期%d/%d/%d\n",_year,_month,_day);
}
Date::Date(int year, int month, int day) {
	_year = year;
	_month = month;
	_day = day;
}
void Date::set(int& year, int& month, int& day) {
	_year = year, _month = month, _day = day;
	printf("输入成功\n");
}
void Date::operator+=(int x) {
	_day += x;
	while (_day > 28) {
		if (_month == 2) {
			if (_year % 400 == 0 || _year % 100 != 0 && _year % 4 == 0) {//闰年
				if (_day <= 29) break;
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

int Date:: cmp(int& year, int& month, int& day) {
	if (_year < year) return 1;
	if (_year == year && _month < month) return 1;
	if (_year == year && _month == month && _day < day) return 1;
	if (_year == year && _month == month && _day == day) return 2;
	return 0;
}

bool Date::judge(int& year, int& month, int& day) {
	return _year == year && _month == month && _day == day;
}

ostream& operator<<(ostream & out, const Date & d) {
	out << d._year << '/' << d._month << '/' << d._day << endl;
	return out;
}

istream& operator>>(istream& in, Date& d) {
	in >> d._year >> d._month >> d._day;
	return in;
}
