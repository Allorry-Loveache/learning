#include<bits/stdc++.h>
using namespace std;
class Date {
	friend class DT;    //可以不用友元，多写几个重载
	friend istream& operator>>(istream& in, DT& x);
	int _year;
	int _day;
	int _month;
public:
	Date(int x, int y, int z) :_year(x), _month(y), _day(z) {}
	friend ostream& operator<<(ostream& out, Date& t) {
		out << t._year << '/' << t._day << '/' << t._month << ':' << ' ';
		return out;
	}
	friend istream& operator>>(istream& in, Date& t) {
		in >> t._year >> t._day >> t._month;
		return in;
	}
	operator int() {
		return _year;
	}
};


class Time {
	friend class DT;
	int _minute;
	int _second;
	int _hour;
public:
	Time(int x, int y, int z) :_hour(x), _minute(y), _second(z) {}
	friend ostream& operator<<(ostream& out, Time& t) {
		out << t._hour << ':' << t._minute << ':' << t._second << ':' << endl;
		return out;
	}
	friend istream& operator>>(istream& in, Time& t) {
		in >> t._hour >> t._minute >> t._second;
		return in;
	}
	operator int() {
		return _hour;
	}
};

class DT {
private:
	Date _d;
	Time _t;
public:
	DT(int x1 = 2000, int y1 = 1, int z1 = 1, int x2 = 12, int y2 = 0, int z2 = 0) :
		_d(x1, y1, z1), _t(x2, y2, z2) {}
	bool operator<(const DT& t) {
		if (_d._year != t._d._year) return _d._year < t._d._year;
		if (_d._month != t._d._month) return _d._month < t._d._month;
		if (_d._day != t._d._day) return _d._day < t._d._day;
		if (_t._hour != t._t._hour) return _t._hour < t._t._hour;
		if (_t._minute != t._t._minute) return _t._minute < t._t._minute;
		if (_t._second != t._t._second) return _t._second < t._t._second;
	}
	operator Date() {
		Date res(_d);
		return res;
	}
	operator Time() {
		Time res(_t);
		return res;
	}
	friend ostream& operator<<(ostream& out, DT& t) {
		out << t._d << t._t;
		return out;
	}
	friend istream& operator>>(istream& in, DT& t) {
		in >> t._d >> t._t;
		return in;
	}
};

int main()
{
	DT haoye;
	cin >> haoye;
	cout << haoye;

	DT dt1(2020, 11, 31, 12, 50, 34);
	DT dt2(2020, 11, 31, 12, 50, 12);
	if (dt1 < dt2)
		cout << "第一个日期时间小" << endl;
	else
		cout << "第一个日期时间不比第二个小" << endl;
	Date d = Date(dt1);
	Time t = Time(dt1);
	cout << dt1 << endl;
	cout << d << " ," << t << endl;
	int kk = d + t; //人类迷惑行为
	return 0;
}
