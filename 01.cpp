#include<iostream>
#include<cmath>
#include<vector>
#include<assert.h>
using namespace std;
#define pai 3.14

class shape {
public:
	virtual void S() = 0;
};

class rectangle :public shape {
private:
	int x, y;
public:
	rectangle(int a, int b) :x(a), y(b) {}
	virtual void S() {
		cout << "rectanle:";
		cout << x * y << endl;
	}
	string type() {
		return "rectangle";
	}
};

class triangle :public shape {
private:
	int x, y, z;
	double p;
	double s;
public:
	triangle(int a, int b, int c) :x(a), y(b), z(c) {
		p = (x + y + z) / 2;
		assert(p >= x && p >= y && p >= z);
		s = sqrt(p * (p - x) * (p - y) * (p - z));
	}
	virtual void S() {
		cout << "triangle:";
		cout << s << endl;
	}
	string type() {
		return "triangel";
	}
};
class circle :public shape {
private:
	int r, x, y;
public:
	circle(int rr, int a, int b) :r(rr), x(a), y(b) {}
	int getR() { return r; }
	virtual void S() {
		cout << "circle:";
		cout << pai * r * r << endl;
	}
};

void area(shape& x) {
	x.S();
}

int main()
{
	/*rectangle r(2, 4);
	triangle t(3, 4, 5);
	circle c(5, 1, 1);
	area(r), area(t), area(c);*/

	//vector<shape*> vs;
	//vs.push_back(new circle(5,1,1));
	//vs.push_back(new rectangle(2,4));
	//vs.push_back(new triangle(3, 4, 5));
	//for (int i = 0; i < 3; i++) {
	//	area(*vs[i]);
	//}

	vector<shape*>vs;
	vs.push_back(new circle(5, 1, 1));
	vs.push_back(new rectangle(2, 4));
	vs.push_back(new triangle(3, 4, 5));

	circle* pc;
	triangle* ps;
	rectangle* pr;
	for (int i = 0; i < vs.size(); i++) {
		if (pc = dynamic_cast<circle*>(vs[i]))
			cout << pc->getR() << endl;
		else if (ps = dynamic_cast<triangle*>(vs[i]))
			cout << ps->type() << endl;
		else if (pr = dynamic_cast<rectangle*>(vs[i]))
			cout << pr->type() << endl;
	}
}


#include<bits/stdc++.h>
using namespace std;
class Savings {
protected:
	int money;
	string account;
public:
	Savings(int a, string b) :money(a), account(b) {}
	virtual void input(int x) = 0;
	virtual void output(int x) = 0;
};

class Checking :public Savings {

};
