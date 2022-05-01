#include"string.h"
int main()
{
	allorry::string a;
	cin >> a;
	cout << a << endl;
	a.resize(10, 65);
	cout << a << endl;
	a.reserve(20);
	a += "woqu";
	cout << a << endl;
	a.resize(5);
	cout << a << endl;
	a.append("lue");
	cout << a << endl;
}
