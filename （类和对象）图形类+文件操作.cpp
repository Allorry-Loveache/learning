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
