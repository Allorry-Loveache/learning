//给你俩长方体，看看有没有能够拼起来的两个面，组成一份新长方体，求体积表面积

#include<bits/stdc++.h>
using namespace std;
class haoye {
	int x, y, z;
public:
	haoye(int a = 1, int b = 1, int c = 1) :x(a), y(b), z(c) {}
	void surface() {
		cout << 2 * (x * y + y * z + z * x) << " ";
	}
	void volume() {
		cout << x * y * z << endl;
	}
	void judge(const haoye& t) {
		if (x == t.x && y == t.y) {
			z *= 2;
			surface();
			volume();
			z /= 2;
		}
		if (y == t.y && z == t.z) {
			x *= 2;
			surface();
			volume();
			x /= 2;
		}
		if (z == t.z && x == t.x) {
			y *= 2;
			surface();
			volume();
			y /= 2;
		}
	}
};
int main()
{
	haoye a(1, 2, 3), b(1, 2, 3);
	a.judge(b);
}
