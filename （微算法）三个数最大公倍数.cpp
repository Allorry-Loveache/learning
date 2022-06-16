#include<iostream>
using namespace std;
int gcd(int a, int b)
{
	int r;
	r = a % b;
	while (r != 0)
	{
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}
int main()
{
	int a, b, c;
	cin >> a >> b >> c; ;
	int ans = gcd(a, gcd(b, c));
	cout << "最大公约数为：" << ans << endl;
	cout << "最小公倍数：" << a * b / ans << endl;
	return 0;
}