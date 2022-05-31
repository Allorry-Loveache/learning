#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
#include<cassert>
#include<cmath>
using namespace std;
#define pai 3.14

class shape {
public:

};

class rectangle :public shape {
private:
	int x, y;
public:
	rectangle(int a = 1, int b = 1) :x(a), y(b) {}
	double S() {
		return x * y;
	}
	void set(int xx, int yy) {
		x = xx, y = yy;
	}
	void out() {   //输入到文件里
		ofstream f("result.txt", ios::app);
		f << "矩形的长 宽 面积分别为：" << x << ' ' <<
			y << ' ' << S() << endl;
		f.close();
	}
	bool operator< (rectangle& x) {
		return S() < x.S();
	}
};

class triangle :public shape {
private:
	double x, y, z;
	double p;
	double s;
public:
	triangle(double a = 1, double b = 1, double c = 1) :x(a), y(b), z(c) {
		p = (x + y + z) / 2;
		assert(p >= x && p >= y && p >= z);
		s = sqrt(p * (p - x) * (p - y) * (p - z));
	}
	double S() {
		return s;
	}
	void set(double a, double b, double c) {
		x = a, y = b, z = c;
	}
	void out() {   //输入到文件里
		ofstream f("result.txt", ios::app);
		f << "三角形的三边 面积分别为：" << x << ' ' <<
			y << ' ' << z << ' ' << s << endl;
		f.close();
	}
	bool operator< (triangle& x) {
		return S() < x.S();
	}
};
class circle :public shape {
private:
	int r, x, y;
public:
	circle(int a = 1, int b = 1, int rr = 1) :x(a), y(b), r(rr) {}
	int getR() { return r; }
	double S() {
		return pai * r * r;
	}
	void set(int a, int b, int c) {
		x = a, y = b, r = c;
	}
	void out() {   //输入到文件里
		ofstream f("result.txt", ios::app);
		f << "圆的x y坐标 半径 面积分别为：" << x << ' ' <<
			y << ' ' << r << ' ' << S() << endl;
		f.close();
	}
	bool operator< (circle& x) {
		return S() < x.S();
	}
};

int main()
{
	vector<circle> c;
	vector<triangle> t;
	vector<rectangle> r;

	string a;
	ifstream f("shape.txt", ios::in);
	if (!f) exit(1);

	vector<int> v;
	while (getline(f, a)) {
		int d;
		istringstream s(a);
		while (s >> d) {
			v.push_back(d);
		}
		if (v.size() == 3) {
			c.push_back(circle(v[0], v[1], v[2]));
		}
		if (v.size() == 4) {
			int a = v[2] - v[0];
			int b = v[1] - v[3];
			r.push_back(rectangle(a, b));
		}
		if (v.size() == 6) {
			double a1 = v[0] - v[2], b1 = v[1] - v[3];
			double a2 = v[0] - v[4], b2 = v[1] - v[5];
			double a3 = v[2] - v[4], b3 = v[3] - v[5];
			t.push_back(triangle(sqrt(a1 * a1 + b1 * b1), sqrt(a2 * a2 + b2 * b2),
				sqrt(a3 * a3 + b3 * b3)));
		}
		v.clear();
	}
	f.close();
	sort(r.begin(), r.end());
	sort(t.begin(), t.end());
	sort(c.begin(), c.end());
	for (int i = 0; i < r.size(); i++)  r[i].out();
	for (int i = 0; i < t.size(); i++)  t[i].out();
	for (int i = 0; i < c.size(); i++)  c[i].out();
}








//另一种思路

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const double pi = acos(-1);
class shape {
public:
	virtual double area() = 0;
	virtual void disp(ofstream& fout) = 0;
};
class point {
private:
	double x, y;
public:
	point(double x, double y)
	{
		this->x = x;
		this->y = y;
	}
	double dist(const point& t)
	{
		return sqrt((x - t.x) * (x - t.x) + (y - t.y) * (y - t.y));
	}
	double getx()
	{
		return x;
	}
	double gety()
	{
		return y;
	}
};
class triangle :public shape {
private:
	point p1, p2, p3;
public:
	triangle(double x1, double y1, double x2, double y2, double x3, double y3) :p1(x1, y1), p2(x2, y2), p3(x3, y3)
	{

	}
	double area()
	{
		double p = (p1.dist(p2) + p2.dist(p3) + p3.dist(p1)) / 2;
		return sqrt(p * (p - p1.dist(p2)) * (p - p2.dist(p3)) * (p - p3.dist(p1)));
	}
	void disp(ofstream& fout)
	{
		fout << "triangle " << p1.getx() << " " << p1.gety() << " " << p2.getx() << " " << p2.gety() << " " << p3.getx() << " " << p3.gety() << endl;
	}
};
class circle :public shape {
private:
	point center;
	double radius;
public:
	circle(double x, double y, double r) :center(x, y), radius(r)
	{

	}
	double area()
	{
		return pi * radius * radius;
	}
	void disp(ofstream& fout)
	{
		fout << "circle " << center.getx() << " " << center.gety() << " " << radius << endl;
	}
};
class rectangle :public shape {
private:
	point p1, p2;
public:
	rectangle(double x1, double y1, double x2, double y2) :p1(x1, y1), p2(x2, y2)
	{

	}
	double area()
	{
		double len1 = p2.gety() - p1.gety();
		double len2 = p2.getx() - p1.getx();
		return len1 * len2;
	}
	void disp(ofstream& fout)
	{
		fout << "rectangle " << p1.getx() << " " << p1.gety() << " " << p2.getx() << " " << p2.gety() << endl;
	}
};
vector <shape*> vec;     //不允许使用抽象类的对象，但指针很有用
bool comp(shape* t1, shape* t2)
{
	return t1->area() < t2->area();
}
int main()
{
	ifstream fin("shape.txt");
	string str;
	while (getline(fin, str))
	{
		shape* now;
		stringstream sin(str);
		vector <double> vin;
		double x;
		while (sin >> x) vin.push_back(x);
		if (vin.size() == 3) now = new circle(vin[0], vin[1], vin[2]);
		if (vin.size() == 4) now = new rectangle(vin[0], vin[1], vin[2], vin[3]);
		if (vin.size() == 6) now = new triangle(vin[0], vin[1], vin[2], vin[3], vin[4], vin[5]);
		vec.push_back(now);
	}
	fin.close();
	sort(vec.begin(), vec.end(), comp);
	ofstream fout("result.txt");
	for (auto it = vec.begin(); it != vec.end(); it++)
		(*it)->disp(fout);
	fout.close();
	return 0;
}


